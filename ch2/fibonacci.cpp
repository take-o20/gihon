#include <bits/stdc++.h>
using namespace std;

int fib1(int n) {
    if(n <= 1)
        return n;
    return fib1(n - 1) + fib1(n - 2);
}

const int MAX_N = 2 << 100;
int memo[MAX_N + 1];

int fib2(int n) {
    if(n <= 1)
        return n;
    if(memo[n] != 0)
        return memo[n];
    return memo[n] = fib2(n - 1) + fib2(n - 2);
}