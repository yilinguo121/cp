#include<bits/stdc++.h>
using namespace std;
#define int long long
bool int_cmp (int a, int b){
	int q = 0, p = 0;
	int aa = a;
	int bb = b;
	while (aa != 0){
		aa = aa / 10;
		q++;
	}
	while (bb != 0){
		bb = bb / 10;
		p++;
	}
	int aaa = a, bbb = b;
	for (int i = 0; i < p; i++) {
		aaa = aaa * 10;
	}
	for (int i = 0; i < q; i++) {
		bbb = bbb * 10;
	}
	return aaa + b > bbb + a;

}
void int_f(int n){
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end(),int_cmp);
	for (int i = 0; i < n; i++) {
		cout << v[i];
	}
	cout << '\n';
}
bool str_cmp(string a, string b) {
       return a + b > b + a;
}
void str_f(int n){
	vector<string> v;
	for (int i = 0; i < n; i++){
		string t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end(), str_cmp);
	for (int i = 0; i < n; i++) {
		cout << v[i];
	}
	cout << '\n';
}

signed main() {
	int n;
	while (cin >> n){
		if (n == 0){
			break;
		}
		int_f(n);
		str_f(n);
	}
}
