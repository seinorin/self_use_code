pole_number=30;
frequen = 2000;
system_clk = 250000000;
one_pulse_angle=360000000*frequen/pole_number/system_clk/4;
//将获取的时间值处理为角度信息
int tga_angel_time_get(int extime,int intime)
{
	int outtime=0,angle=0;
	outtime = intime - extime;
	angle = one_pulse_angle * outtime;
	return angle;
}

double tga_angel_data_get(int now_pole,int now_angle)
{
	double out_angle=0;
	out_angle = now_pole *360/pole_number + now_angle/1000000;
	return out_angle;
}