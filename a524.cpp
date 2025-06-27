#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		vector<int> v;
		for (int i = n;i >= 1;i--) v.push_back(i);
		for (int i = 0;i < n;i++) cout << v[i];
		cout << '\n';
		while (prev_permutation(v.begin(), v.end())) {
			for (int i = 0;i < n;i++) cout << v[i];
			cout << '\n';
		}
	}
}

