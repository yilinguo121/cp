#include<bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N;
    vector<unsigned int> a(N);
    cin >> a[0] >> K;
    unsigned long long x = a[0];
    for(int i = 1; i < N; i++) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        a[i] = x & ((1LL << 30) - 1);
    }
	nth_element(a.begin(), a.end() - K, a.end());
	long long int ans = 0;
	for (int i = N - 1;i >= N - K;i--) {
		ans += a[i];
	}
	cout << ans;
}
