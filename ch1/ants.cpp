#include <bits/stdc++.h>
using namespace std;

const int MAX_IN = 100000;
int L, n;
int x[MAX_IN];

void solve() {
    int minT = 0;
    for(int i = 0; i < n; i++) {
        minT = min(minT, min(x[i], L - x[i]));
    }

    int maxT = 0;
    for(int i = 0; i < n; i++) {
        maxT = max(maxT, max(x[i], L - x[i]));
    }

    printf("%d %d\n", minT, maxT);
}