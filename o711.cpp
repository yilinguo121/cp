#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int vol_to_h(int vol, int a1, int a2, int c1, int c2, int h1){
    if (vol <= 0) return 0;
    if (vol <= c1) return vol / a1;
    int rem = vol - c1;
    if (rem > c2) rem = c2;
    return h1 + rem / a2;
}
int main(){
    IO
    int n;
    cin >> n;
    int w1, w2, h1, h2;
    cin >> w1 >> w2 >> h1 >> h2;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int a1 = w1 * w1;
    int a2 = w2 * w2;
    int c1 = a1 * h1;
    int c2 = a2 * h2;
    int total = c1 + c2;
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int b = vol_to_h(cur, a1, a2, c1, c2, h1);
        cur += v[i];
        if (cur > total) cur = total;
        int a = vol_to_h(cur, a1, a2, c1, c2, h1);
        ans = max(ans, a - b);
    }
    cout << ans << '\n';
    return 0;
}
