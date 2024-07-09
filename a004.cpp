#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	while (cin >> n) {
		if ((n % 4 == 0 and n % 100 != 0) or n % 400 == 0){
		cout << "閏年" << '\n';
		}
		else {
		cout << "平年" << '\n';
		}
	}
}
