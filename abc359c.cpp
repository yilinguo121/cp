#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b % 2 == 0 and a % 2 == 0) a++;
	if (d % 2 == 0 and c % 2 == 0) c++;
	if (b % 2 == 1 and a % 2 == 1) a++;
	if (d % 2 == 1 and c % 2 == 1) c++;
	int ans = 0;
	ans += abs(b - d);
	int dis = abs(a - c) - abs(b - d);
	dis = max(dis, 0ll);
	dis = dis / 2;
	ans += dis;
	cout << ans;
}

