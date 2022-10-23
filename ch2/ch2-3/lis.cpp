// Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
int n;
int a[MAX_N];

int dp[MAX_N];

void solve() {
    int res = 0;
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j]) + 1;
            }
            res = max(res, dp[i]);
        }
    }
    cout << res << endl;
}

const int INF = 1 << 30;
int DP[MAX_N];
void solve2() {
    fill(DP, DP + n, INF);
    for(int i = 0; i < n; i++) {
        *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp + n, INF) - dp << endl;
}