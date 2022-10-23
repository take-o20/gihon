#include <bits/stdc++.h>
using namespace std;
/*
 個数制限なしナップザック問題
*/

const int MAX_N = 100;
const int MAX_W = 10000;

int n, W;
int w[MAX_N], v[MAX_N];

// memo table
int dp[MAX_N + 1][MAX_W + 1];

/*
　漸化式
　dp[0][j]=0
  dp[i+1][j]=max{dp[i][j-k*w[i]]+k*v[i]|0<=k}
  計算量がO(nW^2)
*/
void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= W; j++) {
            for(int k = 0; k * w[i] <= j; k++) {
                dp[i + 1][j] =
                    max(dp[i + 1][j], dp[i][j - k * w[i]] + k * v[i]);
            }
        }
    }
    cout << dp[n][W] << endl;
}
/*
　漸化式
　dp[0][j]=0
  dp[i+1][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i])
  計算量がO(nW)
*/
void solve2() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= W; j++) {
            for(int k = 0; k * w[i] <= j; k++) {
                dp[i + 1][j] =
                    max(dp[i + 1][j], dp[i][j - k * w[i]] + k * v[i]);
            }
        }
    }
    cout << dp[n][W] << endl;
}

/*
　配列version
*/
int DP[MAX_W + 1];
void solve3() {
    for(int i = 0; i < n; i++) {
        for(int j = w[i]; j <= W; j++) {
            DP[j] = max(DP[j], DP[j - w[i]] + v[i]);
        }
    }
    cout << DP[W] << endl;
}