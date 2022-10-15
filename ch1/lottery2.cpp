#include <bits/stdc++.h>
using namespace std;

const int MAX_IN = 1000;
int n, m, k[MAX_IN];
int kk[MAX_IN * MAX_IN];

bool binary_search(int x) {
    int l = 0, r = n;
    while(r - l > 0) {
        int i = (l + r) / 2;
        if(k[i] == x)
            return true;
        else if(k[i] < x) {
            l = i + 1;
        } else {
            r = i - 1;
        }
    }
}

void solve() {
    for(int c = 0; c < n; c++) {
        for(int d = 0; d < n; d++) {
            kk[c * n + d] = k[c] + k[d];
        }
    }
    sort(kk, kk + n * n);

    bool f = false;

    for(int a = 0; a < n; a++) {
        for(int b = 0; b < n; b++) {
            if(binary_search(m - k[a] - k[b])) {
                f = true;
            }
        }
    }
    if(f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}