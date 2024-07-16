#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int a[100005];
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	for (int i = 0;i < k;i++){
		int t;
		cin >> t;
		int l = -1, r = n, m = (l + r) / 2;
		while(1) {
			if (t == a[m]) {
				cout << m + 1 << '\n';
				break;
			}
			if (t > a[m]){
				l = m;
				m = (l + r) / 2;
			}
			if (t < a[m]){
				r = m;
				m = (l + r) / 2;
			}
			if (r - l <= 1){
				cout << 0 << '\n';
				break;
			}
		}
	}
}
