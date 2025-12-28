#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int a, b;
	while (cin >> a >> b) {
		int sum = a * b;
		string w = to_string(sum);
		cout << string(w.size() + 1 - to_string(a).size(), ' ') << a << '\n';
		cout << 'x' << string(w.size() - to_string(b).size(), ' ') << b << '\n';
		cout << string(w.size() + 1, '-') << '\n';
		for (int i = to_string(b).size() - 1;i >= 0;i--) {
			int now = (to_string(b)[i] - '0') * a;
			cout << string(w.size() + 1 - to_string(now).size() - (to_string(b).size() - 1 - i), ' ') << now << '\n';
		}
		cout << string(w.size() + 1, '-') << '\n';
		cout << ' ' << sum << '\n';
	}
}

