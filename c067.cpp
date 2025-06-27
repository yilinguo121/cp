#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int i = 1;
	while (cin >> n) {
		if (!n) break;
		vector<int> v(n);
		for (int i = 0;i < n;i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int ans1 = 0, ans2 = 0;
		for (int i = 0;i < n;i++) {
			ans1 += abs(v[i] - v[n / 2 - 1]);
			ans2 += abs(v[i] - v[n / 2]);
		}
		cout << "Set #" << i << '\n';
		cout << "The minimum number of moves is ";
		i++;
		cout << min(ans1, ans2) / 2 << ".\n\n";
	}
}

