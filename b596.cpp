#include <bits/stdc++.h>
using namespace std;
void getRC(int cell, int &r, int &c) {
    r = (cell - 1) / 3;
    c = (cell - 1) % 3;
}
bool isAdjacent(int cell1, int cell2) {
    int r1, c1, r2, c2;
    getRC(cell1, r1, c1);
    getRC(cell2, r2, c2);
    int dist = abs(r1 - r2) + abs(c1 - c2);
    return (dist == 1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int A, B, C;
        cin >> A >> B >> C;
        vector<int> ans;
        for(int candidate = 1; candidate <= 9; candidate++){
            if(isAdjacent(A, candidate) &&
               !isAdjacent(B, candidate) &&
               !isAdjacent(C, candidate))
            {
                ans.push_back(candidate);
            }
        }
        if(ans.empty()){
            cout << "Empty";
        } else {
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i];
                if(i != ans.size() - 1)
                    cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
