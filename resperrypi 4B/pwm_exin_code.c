#include <wiringPi.h>
#include <stdio.h>

//多线程头文件
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringSerial.h>//UARTinit


int fd;
int cmd;




//存时间数据
int interruptdata;
int excitationdata;
struct timespec tss;
struct timespec ts ;


#define range_value 270  //每个周期内细分度设置
			    //54mhz,2000hz 50个点delay10,180等分range
#define Clock_value 2//设置分频，pwm的工作时钟== 19.2M/Clock_value，4b似乎默认为100M,wiringpi使用54m
			//默认情况下 Clock_value为32，即600Khz
#define pwm_pin0 1	//wpi引脚为1,26和24,23，对应12,32和35,33
#define pwm_pin1 23
//pwm_value/range_value 为占空比
int pwm_value[]={
	0,2,8,18,31,48,
	68,91,116,144,173,
	203,234,266,297,327,
	356,384,409,432,452,
	469,482,492,498,500};            
extern int excitationdata;//output data time get
extern struct timespec tss ;
//pwm激励生成线程，仅两路。
PI_THREAD (pwm_range_change)
{
    int i=0,j=12;
    int flag=1,flagg=1;
    while(1)
    {
		clock_gettime (CLOCK_MONOTONIC_RAW, &tss) ;
		//excitationdata = tss.tv_nsec;
		if(i==25){flag=-1;excitationdata = tss.tv_nsec;}
		else if(i==0){flag=1;}
		if(j==25){flagg=-1;}
		else if(j==0){flagg=1;}
		pwmWrite(pwm_pin0,pwm_value[i]/2);
		pwmWrite(pwm_pin1,pwm_value[j]/2);
		//pwmWrite(pwm_pin0,135);
		i=i+flag;
		j=j+flagg;
		delayMicroseconds(10);
		}
    }



//外部中断
#define  btn_pin 4 // 按钮引脚
extern int interruptdata;//input data time get
extern struct timespec ts ;
void blank(void)
{
	clock_gettime (CLOCK_MONOTONIC_RAW, &ts) ;
    interruptdata = ts.tv_nsec;
}


int main()
{
	int count=0;
	if(wiringPiSetup()<0)//初始化wiringpi库
		return 1;
		
		
	fd=serialOpen("/dev/ttyAMA0",115200);	
		
		
	
	pinMode(pwm_pin0,PWM_OUTPUT);//输出使能
	pinMode(pwm_pin1,PWM_OUTPUT);//输出使能
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(range_value);	
	pwmSetClock(Clock_value);   
	//pwm初始化
	
	
	pinMode(btn_pin, INPUT);
    pullUpDnControl (btn_pin, PUD_UP); // 这个很重要，把中断引脚设置成上拉输入，
    delay(100);
    wiringPiISR(btn_pin,INT_EDGE_FALLING,&blank);
	//外部中断初始化
	
	
	piThreadCreate(pwm_range_change);//启动pwm线程
	while(1)
	{/*
		if(serialDataAvail(fd) != -1)
		{
			cmd=serialGetchar(fd);
			printf("%d/n",cmd);
			}
		count++;
		delay(100);
		if(count==100)break;*/
		}
	serialClose(fd);
	return 0;
}
