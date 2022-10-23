#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100;
const int MAX_K = 100000;
int n;
int K;
int a[MAX_N];
int m[MAX_N];

bool dp[MAX_N + 1][MAX_K + 1];

void solve() {
    dp[0][0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= K; j++) {
            for(int k = 0; k <= m[i] && k * a[i] <= j; k++) {
                dp[i + 1][j] |= dp[i][j - k * a[i]];
            }
        }
    }
    if(dp[n][K]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int DP[MAX_K + 1];

void solve2() {
    memset(DP, -1, sizeof(DP));
    DP[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= K; j++) {
            if(DP[j] >= 0) {
                DP[j] = m[i];
            } else if(j < a[i] || DP[j - a[i]] <= 0) {
                DP[j] = -1;
            } else {
                DP[j] = DP[j - a[i]] - 1;
            }
        }
    }
    if(DP[K] >= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}