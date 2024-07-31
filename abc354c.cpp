#include<bits/stdc++.h>
using namespace std;
struct s{
	int a;
	int c;
	int r;
};
bool cmp(s d, s b) {
	return d.a > b.a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<s> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].a >> v[i].c;
		v[i].r = i + 1;
	}
	sort(v.begin(), v.end(), cmp);
	vector<int> k;
	int minc = 1e19;
	for (int i = 0;i < n;i++) {
		if (v[i].c < minc) {
			minc = v[i].c;
			k.push_back(v[i].r);
		}
	}
	sort(k.begin(), k.end());
	cout << k.size() << '\n';
	for (int i = 0;i < k.size();i++) {
		cout << k[i] << ' ';
	}
}
