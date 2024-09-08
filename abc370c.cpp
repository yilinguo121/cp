#include <bits/stdc++.h>
using namespace std;
int main() {
    string S, T;
    cin >> S >> T;
    vector<string> X;
    int n = S.length();
	for (int i = 0; i < n; ++i) {
		if (S[i] > T[i]) {
			S[i] = T[i];
			X.push_back(S);
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (S[i] < T[i]) {
			S[i] = T[i];
			X.push_back(S);
		}
	}
    cout << X.size() << endl;
    for (const string& s : X) {
        cout << s << endl;
    }
    return 0;
}
