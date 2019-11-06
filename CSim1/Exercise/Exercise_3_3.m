% Exercise 3.3

h = 0.01;
i = sqrt(-1);
z1 = [1,1];
for n = 1:401
	for m = 1:401;
	z1(n,m) = (m-201)*h + i*(n-201)*h;  
	end
end

z = prev_z = z1;
tolerance = 0.0000001;
number_of_iterations = 100;

for j = 1 : number_of_iterations
  f = z.^3 - 1;
  df = 3*z.^2;
  z = z - f./df;
  error = abs(z - prev_z);
  prev_z = z;
  if ( error < tolerance)
      break;
  end
end
 
A = zeros(n,m);
for n = 1:401
  for m = 1:401
      if z(n,m) == 1;
          A(n,m) = 1;
      end
  end
end

imagesc(A)
colorbar