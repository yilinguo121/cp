#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for (int i = 0;i < n;i++) cin >> x[i] >> y[i];
	if (accumulate(x.begin(), x.end(), 0) > accumulate(y.begin(), y.end(), 0)) cout << "Takahashi";
	else if (accumulate(x.begin(), x.end(), 0) < accumulate(y.begin(), y.end(), 0)) cout << "Aoki";
	else cout << "Draw";
}

