#include<bits/stdc++.h>
using namespace std;
signed main() {
	int n;
	cin >> n;
	priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		pq.push(k);
	}
	int sum = 0;
	long long int ans = 0;
	while (pq.size() > 1){
		long long int a = pq.top();
		pq.pop();
		long long int b = pq.top();
		pq.pop();
		long long int all = a + b;
		ans += all;
		pq.push(all);
	}
	cout << pq.top() << '\n' << ans << '\n';
}
