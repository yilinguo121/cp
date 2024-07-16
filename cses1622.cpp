#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int ans = 1;
	vector<string> v;
	sort(s.begin(), s.end());
	v.push_back(s);
	while (next_permutation(s.begin(), s.end())){
		ans++;
		v.push_back(s);
	}
	cout << ans << '\n';
	for (int i = 0;i < v.size();i++){
		cout << v[i] << '\n';
	}
}
