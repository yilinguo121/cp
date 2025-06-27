#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100];
int f(int i){
	if (i == 0){
		return 1;
	}
	if (i == 1){
		return 1;
	}
	if (a[i]){
		return a[i];
	}
	return a[i] = f(i - 1) + f(i - 2);
}
signed main() {
	int n;
	while (cin >> n){
		if (n == 0){
			break;
		}
		cout << f(n) << '\n';
	}
}
