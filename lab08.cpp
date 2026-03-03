#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Tail-recursive helper function prototypes
*******************************************************************************/

unsigned factHelper(unsigned, unsigned);
unsigned fibHelper(unsigned, unsigned, unsigned);
unsigned multHelper(unsigned, unsigned, unsigned);
unsigned powerHelper(unsigned, unsigned, unsigned);
unsigned productHelper(unsigned, unsigned, unsigned);

/*******************************************************************************
 * Original function prototypes (unchanged)
*******************************************************************************/

unsigned fact(unsigned);
unsigned fib(unsigned);
unsigned mult(unsigned, unsigned);
unsigned power(unsigned, unsigned);
unsigned product(unsigned, unsigned);

/*******************************************************************************
 * MAIN
*******************************************************************************/

int main() {
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;
    cout << "50th Fibonacci number is " << fib(50) << endl;
    return 0;
}

/*******************************************************************************
 * Tail Recursive Implementations
*******************************************************************************/

// Factorial: O(n)
unsigned fact(unsigned n) {
    return factHelper(n, 1);
}

unsigned factHelper(unsigned n, unsigned acc) {
    if (n <= 1)
        return acc;
    return factHelper(n - 1, acc * n);
}


// Fibonacci: O(n) instead of O(2^n)
unsigned fib(unsigned n) {
    return fibHelper(n, 0, 1);
}

unsigned fibHelper(unsigned n, unsigned a, unsigned b) {
    if (n == 0)
        return a;
    return fibHelper(n - 1, b, a + b);
}


// Multiplication via repeated addition: O(y)
unsigned mult(unsigned x, unsigned y) {
    return multHelper(x, y, 0);
}

unsigned multHelper(unsigned x, unsigned y, unsigned acc) {
    if (y == 0)
        return acc;
    return multHelper(x, y - 1, acc + x);
}


// Power function: O(y)
unsigned power(unsigned x, unsigned y) {
    return powerHelper(x, y, 1);
}

unsigned powerHelper(unsigned x, unsigned y, unsigned acc) {
    if (y == 0)
        return acc;
    return powerHelper(x, y - 1, acc * x);
}


// Product from x to y: O(y - x)
unsigned product(unsigned x, unsigned y) {
    return productHelper(x, y, 1);
}

unsigned productHelper(unsigned x, unsigned y, unsigned acc) {
    if (x > y)
        return acc;
    return productHelper(x + 1, y, acc * x);
}