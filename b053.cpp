#include <bits/stdc++.h>
using namespace std;
int a[10][10] ,n;
vector<pair<int ,int>> p;
bool h = 0;
void out() {
    for(int i = 1; i <= n * n; i++) {
        for(int j = 1; j <= n * n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}
void f(int t){
	if (h == 1){
		return;
	}
	if (t == p.size()){
		h = 1;
		out();
		return;
	}
	int x = p[t].first;
	int y = p[t].second;
	for (int i = 1;i <= n * n;i++){
		bool put = 1;
		for (int j = 1;j <= n * n;j++){
			if (j == y){
				continue;
			}
			if(a[x][j] == i){
				put = 0;
			}
		}
		for (int j = 1;j <= n * n;j++){
			if (j == x){
				continue;
			}
			if(a[j][y] == i){
				put = 0;
			}
		}
		int xx = n * ((x - 1) / n) + 1;
		int yy = n * ((y - 1) / n) + 1;
		for (int j = xx;j < n + xx;j++){
			for (int k = yy;k < n + yy;k++){
				if (i == a[j][k]){
					put = 0;
				}
			}
		}
		if (put){
			a[x][y] = i;
			f(t + 1);
			a[x][y] = 0;
		}		
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n){
		p.clear();
		memset(a ,0 ,sizeof(a));
		h = 0;
		for (int i = 1;i <= n * n;i++){
			for (int j = 1;j <= n * n;j++){
				cin >> a[i][j];
				if (a[i][j] == 0){
					p.push_back({i ,j});
				}
			}
		}
		f(0);
		if(h == 0){
			cout << "NO SOLUTION" << '\n';
		}
	}
}
