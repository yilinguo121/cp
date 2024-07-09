#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int n;
		cin >> n;
		vector<int> v;
		for (int j = 2; j <= n; j++){
			v.push_back(j);
			n -= j;
		}
		for (int j = v.size() - 1; j >= 0 and n > 0; j--) {
			v[j]++;
			n--;
		}
		if (n > 0){
			v[v.size() - 1] += n;
		}
		for (int i = 0; i < v.size() - 1; i++){
			cout << v[i] << ' ';
		}
		cout << v[v.size() - 1] << '\n';
	}
}
