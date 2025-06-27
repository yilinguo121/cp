#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int main() {
	vector<pair<int, int>> v(3);
	for (int i = 0;i < 3;i++) {
		cin >> v[i].x >> v[i].y;
	}
	double ab = sqrt((v[0].x - v[1].x) * (v[0].x - v[1].x) + (v[0].y - v[1].y) * (v[0].y - v[1].y));
	double bc = sqrt((v[1].x - v[2].x) * (v[1].x - v[2].x) + (v[1].y - v[2].y) * (v[1].y - v[2].y));
	double ac = sqrt((v[0].x - v[2].x) * (v[0].x - v[2].x) + (v[0].y - v[2].y) * (v[0].y - v[2].y));
	double t = 0.00001;
	if (abs(ab * ab + bc * bc - ac * ac) < t or abs(ab * ab + ac * ac - bc * bc) < t or abs(ac * ac + bc * bc - ab * ab) < t) {
		cout << "Yes";
	}else {
		cout << "No";
	}
}
