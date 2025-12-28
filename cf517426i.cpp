#include<bits/stdc++.h>
using namespace std;
const int SIZE = 500000;
vector<int> v;
int p[SIZE];
#define int long long
signed main() {
    int w;
    cin >> w;
    for(int i = 0; i < w; i++) cin >> p[i];
    int x, k;
    cin >> x >> k; // 0 <= x < w, 1 <= k <= 10^18
    while(k--) {
		x = p[x];
		if (x == v[0]) break;
		v.push_back(x);
		if (k == 0) {
			cout << x;
			return 0;
		}
	}
	k = k % v.size();
	cout << v[k];
}
