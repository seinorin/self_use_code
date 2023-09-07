from machine import Pin,Timer,UART,PWM
from rp2 import PIO,asm_pio #状态机库
import time,_thread,rp2


#串口调试
uart0 = UART(0, baudrate=115200, tx=Pin(0), rx=Pin(1))

#状态机设置
#获取脉冲值
@asm_pio()
def direction():
    wrap_target()
    #有脉冲到来时判断方向
    wait(1,gpio,2)
    jmp(pin,"x")
    #y方向
    jmp(y_dec,"goon")
    mov(y,osr)
    jmp("goon")
    #x方向
    label("x")
    jmp(x_dec,"goon")
    mov(x,osr)
    jmp("goon")
    #一个脉冲结束
    label("goon")
    wait(0,gpio,2)
    wrap()
    
sm0 = rp2.StateMachine(0,direction,freq=125000000,jmp_pin=Pin(3),push_thresh=20)
max_count=36000*25#似乎是25分频？
sm0.put(max_count)
sm0.exec("pull()")
sm0.exec("mov(x,osr)")
sm0.exec("mov(y,osr)")
sm0.active(1)

#模拟脉冲输入
@asm_pio(set_init=(rp2.PIO.OUT_LOW,rp2.PIO.OUT_LOW))
def blink():
    wrap_target()
    set(pins,0x0)[31]
    set(pins,0x1)[31]
    set(pins,0x3)[31]
    set(pins,0x2)[31]
    wrap()
sm1 = rp2.StateMachine(1, #第0号状态机，Pico总共有8个状态机，编号0到7
                      blink,#状态机运行程序
                      freq=2000, # 状态机运行频率
                      in_base=None,#用于in指令
                      out_base=None,#用于out指令
                      set_base=Pin(4), # 起始针脚是GP25，对应于Pico板载的LED灯
                      jmp_pin=None,#jmp指令
                      sideset_base=None,#用于侧置指令
                      in_shiftdir=None,#ISR移动方向
                      out_shiftdir=None,#CSR移动方向
                      pull_thresh=None#拉取阈值
                      )
sm1.active(1)


def twinkle(tim):
    sm0.exec("in_(x,22)")
    sm0.exec("push(block)")
    x_dec=sm0.get()
    sm0.exec("in_(y,22)")
    sm0.exec("push(block)")
    y_dec=sm0.get()
    oga=((y_dec & 0xfffff)-(x_dec & 0xfffff))/2500
    if (oga < 0):
        oga=360+oga
    print('this time OGAdata = ',oga)
    uart0.write(str(oga))


if __name__ == '__main__':    
    # 构建定时器
    tim = Timer()
    # tim.init(period, mode, callback)
    # period:周期时间(单位为ms)
    # mode:工作模式，有Timer.ONE_SHOT(执行一次)和Timer.PERIODIC(周期性执行)两种
    # callback:定时器中断的回调函数
    tim.init(freq=1, mode=Timer.PERIODIC, callback=twinkle)