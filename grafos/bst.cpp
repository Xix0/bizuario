#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<int> v;
long long table[N][30], arr[N];

void bst(int n) {
    for(int i = 0; i < n; i++) {
        table[i][0] = arr[i];
    }
    for(int j = 1; j <= log2(n); j++) {
        for(int i = 0; i <= n - (1 << j); i++) {
            table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}