#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, t;
	cin >> n >> t;
	int a[n] = {};
	//直的
	int b[n] = {};
	//橫的
	int c = 0;
	//左上到右下
	int d = 0;
	//右上到左下
	for (int i = 1;i <= t;i++) {
		int k;
		cin >> k;
		k--;
		int x = k / n;
		int y = k % n;
		a[x]++;
		b[y]++;
		if (x + y == n - 1) {
			d++;
		}
		if (x == y) {
			c++;
		}
		for (int j = 0;j < n;j++) {
			if (a[j] == n or b[j] == n or c == n or d == n) {
				cout << i;
				return 0;
			}
		}
		if (i == t) {
			cout << -1;
		}
	}
}
