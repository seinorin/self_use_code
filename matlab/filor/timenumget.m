function t=timenumget(fint)
%获取共多少个周期
    flag=0;t=0;e=0;
    int=smooth(fint,60);
    for i=10:10:length(int)
        if flag==0 && int(i) >int(i-9)
            t=t+1;
            flag=1;
        elseif flag==1 && int(i) < int(i-9)
              flag=0;  
              e=e+1;
        end
    end
    t=min([t,e]);
end