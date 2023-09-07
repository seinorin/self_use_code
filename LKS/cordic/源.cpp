#include <stdio.h>
#include <stdlib.h>

#define u32 double
#define DEPTH      16            //最大赋值为16
#define DEP_SHIFT (DEPTH-1)      //tan数组中的标幺值移位
#define KEY 0.607252935103140
static u32 _tan[15] = { 0.500000000000000,0.250000000000000,0.125000000000000,
						0.0625000000000000,0.0312500000000000,0.0156250000000000,0.00781250000000000,
						0.00390625000000000,0.00195312500000000,0.000976562500000000,0.000488281250000000,
						0.000244140625000000,0.000122070312500000,6.10351562500000e-05,3.05175781250000e-05 };

//tanθ = 2^(-i)时对应的θ值
static u32 _angle[15]={ 26.5650511770780,14.0362434679265,7.12501634890180,
						3.57633437499735,1.78991060824607,0.895173710211074,0.447614170860553,
						0.223810500368538,0.111905677066207,0.0559528918938037,0.0279764526170037,
						0.0139882271422650,0.00699411367535292,0.00349705685070401,0.00174852842698045};



u32 getangle(u32 cosx, u32 sinx);

int main()
{
	u32 num = 0;
	num = getangle(-0.94*2, -0.342*2);
	printf("%f", num);
	system("pause");
	return 0;
}


u32 getangle(u32 cosx, u32 sinx)
{
	//进入计时器。
	//将角度更换至0-pi/4
	char flag = 0;
	u32 data = 0;
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
	char d = 1;
	u32 _x = cosx, _y = sinx, z = 0;
	u32 _x1, _y1;
	for (int i = 0; i < 15; i++)
	{
		_x1 = _y * _tan[i];
		_y1=_x*_tan[i];
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
	switch(flag)
	{
	case 0:
			break;
	case 1:
		z += 45; break;
	case 2:
		z += 135; break;
	case 3:
		z += 90; break;
	case 4:
		z += 315; break;
	case 5:
		z += 270; break;
	case 6:
		z += 180; break;
	case 7:
		z += 225; break;
	}
	return z;
}