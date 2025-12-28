#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
    int n;
    cin >> n;
    stack<int> s;
    while (n--) {
        int t;
        cin >> t;
        if (t == 1) s.pop();
        else if (t == 2) cout << s.top() << '\n';
        else {
            int num;
            cin >> num;
            s.push(num);
        }
    }
}
