#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string s, x;
		for (int i = 0;i < 4;i++) {
			cin >> x;
			s += x;
		}
		int sum = 0;
		for (int i = 0;i < 16;i++) {
			if (i % 2) sum += (s[i] - '0');
			else  {
				int k = s[i] - '0';
				k *= 2;
				while (k) {
					sum += k % 10;
					k /= 10;
				}
			}
		}
		if (sum % 10) cout << "Invalid\n";
		else cout << "Valid\n";
	}
}

