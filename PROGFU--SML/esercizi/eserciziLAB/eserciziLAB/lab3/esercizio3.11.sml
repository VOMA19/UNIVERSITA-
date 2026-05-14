fun power (x, 0) = 1
  | power (x, i) = x * power(x, i - 1);