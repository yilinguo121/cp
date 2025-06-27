#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	bool have[n + 1] = {};
	for (int i = 0;i < m;i++) {
		int a;
		char b;
		cin >> a >> b;
		if (b == 'F') {
			cout << "No\n";
			continue;
		}
		if (!have[a]) cout << "Yes\n";
		else cout << "No\n";
		have[a] = 1;
	}
}
