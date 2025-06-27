// TIOJ 1668 . 分組編隊 TLE 的 code
#include<iostream>
#include<vector>
using namespace std;
void solve() {
    int L, R;
    cin >> L >> R;
    vector<bool> not_prime(R - L + 1);
    for(int i = 2; i * i <= R; i++) {
         int v = R / i * i; // v 是 <= R 的最大的 i 的倍數
         for(; v >= L && v > i; v -= i) {
             not_prime[v - L] = 1;
         }
    }
    int ans = 0;
    for(bool x: not_prime) {
        if(!x) ans++;
    }
    cout << ans << '\n';
}
int main() {
    int T;
    cin >> T;
    while(T--) solve();
}
