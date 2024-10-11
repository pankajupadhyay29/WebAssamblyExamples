// fibonacci.c
#include <emscripten.h>

// Create an array for memoization
int f[10000] = {0};

int fibonacci(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    // If fib(n) is already computed
    if (f[n])
        return f[n];

    int k = (n & 1) ? (n + 1) / 2 : n / 2;

    // Applying above formula [Note value n&1 is 1
    // if n is odd, else 0].
    f[n] = (n & 1) ? (fibonacci(k) * fibonacci(k) + fibonacci(k - 1) * fibonacci(k - 1))
                   : (2 * fibonacci(k - 1) + fibonacci(k)) * fibonacci(k);

    return f[n];
}

// Computes value of first Fibonacci numbers
EMSCRIPTEN_KEEPALIVE
double fibonacciSum(double n)
{
    // return fibonacci(n+2) - 1;
    double a = 0, b = 0, sumf = 1;
    if (n <= 0)
        sumf = 0;
    double curr = 1;
    for (int i = 1; i < n; i++)
    {
        a = b;
        b = curr;
        curr = a + b;
        sumf += curr;
    }
    return sumf;
}
