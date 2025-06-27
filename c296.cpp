#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n ,m ,k;
	cin >> n >> m >> k;
	vector<int> v;
	for (int i = 1; i <= n; i++){
		v.push_back(i);
	}
	int i = 0;
	for (int j = 0;j < k;j++){
		i += m - 1;
		i = i % v.size();
		v.erase(v.begin() + i);
	}
	i = i % v.size();
	cout << v[i];
}
