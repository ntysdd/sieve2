#include <iostream>
#include <vector>

bool isPrime(long long n) {
  if (n <= 2) {
    return n == 2;
  }

  if (n % 2 == 0) {
    return false;
  }

  long long i = 3;
  while (true) {
    if (i * i > n) {
      return true;
    }
    if (n % i == 0) {
      return false;
    }
    i += 2;
  }
}

double f1(int n, std::vector<bool> const &vec) {
  int count = 0;
  for (int i = 1; i < n; i++) {
    if (vec.at(i) && vec.at(n - i)) {
      // both i and n-i are primes
      count++;
    }
  }
  return count;
}

int main() {
  // make sure n is even
  int n = 69900434; // rand(10 ** 8)

  // primes bit map
  std::vector<bool> vec(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (isPrime(i)) {
      vec.at(i) = true;
    }
  }

  std::vector<int> nums;
  for (int i = 2; i <= n-2; i++) {
    nums.push_back(i);
  }

  long double estimate = n-3;

  for (int i = 1; i * i <= n; i++) {
    if (!vec.at(i)) {
      continue;
    }

    int p = i; // p is prime

    std::vector<int> new_nums;

    for (int x : nums) {
      if (x % p == 0) {
        // if x is multiple of p filter out
        continue;
      }

      if ((n - x) % p == 0) {
        // if n-x is multiple of p filter out
        continue;
      }

      new_nums.push_back(x);
    }

    nums = new_nums;

    if (n % p == 0) {
      estimate *= 1 - (long double)1 / p;
    } else {
      estimate *= 1 - (long double)2 / p;
    }

    double diff = nums.size() - estimate;

    std::cout << "filter " << p << ": " << nums.size() << " " << estimate
              << " diff=" << diff << "\n";

    // use this for estimating next round
    estimate = nums.size();
  }

  double number_of_solutions = f1(n, vec);

  std::cout << "number_of_solutions=" << number_of_solutions << "\n";
}
