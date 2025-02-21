#include <iomanip>
#include <iostream>
#include <math.h>
#include <vector>

long double f1(long long x, const std::vector<bool> &vec) {
  long long sqr = sqrtl(x);
  long long count = 0;
  for (long long i = sqr + 1; i < x / 2; i++) {
    if (vec.at(i) && vec.at(x - i)) {
      count++;
    }
  }

  count *= 2;

  if (vec.at(x / 2)) {
    count++;
  }

  return count;
}

long double f2(long long x, const std::vector<bool> &vec) {
  long long sqr = sqrtl(x);
  long double est = x - 3;

  for (long long i = 2; i <= sqr; i++) {
    if (vec.at(i)) {
      long double d = 2;
      if (x % i == 0) {
        d = 1;
      }
      est *= 1 - d / i;
    }
  }

  return est;
}

long double g1(long long x, const std::vector<bool> &vec) {
  long long count = 0;
  for (long long i = 1; i <= x; i++) {
    if (vec.at(i)) {
      count++;
    }
  }
  return count;
}

long double g2(long long x, const std::vector<bool> &vec) {
  long long sqr = sqrtl(x);
  long double est = x - 1;

  for (long long i = 2; i <= sqr; i++) {
    if (vec.at(i)) {
      long double d = 1;
      est *= 1 - d / i;
    }
  }

  return est;
}

int main() {
  long long from = 100000000;
  long long to = from + 1000;

  std::vector<bool> vec(to + 1, true);
  vec.at(0) = false;
  vec.at(1) = false;

  for (long long i = 2; i * i <= to; i++) {
    if (!vec.at(i)) {
      continue;
    }
    for (long long j = i * i; j <= to; j += i) {
      vec.at(j) = false;
    }
  }

  std::cout.precision(4);
  std::cout << std::fixed;

  for (long long i = from; i <= to; i += 2) {
    long double count = f1(i, vec);
    long double est = f2(i, vec);

    long double count2 = g1(i, vec);
    long double est2 = g2(i, vec);

    long double rel_err = count / est - 1;
    long double rel_err2 = count2 / est2 - 1;

    rel_err *= 100;
    rel_err2 *= 100;

    long double ratio = rel_err / rel_err2;

    std::cout << i << " " << rel_err << "% " << rel_err2 << "% ratio=" << ratio
              << "\n";
  }
}
