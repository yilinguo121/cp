#include<bits/stdc++.h>
using namespace std;
int main() {
	int r;
	cin >> r;
	int ans = ((r / 100) + 1) * 100 - r;
	cout << ans;
}
