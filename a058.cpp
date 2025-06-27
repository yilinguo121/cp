#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a = 0, b = 0, c = 0;
	while(n--) {
		int t;
		cin >> t;
		if (t % 3 == 0) a++;
		else if ((t - 1) % 3 == 0) b++;
		else c++;
	}
	cout << a << ' ' << b << ' ' << c;
}
