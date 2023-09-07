function out=onef(fint,num)
%取一个周期信号
%fint为输入
%num为一个周期的采样点数
%主函数的版本fint为out
% outnum=fint(200000:500001);
% outnum=outnum-min(outnum);
% outnum=(outnum/max(outnum)-0.5)*2;
% for i=1:1:300002
%     if outnum(i)>=0
%         fin=outnum(i:i+49999);
%         break
%     end
% end


%   取一个周期的数据

     int=fint(num:length(fint));
    int=int-min(int);
    int=int/max(int)-0.5;
    for i=1:1:length(int)
        if int(i)>=0
            out=int(i:i+num-1);
         break;
        end
    end
    out=out*2;
end

