#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
bool cmp(pair<int, int> a, pair<int, int> b){
	return (a.f * a.f) + (a.s * a.s) > (b.f * b.f) + (b.s * b.s);
}
int main(){
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].f >> v[i].s;
	}
	sort (v.begin(), v.end(), cmp);
	cout << v[1].f << ' ' << v[1].s << '\n';
}
