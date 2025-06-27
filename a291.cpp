#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans[4];
    while (cin >> ans[0]) {
        for (int i = 1;i < 4;i++) {
            cin >> ans[i];
        }
		int n;
		cin >> n;
        for (int i = 0;i < n;i++) {
			int num[10] = {};
			for (int i = 0;i < 4;i++) num[ans[i]]++;
            int guess[4];
            for (int i = 0;i < 4;i++) cin >> guess[i];
            int a = 0, b = 0;
            for (int i = 0;i < 4;i++) if (ans[i] == guess[i]) a++;
            for (int i = 0;i < 4;i++) {
                if (num[guess[i]] - 1 >= 0) {
					b++;
					num[guess[i]]--;
				}
            }
            cout << a << "A" << b - a << "B\n"; 
        }
    }
}
