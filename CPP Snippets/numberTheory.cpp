#include <bits/stdc++.h>
using namespace std;

//******************* Prime **************************
//================== marking sieve =======================
#define M 10000007
bool notPrime[M];
void markingNotPrimes()
{
    notPrime[0] = true;
    notPrime[1] = true;

    for (int i = 4; i < M; i += 2)
    {
        notPrime[i] = true;
    }

    int i;
    for (i = 3; i * i < M; i += 2)
    {
        if (!notPrime[i])
        {
            for (int j = i * i;
                 j < M;
                 j += (i + i))
            {
                notPrime[j] = true;
            }
        }
    }
}
//=================== get prime list sieve =====================
#define M 10000007
bool notPrime[M];
vector<int> primes;

void initializePrimes()
{
    notPrime[0] = true;
    notPrime[1] = true;

    primes.push_back(2);

    for (int i = 4; i < M; i += 2)
    {
        notPrime[i] = true;
    }

    int i;
    for (i = 3; i * i < M; i += 2)
    {
        if (!notPrime[i])
        {
            for (int j = i * i; j < M; j += (i + i))
            {
                notPrime[j] = true;
            }
            primes.push_back(i);
        }
    }
    for (; i < M; i += 2)
    {
        if (!notPrime[i])
        {
            primes.push_back(i);
        }
    }
}

//==================== get prime factorization ===================
#define M 10000007
int spf[M];
vector<int> factors; // use set for distinct factors

void sieve()
{

    spf[1] = 1;

    for (int i = 2; i < M; i++)
    {
        spf[i] = i;
    }
    for (int i = 4; i < M; i += 2)
    {
        spf[i] = 2;
    }
    int i;
    for (i = 3; i * i < M; i += 2)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < M; j += (i + i))
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void getFactors(int x)
{
    while (x != 1)
    {
        factors.push_back(spf[x]);
        x = x / spf[x];
    }
}
//============ sieve with linear time complexity =========
// Time Complexity: O(n)
/*
    spf[i] = 0 means i is prime number, there is no other prime factor
*/
#define N 10000007
int spf[N + 1];     // smallest prime factors
vector<int> primes; // to speeds up the process replace vector with array

void initializePrimes()
{
    for (int i = 2; i <= N; ++i)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size() && primes[j] <= spf[i] && i * primes[j] <= N; ++j)
            spf[i * primes[j]] = primes[j];
    }
}

//=================== primality check ===================
//!single occurance
bool isPrime(long long n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;

    for (long long i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}
//====================Count Primes========================
//!single occurance
// Total number of primes less than or equals n
int primeCount(int n)
{
    int x = n / floor(log(n));
    return x;
}

//****************** Golbachs Conjecture ****************
// For n >= 4 there exist n = p1 + p2 where p1,p2 ar primes
/* 
For n <= 2^15 = 32768 the goldbach function 
Finds the number of different pairs (p1, p2), 
For which n = p1 + p2. As p1 <= p2 and p1 <= n/2.
*/
#define M 10000007
bool notPrime[M];
void markingNotPrimes()
{
    notPrime[0] = true;
    notPrime[1] = true;

    for (int i = 4; i < M; i += 2)
    {
        notPrime[i] = true;
    }

    int i;
    for (i = 3; i * i < M; i += 2)
    {
        if (!notPrime[i])
        {
            for (int j = i * i;
                 j < M;
                 j += (i + i))
            {
                notPrime[j] = true;
            }
        }
    }
}
int goldbach(int n)
{
    int i, res = 0;
    for (i = 2; i <= n / 2; i++)
        if (!notPrime[i] && !notPrime[n - i])
            res++;
    return res;
}
//******************* Co-primes *************************
// Time Complexity: O(√n)
/*
if n = p1^q1*p2^q2*...pk^qk
number of Co-primes to n (less than n),
 ϕ(n) = n*(1-1/p1)(1-1/p2)...(1-1/pk)
*/
int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
//******************* Divisors **************************
//========= number of divisors and the divisors ===========
//!single occurance
vector<int> divs;
int divisorCount(long n)
{
    int count = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
            {
                divs.push_back(i);
                count++;
            }
            else
            {
                divs.push_back(i);
                divs.push_back(n / i);
                count += 2;
            }
        }
    }
    return count;
}
//==================== all divisors =========================
// Time Complexity : O(n logn)
vector<int> divisors[10000002];

void initializeDivisors(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}
//=============== number of divisors ========================
/*
    if a prime factorization of a number N is,
    N = p1^q1 x p2^q2 x p3^q3 x . . . x pk^qk
    then number of divisors,
    d(N) = (q1+1) x (q2+1) x (q3+1) x . . . x (qk+1)
    example : 48 = 2^4 x 3^1, so d(N) = (4+1)(1+1) = 10
    src: https://cp-algorithms.com/algebra/divisors.html

    It's a multiplicative function.
    So, d(ab) = d(a)xd(b)
*/
#define M 10000007
bool flag[M];
int primes[M];

int sieve()
{
    int i, j, total = 0, val;

    for (i = 2; i <= M; i++)
        flag[i] = 1;

    for (i = 2; i * i <= M; i++)
        if (flag[i])
            for (j = i; j * i <= M; j++)
                flag[i * j] = 0;

    for (i = 2; i <= M; i++)
        if (flag[i])
            primes[total++] = i;

    return total;
}

int divisorCount(int n)
{
    int i, val, count, sum;

    val = sqrt(n) + 1;
    sum = 1;
    for (i = 0; primes[i] < val; i++)
    {
        if (n % primes[i] == 0)
        {
            count = 0;
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                count++;
            }
            sum *= (count + 1);
        }
    }
    if (n > 1)
        sum = sum * 2;
    return sum;
}
//================== sum of divisors ======================
/*if a prime factorization of a number N is,
    N = p1^q1 x p2^q2 x p3^q3 x . . . x pk^qk
    then sum of divisors,
    σ(N) = [{p1^(q1+1)}-1]/(p1-1)
    src: https://cp-algorithms.com/algebra/divisors.html
    
    It's a multiplicative function.
    So, σ(ab) = σ(a)xσ(b)
*/
#define M 10000007
bool flag[M];
int primes[M];

int sieve()
{
    int i, j, total = 0, val;

    for (i = 2; i <= M; i++)
        flag[i] = 1;

    for (i = 2; i * i <= M; i++)
        if (flag[i])
            for (j = i; j * i <= M; j++)
                flag[i * j] = 0;

    for (i = 2; i <= M; i++)
        if (flag[i])
            primes[total++] = i;

    return total;
}

int Sum_Of_Divisor(int N)
{
    int i, val, count, sum, p, s;

    val = sqrt(N) + 1;
    sum = 1;
    for (i = 0; primes[i] < val; i++)
    {
        if (N % primes[i] == 0)
        {
            p = 1;
            while (N % primes[i] == 0)
            {
                N /= primes[i];
                p = p * primes[i];
            }
            p = p * primes[i];
            s = (p - 1) / (primes[i] - 1);
            sum = sum * s;
        }
    }

    if (N > 1)
    {
        p = N * N;
        s = (p - 1) / (N - 1);
        sum = sum * s;
    }
    return sum;
}
//********************* Euclid ****************************
//===================== GCD & LCM =========================
//!single occurance
//GCD
int gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//LCM
int lcm(long long a, long long b)
{
    long long mul = a * b;
    return mul / gcd(a, b);
}
//=============== Extended ALgorithm =======================
// ax + by = gcd (a,b)
tuple<int, int, int> extendedGCD(int a, int b)
{
    if (b == 0)
    {
        return {1, 0, a};
    }
    else
    {
        int x, y, g;
        tie(x, y, g) = extendedGCD(b, a % b);
        return {y, x - (a / b) * y, g};
    }
}
// solving Diophantine Equation using extended algo
// ex: 5x + 4x = 29 ... solve for x, y
// the x, y will be true for every (x + (kb)/gcd(a,b), y - (ka)/gcd(a,b))
pair<double, double> solveEqu(int a, int b, int c)
{
    int x, y, g;
    tie(x, y, g) = extendedGCD(a, b);
    double r = (c * 1.0) / g;
    return {r * x, r * y};
}
//**************** Modular Arithmetic *******************

//********************* Others **************************
int countDigit(long long n)
{
    return floor(log10(n) + 1);
}