#include<bits/stdc++.h>
using namespace std;
int n;
void a(vector<int> v) {
	if (v[0] >= 60) {
		cout << "best case\n";
		return;
	}
	for (int i = 0;i < n - 1;i++) {
		if (v[i] < 60 and v[i + 1] >= 60) {
			cout << v[i] << '\n';
			return;
		}
	}
	cout << v[n - 1] << '\n';
}
void b(vector<int> v) {
	if (v[n - 1] < 60) {
		cout << "worst case\n";
		return;
	}
	for (int i = n - 1;i > 0;i--) {
		if (v[i] >= 60 and v[i - 1] < 60) {
			cout << v[i] << '\n';
			return;
		}
	}
	cout << v[0];
}
int main() {
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0;i < n;i++) cout << v[i] << ' ';
	cout << '\n';
	a(v);
	b(v);
	
}
