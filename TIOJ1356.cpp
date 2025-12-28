#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int cnt = 1;
void h(int n, int f, int t) {
	if (!n) return;
	if (abs(f - t) == 1) {
		h(n - 1, f, 6 - f - t);
		cout << "#" << cnt++ << " : move the dish from #" << f << " to #" << t << '\n';
		h(n - 1, 6 - f - t, t);
	}
	else {
		h(n - 1, f, t);
		cout << "#" << cnt++ << " : move the dish from #" << f << " to #" << 6 - f - t << '\n';
		h(n - 1, t, f);
		cout << "#" << cnt++ << " : move the dish from #" << 6 - f - t << " to #" << t << '\n';
		h(n - 1, f, t);
	}
}
int main() {
	IO
	int n;
	cin >> n;
	h(n, 1, 3);
}

