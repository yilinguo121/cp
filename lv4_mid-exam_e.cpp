#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<pair<double, double>> v;
double f(double x) {
	double cnt = 0;
	for (auto [a, d] : v) cnt += abs(a * x - d);
	return cnt;
}
int main() {
	int n;
	cin >> n;
	v.resize(n);
	for (auto &[a, d] : v) cin >> a >> d;
	double l = 0, r = INF;
	for (int k = 0;k < 1000;k++) {
		double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if (f(m1) < f(m2)) r = m2;
		else l = m1;
	}
	cout << fixed << setprecision(15) << f(l);
}
