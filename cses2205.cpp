#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<string> f(int n) {
	if (n == 1) return {"0", "1"};
	vector<string> now;
	auto x = f(n - 1);
	for (int i = 0;i < x.size();i++) now.push_back("0" + x[i]);
	for (int i = x.size() - 1;i >= 0;i--) now.push_back("1" + x[i]);
	return now;
}
int main() {
	IO
	int n;
	cin >> n;
	for (auto x : f(n)) cout << x << '\n';
}

