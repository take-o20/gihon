#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
const int MAX_W = 10000;

int n, W;
int w[MAX_N], v[MAX_N];

// memo table
int dp[MAX_N + 1][MAX_W + 1];

int rec(int i, int j) {
    if(dp[i][j] > 0) {
        return dp[i][j];
    }
    int res;
    if(i == n) {
        return 0;
    } else if(j < w[i]) {
        res = rec(i + 1, j);
    } else {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    return dp[i][j] = res;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cout << rec(0, W) << endl;
}

/*
    dp[i][j]:=i番目以降の品物から重さの総和がｊ以下となるように選んだときの価値の総和の最大値
    dp[n][j]:=0
    dp[i][j]= dp[i+1][j](j<w[i])
            = max(dp[i+1][j],dp[i+1][j-w[i]]+v[i])
*/
void solve_zenkasiki() {
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= W; j++) {
            if(j < w[i]) {
                dp[i][j] = dp[i + 1][j];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[0][W] << endl;
}

/*
    dp[i+1][j]:=i番目までの品物から重さの総和がｊ以下となるように選んだときの価値の総和の最大値
    dp[0][j]=0;
    dp[i+1][j]=dp[i][j](j<w[i])
               max(dp[i][j], dp[i][j-w[i]]+v[i])
*/
void solve_zenkasik2() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= W; j++) {
            if(j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][W] << endl;
}
/*
　配列version
*/
int DP[MAX_W + 1];
void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = W; j >= w[i]; j--) {
            DP[j] = max(DP[j], DP[j - w[i]] + v[i]);
        }
    }
}