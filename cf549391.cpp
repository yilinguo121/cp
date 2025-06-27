#include <bits/stdc++.h>
using namespace std;
int a[200001] = {};
void f(int x) {
	if (x == 1) {
		cout << 1;
		return;
	}
	f(a[x]);
	cout << "->";
	cout << x;
}
int main() {
	int n;
	cin >> n;
	for (int i = 2;i <= n;i++) cin >> a[i];
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		f(x);
		cout << '\n';
	}
}
