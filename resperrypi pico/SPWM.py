from machine import Pin,PWM,Timer
import time
from math import sin
i=0
s=1
num=[0,180,716,1604,2833,
     4390,6258,8417,10842,13507,
     16384,19440,22642,25955,29342,
     32767,36193,39580,42893,46095,
     49151,52028,54693,57118,59277,
     61145,62702,63931,64819,65000,
     65530,65535]
pwm=PWM(Pin(15))
pwm.freq(64000)
def twinkle(tim):
    global i,s
    if i==31:
        s=-1
    if i==0:
        s=1
    pwm.duty_u16(num[i])
    i+=s
if __name__ == '__main__':
    # 构建定时器
    tim = Timer()
    # tim.init(period, mode, callback)
    # period:周期时间(单位为ms)
    # mode:工作模式，有Timer.ONE_SHOT(执行一次)和Timer.PERIODIC(周期性执行)两种
    # callback:定时器中断的回调函数
    tim.init(freq=64000, mode=Timer.PERIODIC, callback=twinkle)