#include <bits/stdc++.h>
using namespace std;

const int MAX_IN = 100;
int n, a[MAX_IN];

void solve() {
    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                int len = a[i] + a[j] + a[k];
                int ma = max(a[i], a[j], a[k]);
                int rest = ma - len;
                if(ma < rest) {
                    ans = max(ans, len);
                }
            }
        }
    }
    cout << ans << endl;
}