#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, w, q;
    cin >> h >> w >> q;
    map<int, set<int>> row;
    map<int, set<int>> col;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    int ans = h * w;
    while (q--) {
        int r, c;
        cin >> r >> c;
        if (col[c].find(r) != col[c].end()) {
            row[r].erase(c);
            col[c].erase(r);
            ans--;
            continue;
        }
        auto cu = col[c].upper_bound(r);
        if (cu != col[c].end()) {
            int up_r = *cu;
            ans--;
            col[c].erase(up_r);
            row[up_r].erase(c);
        }
        auto cl = col[c].lower_bound(r);
        if (cl != col[c].begin()) {
            --cl;
            int down_r = *cl;
            ans--;
            col[c].erase(down_r);
            row[down_r].erase(c);
        }
        auto ru = row[r].upper_bound(c);
        if (ru != row[r].end()) {
            int left_c = *ru;
            ans--;
            row[r].erase(left_c);
            col[left_c].erase(r);
        }
        auto rl = row[r].lower_bound(c);
        if (rl != row[r].begin()) {
            --rl;
            int right_c = *rl;
            ans--;
            row[r].erase(right_c);
            col[right_c].erase(r);
        }
    }
    cout << ans << '\n';
    return 0;
}

