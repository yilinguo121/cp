#include<bits/stdc++.h>
using namespace std;
vector<int> v(1000005);
int main() {
	int n;
	int ans = 0;
	cin >> n;
	while (n--) {
		int type;
		cin >> type;
		if (type == 1) {
			int x;
			cin >> x;
			if (v[x] == 0) {
				ans++;
			}
			v[x]++;
		}
		if (type == 2) {
			int x;
			cin >> x;
			if (v[x] == 1) {
				ans--;
			}
			v[x]--;
		}
		if (type == 3) {
			cout << ans << '\n';
		}
	}
}
