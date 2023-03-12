#ifndef MATH_H_
#define MATH_H_

int Factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * Factorial(n - 1);
}

#endif
