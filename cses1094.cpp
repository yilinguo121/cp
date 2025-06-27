#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main (){
	int n;
	//dewfewfwfwwfwf
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		v.push_back(t);
	}
	int ans = 0;
	for (int i = 1; i < v.size(); i++){
		if (v[i] < v[i - 1]){
			ans += v[i - 1] - v[i];
			v[i] = v[i - 1];
		}
	}
	cout << ans << '\n';
}
