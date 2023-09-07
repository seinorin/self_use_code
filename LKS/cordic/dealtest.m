function key = dealtest(num1,num2,pole)
%DEAL 此处显示有关此函数的摘要
%   此处显示详细说明
    if (num2-num1) > 180
        key=pole+1;
    elseif (num2-num1) < (-180)
        key=pole-1;
    else
        key=pole;
    end

