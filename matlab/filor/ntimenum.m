function [t,out] = ntimenum(fint)
%取所有完整周期数据
int=fint;
key0=1;key1=1;
    for i=2:1:length(int)
        if (int(i)>=int(1)&&int(i-1)<=int(1))||(int(i)<=int(1)&&int(i-1)>=int(1))
            key0=i;
        end
        if (key0-key1)>1000%根据周期采样点数适当调整
            key1=key0;
        end
    end
int=smooth(int,60);
if (int(1)>int(3))==(int(key0)>int(key0+3))
    out=fint(1:key0);
else
    out=fint(1:key1);
end
t=timenumget(out)/length(out):timenumget(out)/length(out):timenumget(out);
t=t'/2;
end
