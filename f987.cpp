#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string s[5] = {"Hello, World!\n", "hello, world\n", "Halo, word!!!\n", "世界，您好！\n", "https://zerojudge.tw/ShowProblem?problemid=a001\n"};
	cout << s[time(NULL) % 5];
	this_thread::sleep_for(chrono::milliseconds(950));
}
