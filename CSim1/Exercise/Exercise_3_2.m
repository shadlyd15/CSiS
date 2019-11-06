%Exercise 3.2

B = 0.17;
f = @(m)[tanh(6*B*m)]-m;

m1 = 4.00;
m2 = 3.50;

tolerance = 0.0000001;
max_iterations = 1000;
erros(1) = 0;

for i= 1:max_iterations
	m3 = m2-(f(m1)*(m1-m2))/(f(m1)-f(m2));
	m1 = m2;
	m2 = m3;  
	error = abs(m1 - m2);
  errors(i) = error;
 	  
	if error < tolerance;
    	break;
	end
end
disp(['Root = ' num2str(m3)])