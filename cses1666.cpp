#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
vector<vector<int>> adj(maxn);
vector<bool> v(maxn);
vector<int> t;

void dfs(int i) {
    v[i] = 1;
    for (auto city : adj[i]) { // 時間複雜度: O(V + E)
        if (v[city] == 0) {
            dfs(city);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++) { // 時間複雜度: O(m)
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1;i <= n;i++) { // 時間複雜度: O(V)
        if (v[i] == 0) {
            dfs(i);
            t.push_back(i);
        }
    }
    cout << t.size() - 1 << '\n';
    for (int i = 0;i < t.size() - 1;i++) { // 時間複雜度: O(V)
        cout << t[i] << ' ' << t[i + 1] << '\n';
    }
}
// 空間複雜度: O(V + E)

