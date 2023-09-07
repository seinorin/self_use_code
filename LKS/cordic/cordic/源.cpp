#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define u32 int
#define pi 3.1415926
#define KEY 0.607252935103140
#define middle 10000


#define flagup1 340000
#define flagup2 350000
#define flagdw1 20000
#define flagdw2 10000


//tanθ = 2^(-i)时对应的θ值
//static u32 _angle[15]={ 26.5650511770780,14.0362434679265,7.12501634890180,
//						3.57633437499735,1.78991060824607,0.895173710211074,0.447614170860553,
//						0.223810500368538,0.111905677066207,0.0559528918938037,0.0279764526170037,
//						0.0139882271422650,0.00699411367535292,0.00349705685070401,0.00174852842698045};

#define u16 int 
static int _angle[16] = {
						26565,14036,7125,3576,
						1789,895,447,223,
						111,55,27,13,
						6,3,1,0};

u32 getangle(u32 cosx, u32 sinx);
u32 getrightangle(u32 num1, u32 num2, u32 pole);//这里的flag记录的是多少个周期
int main()
{
	u32 num1 = 0,num2=0;
	int sinx, cosx;
	int i = 3;
	u32 pole = 0;
	u32 out = 0;
	for (int i = 0; i < 32; i++)
	{
		sinx =int( 10000*sin(double(i) / 16 * pi))+10000;
		cosx =int( 10000*cos(double(i) / 16* pi))+10000;
		num1 = getangle(cosx,sinx);
		pole = getrightangle(num1, num2, pole);

		printf("%d   %d    %d\n", pole*1000+num1,cosx,sinx);
		num2 = num1;

	}
	
	system("pause");
	return 0;
}



u32 getrightangle(u32 num1, u32 num2, u32 pole)
{
	int key;
	if ((num2 - num1) > 180)
		key = pole + 1;
	else if ((num2 - num1) < (-180))
		key = pole - 1;
	else
		key = pole;
	return key;
}



u32 getangle(int cosx, int sinx)
{
	//进入计时器。
	//将角度更换至0-pi/4
	int flag = 0, i = 0;
	int data = 0;
	int _x, _y;
	u32 z = 0;
	int _x1, _y1;
	if (1)
	{
		sinx -= middle;
		cosx -= middle;
	}
	if (sinx < 0)
	{
		flag |= 0x04;
		sinx = -sinx;
	}
	if (cosx < 0)
	{
		flag |= 0x02;
		cosx = -cosx;
	}
	if (cosx < sinx)
	{
		flag |= 0x01;
		data = cosx;
		cosx = sinx;
		sinx = data;
	}
	_x = cosx; _y = sinx;
	for (; i < 15; i++)
	{
		_x1 = _y >> (i + 1);
		_y1 = _x >> (i + 1);
		if (_y > 0)
		{
			_x += _x1;
			_y -= _y1;
			z += _angle[i];
		}
		else
		{
			_x -= _x1;
			_y += _y1;
			z -= _angle[i];
		}
	}
	switch (flag)
	{
	case 0:
		break;
	case 1:
		z = 90000 - z; break;
	case 2:
		z = 180000 - z; break;
	case 3:
		z = 90000 + z; break;
	case 4:
		z = 360000 - z; break;
	case 5:
		z += 270000; break;
	case 6:
		z += 180000; break;
	case 7:
		z = 270000-z; break;
	}
	return z;
}