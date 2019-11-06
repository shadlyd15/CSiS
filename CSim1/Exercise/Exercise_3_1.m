% Exercise 3.2

R = 5;
x = x0 = prev_x = 0;
tolerance = 0.000001;
number_of_iterations = 1000;

for i = 1 : number_of_iterations
  f = exp(x) - R;
  df = exp(x);
  x = x - f/df;
  error = abs(x - prev_x);
  prev_x = x;
  if ( error < tolerance)
      break;
  end
end

disp(['x = ' num2str(x)])
