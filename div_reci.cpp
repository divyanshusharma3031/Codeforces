#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

map<long long int, int> is_prime;
vector<int> primes;
map<long long int, vector<long long int>> divisor_sum;

void prime_sieve()
{

    for (long long int i = 0; i <= 1000000; i++)
    {
        is_prime[i] = 0;
    }

    is_prime[2] = 1;
    for (long long int i = 3; i <= 1000000; i = i + 2)
    {
        is_prime[i] = 1;
    }

    for (long long int i = 3; i <= 1000000; i = i + 2)
    {
        if (is_prime[i])
        {
            for (long long int j = ((long long int)i * (long long int)i); j <= 1000000; j = j + i)
            {
                is_prime[j] = 0;
            }
        }
    }

    for (long long int i = 1; i <= 1000000; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}

long long int sum_of_divisors(long long int number)
{

    long long int sum_of_divisors = 1;

    for (long long int i = 0; (primes[i] * primes[i]) <= number; i++)
    {
        long long int factor = primes[i];
        long long int exponent = 0;

        if (number % factor == 0)
        {
            while (number % factor == 0)
            {
                number = number / factor;
                exponent++;
            }

            long long int place_value = 1;
            long long int sum_of_gp = 0;
            for (long long int i = 0; i <= exponent; i++)
            {
                sum_of_gp = sum_of_gp + place_value;
                place_value = place_value * factor;
            }
            sum_of_divisors = sum_of_divisors * (sum_of_gp);
        }
    }

    if (number != 1)
    {
        sum_of_divisors = sum_of_divisors * (number + 1);
    }

    return sum_of_divisors;
}

void divisor_sum_precomputation()
{
    divisor_sum[1].push_back(1);
    for (long long int i = 2; i <= 1000000; i++)
    {
        long long int sum = sum_of_divisors(i);
        divisor_sum[sum].push_back(i);
    }
}

pair<long long int, long long int> calc_numerator_denominator(long long int number)
{
    long long int numerator = 1;
    long long int denominator = 1;
    for (long long int i = 0; (primes[i] * primes[i]) <= number; i++)
    {
        long long int factor = primes[i];
        long long int exponent = 0;

        if (number % factor == 0)
        {
            while (number % factor == 0)
            {
                number = number / factor;
                exponent++;
            }

            numerator *= (pow(factor, exponent + 1) - 1);
            denominator *= (pow(factor, exponent + 1) - pow(factor, exponent));
        }
        // cout<<numerator<<" "<<denominator<<"\n";
    }
    return make_pair(numerator, denominator);
}

int main()
{

    prime_sieve();
    divisor_sum_precomputation();

    int number_of_test_cases;
    cin >> number_of_test_cases;

    for (int i = 0; i < number_of_test_cases; i++)
    {
        int sum;
        cin >> sum;

        int numerator;
        cin >> numerator;
        int denominator;
        cin >> denominator;

        if (divisor_sum.count(sum) == 0)
        {
            cout << -1;
        }
        else
        {
            bool flag = 1;
            for (auto x : divisor_sum[sum])
            {
                pair<long long int, long long int> result = calc_numerator_denominator(x);
                // cout << result.first <<" "<< result.second << endl;
                if ((numerator == result.first) && (denominator == result.second))
                {
                    cout << x << endl;
                    break;
                }
            }
            cout << -1 << endl;
        }
    }
}