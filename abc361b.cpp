#include<bits/stdc++.h>
using namespace std;
bool f(int x1[], int y1[], int z1[], int x2[], int y2[], int z2[]) {
	int a = min(x1[1], x2[1]) - max(x1[0], x2[0]);
	int b = min(y1[1], y2[1]) - max(y1[0], y2[0]);
	int c = min(z1[1], z2[1]) - max(z1[0], z2[0]);
	if (a > 0 and b > 0 and c > 0) {
		return 1;
	}
	return 0;

}
int main() {
	int x1[2], y1[2], z1[2], x2[2], y2[2], z2[2];
	cin >> x1[0] >> y1[0] >> z1[0] >> x1[1] >> y1[1] >> z1[1];
	cin >> x2[0] >> y2[0] >> z2[0] >> x2[1] >> y2[1] >> z2[1];
	if (f(x1, y1, z1, x2, y2, z2) or f(x2, y2, z2, x1, y1, z1)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}
