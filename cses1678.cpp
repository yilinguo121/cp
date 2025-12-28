#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
vector<int> pa;
vector<bool> vis, vis2;
vector<int> ans, final_ans;
void dfs(int t) {
    vis[t] = 1;
    vis2[t] = 1;
    ans.push_back(t);
    for (auto nt : v[t]) {
        if (!vis[nt]) {
            pa[nt] = t;
            dfs(nt);
        }
		else if (vis2[nt]) {
            int flag = 0;
            final_ans.clear();
            for (auto x : ans) {
                if (x == nt) flag = 1;
                if (flag) final_ans.push_back(x);
            }
            final_ans.push_back(nt);
            cout << final_ans.size() << '\n';
            for (auto x : final_ans) cout << x << ' ';
            exit(0);
        }
    }
    ans.pop_back();
    vis2[t] = 0;
}
int main() {
    IO
    int n, m;
    cin >> n >> m;
    v.resize(n + 1);
    pa.resize(n + 1);
    vis.assign(n + 1, 0);
    vis2.assign(n + 1, 0);
    while (m--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    cout << "IMPOSSIBLE";
    return 0;
}
