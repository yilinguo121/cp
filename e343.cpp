#include<bits/stdc++.h>
using namespace std;
int main() {
	double w, h;
	double bmi;
	cin >> w >> h;
	bmi = w / pow(h, 2);
	cout << fixed << setprecision(1) << bmi << '\n';
}
