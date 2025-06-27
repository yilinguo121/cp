#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n;
	cin >> n;
	int pos = 0;
	vector<int> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		if (a[i] > 0) pos++;
	}
	int ans = 0;
	while (1) {
		if (pos <= 1) break;
		ans++;
		sort(a.begin(), a.end(), cmp);
		a[0]--;
		a[1]--;
		if (a[0] < 1) pos--;
		if (a[1] < 1) pos--;
	}
	cout << ans;
}

