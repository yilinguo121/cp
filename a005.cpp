#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long a[5];
	while (n--) {
		for (int i = 0;i < 4;i++) cin >> a[i];
		if (a[1] - a[0] == a[2] - a[1] and a[2] - a[1] == a[3] - a[2]) a[4] = a[3] + a[3] - a[2];
		else a[4] = a[3] * (a[3] / a[2]);
		for (int i = 0;i < 5;i++) cout << a[i] << ' ';
		cout << '\n';
	}
}
