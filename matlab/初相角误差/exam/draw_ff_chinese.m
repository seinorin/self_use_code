function y=napssz_outsort(ms,ns)%%msΪ����Ƶ�Σ�
ms=15;
% clear all;
fid=fopen('�ǶȲ������.txt');%ֻ������ʽ���ļ�
R=fscanf(fid,'%f',inf);%��ȡ�ļ��е�����Ԫ��
fclose(fid);%�ر��ļ�
m=length(R);
% z=R(1:m-1);%�޳�������������һ������
z=R(1:m);%�޳�������������һ������
n=length(z);
z1=fft(z,n);%fft�任
A=2*abs(z1)/n;%��ģ(��������)
A(1)=(z1(1))/n;%ֱ������
% P=angle(z1)+pi/2;%����λ
P=angle(z1);%����λ
for i=1:(n/2)
    O(i)=i;
end  
O=O';
for k=2:(n/2+1)
    BA(k-1)=A(k);
    BP(k-1)=P(k);
end
BA=BA';
BP=BP';
B=[BA BP O];
% B=-sortrows(-B);%��1���Ժ����ֵ���н�������
% AP=[A(1) P(1) 0 ;B;];%������A��P����
% for j=1:(n/2+1)
%    NapOut(j,1)=AP(j,3);
%    NapOut(j,2)=AP(j,1);
%    NapOut(j,3)=AP(j,2);
% end

AP=[A(1) P(1) 0 ;B;];%δ������A��P����
for j=1:(n/2+1)
   NapOut(j,1)=AP(j,3);
   NapOut(j,2)=AP(j,1);
   NapOut(j,3)=AP(j,2);
end

fid=fopen('����Ҷ�任���.txt','wt');
for i=1:ms
%     fprintf(fid,'c%d[%d]=%d;\t\ta%d[%d]=%f;\t\tb%d[%d]=%f\n',ns,i-1,NapOut(i,1),ns,i-1,NapOut(i,2),ns,i-1,NapOut(i,3));
    fprintf(fid,'%d\t%f\t%f\n',NapOut(i,1),NapOut(i,2),NapOut(i,3));
end
fclose(fid);%�ر��ļ�

%data=load('fitssz_outsort.txt');
%x=data(:,1);
%y=data(:,2);
%stem(x,y);
t=[0:1:14]%t=[0:1/fs:N/fs]; %����ʱ��
X=load('����Ҷ�任���.txt');
S=X(:,2); %�ź�
stem(t,S);

set(gcf,'unit','centimeters','position',[0 0 12 6.5]);%��λΪ���ף���СΪ16cm��6.5cm��ͼ���������Ϊ��0cm��0cm����ʾ���µ�����ʾ�����߽�0cm�����²�߽�0cm��
xlabel('г��Ƶ��');
ylabel('��ֵ[��]');
set(gca,'FontName','Times New Roman','FontSize',12)%���������������С������
xlabel('г��Ƶ��','Fontname', 'Times New Roman','FontSize',12);
ylabel('��ֵ[��]','Fontname', 'Times New Roman','FontSize',12);
%title('The harmonic order(Hz)');
grid on;