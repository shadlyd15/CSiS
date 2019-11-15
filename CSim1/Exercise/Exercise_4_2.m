# Format Long
f=@(x)sqrt(4-x^2)
f1=@(x)(log(1+x)/x)
a=0; %limits of the second integeral question
b=2;
a1=0.001;%limits of the first integeral question
b2=1
n=5000;
h=(b-a)/n; %calculating step size for first integral
h1=(b2-a1)/n; %calculating step size for second integral
s=zeros(5005,1);  %creating a matrix to store
s1=zeros(5005,1);
s2=zeros(5005,1);
s3=zeros(5005,1);
r_error1=zeros(n,1);
r_value1=(pi*pi)/12;
r_error2=zeros(n,1);
r_value2=pi;
r_error3=zeros(n,1);
r_error4=zeros(n,1);
for i= 1:n
	if i==0 || i==n
    	p=1;
	elseif mod(i,2) ~= 0
	  p=4;
	else
	  p=2;
  end
   x=(a+i*h);
   x2=real(a1+i*h1)
   s(i+1,1)=(s(i,1)+p*f(x));
   s1(i+1,1)=real(s1(i,1)+p*f1(x2));

SimpI(i,1)=real(h/3*s(i,1));
SimpI2(i,1)=real(h1/3*s1(i,1));
r_error1(i,1)= r_value2-SimpI(i,1) %calculating relative error for 1st integral question
r_error2(i,1)=r_value1-SimpI2(i,1) %calculating relative error for 2nd integral question


if (r_error1(i,1)<= 10^-8)  %To find out in which iteration we can find the relative error upto 10^-8
disp(i)  
end
title('Log Log plot for the error approximation using simpsons rule')
ylabel('error')
xlabel('step size')
loglog(1:n,r_error1)
hold on
end
