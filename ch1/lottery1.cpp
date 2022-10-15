#include <bits/stdc++.h>
using namespace std;

const int MAX_IN = 100000;
int n, m, k[MAX_IN];

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
    sort(k, k + n);

    bool f = false;

    for(int a = 0; a < n; a++) {
        for(int b = 0; b < n; b++) {
            for(int c = 0; c < n; c++) {
                if(binary_search(m - k[a] - k[b] - k[c])) {
                    f = true;
                }
            }
        }
    }
    if(f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}