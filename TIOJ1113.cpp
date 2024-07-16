#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	while(cin >> s){
		sort(s.begin(), s.end());
		cout << s << '\n';
		while(next_permutation(s.begin(), s.end())){
			cout << s << '\n';
		}
		cout << '\n';
	}
}
