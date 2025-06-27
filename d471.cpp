#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        int x = 1 << n;  // 2^n 種組合
        for (int i = 0; i < x; i++) {
            for (int j = n - 1;j >= 0;j--) {
                cout << ((i >> j) & 1);
            }
            cout << "\n";
        }
    }
}
