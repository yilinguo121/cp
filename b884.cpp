#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		float yee = 100 - sqrt(x + y) * sqrt(x + y);
		if (yee > 0 and yee <= 30) cout << "sad!\n";
		else if (yee > 30 and yee <= 60) cout << "hmm~~\n";
		else if (yee > 60 and yee < 100) cout << "Happyyummy\n";
		else cout << "evil!!\n";
	}
}

