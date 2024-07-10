#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<int, set<int>> x;
	map<int, set<int>> y;
	map<int, map<int, int>> t;
	for(int i = 0; i < n; i++){
		int xx, yy, tt;
		cin >> xx >> yy >> tt;
		t[xx][yy] = tt;
		y[xx].insert(yy);
		x[yy].insert(xx);
	}
	int way = 0;
	int ans = 0;
	int a = 0,b = 0;
	while(1){
		if (way == 0){
			if (x[b].upper_bound(a) == x[b].end()){
				break;
			}
			ans++;
			auto ite = x[b].upper_bound(a);
			a = *ite;
			if (t[a][b] == 1){
				way = 3;
			}
			else {
				way = 1;
			}
		}
		else if (way == 1){
			if (y[a].upper_bound(b) == y[a].end()){
				break;
			}
			ans++;
			auto ite = y[a].upper_bound(b);
			b = *ite;
			if (t[a][b] == 1){
				way = 2;
			}
			else {
				way = 0;
			}
		}
		else if (way == 2){
			if (x[b].lower_bound(a) == x[b].begin()){
				break;
			}
			ans++;
			auto ite = --x[b].lower_bound(a);
			a = *ite;
			if (t[a][b] == 1){
				way = 1;
			}
			else {
				way = 3;
			}
		}
		else if (way == 3){
			if (y[a].lower_bound(b) == y[a].begin()){
				break;
			}
			ans++;
			auto ite = --y[a].lower_bound(b);
			b = *ite;
			if (t[a][b] == 1){
				way = 0;
			}
			else{
				way = 2;
			}
		}
	}
	cout << ans << '\n';
}
