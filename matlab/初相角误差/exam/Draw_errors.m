clear all;
close all;
t=[0:15:360]
a=load('��դ.txt');
b=load('ʱդ.txt');
c=load('�������.txt');

x=a; 
y=b;
z=c;
 
figure;
plot(t,x,'r-s');
hold on;
plot(t, y, 'b.-');
plot(t,x,'b-s');
hold on;
plot(t, z, 'b.-');


xlabel('Sampling point[0��,360��]');
ylabel('Errors(��)');
hold on;

%hold off;