clear all;
close all;
t=[0:15:360]
a=load('π‚’§.txt');
b=load(' ±’§.txt');
c=load('≤‚¡øŒÛ≤Ó.txt');

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


xlabel('Sampling point[0°„,360°„]');
ylabel('Errors(°„)');
hold on;

%hold off;