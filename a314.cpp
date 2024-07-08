#include<bits/stdc++.h>
using namespace std;
#define lint long long
bool cmp (pair<int, int> a ,pair<int, int> b){
	return a.second < b.second;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int ,int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), cmp);
	int t = v[0].second, ans = 1;
	for (int i = 0; i < n;i++) {
		if (v[i].first > t){
			ans++;
			t = v[i].second;
		}
	}
	cout << ans << '\n';
}
