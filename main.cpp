#include <iostream>
#include <vector>

bool isPrime(long long n)
{
    if (n <= 2)
    {
        return n == 2;
    }

    if (n % 2 == 0)
    {
        return false;
    }

    long long i = 3;
    while (true)
    {
        if (i * i > n)
        {
            return true;
        }
        if (n % i == 0)
        {
            return false;
        }
        i += 2;
    }
}

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        if (isPrime(i))
        {
            std::cout << i << "\n";
        }
    }
}
