#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int r[5] = {734, 632, 8, 612, 302};
	int t[5][5] = {{0, 4, 5, 6 ,12}, {4, 1, 9, 6, 8}, {11, 2, 4, 5, 9}, {5, 4, 6, 7, 6}, {4, 11, 88, 8, 0}};
	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		if (b == 734) b = 0;
		if (b == 632) b = 1;
		if (b == 8) b = 2;
		if (b == 612) b = 3;
		if (b == 302) b = 4;
		bool f = 0;
		for (int j = 0;j < 5;j++) {
			if (t[b][j] == a) {
				cout << "別騙我喔,qwq" << '\n';
				f = 1;
				break;
			}
		}
		if (f) {
			continue;
		}
		vector<int> v;
		for (int j = 0;j < 5;j++) {
			for (int k = 0;k < 5;k++) {
				if (t[j][k] == a) {
					v.push_back(r[j]);
					f = 1;
					break;
				}
			}
		}
		if (f) {
			for (int j = 0;j < v.size() - 1;j++) {
				cout << v[j] << ' ';
			}
			cout << v[v.size() - 1] << '\n';
		}
		if (f) {
			continue;
		}
		cout << "qwq，去搭taxi吧!" << '\n';
	}
}
