#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> x(3), y(3);
    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }
    double ab, bc, ca;
    ab = sqrt(pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2));
    bc = sqrt(pow(x[1] - x[2], 2) + pow(y[1] - y[2], 2));
    ca = sqrt(pow(x[2] - x[0], 2) + pow(y[2] - y[0], 2));
    vector<double> v = {ab, bc, ca};
    sort(v.begin(), v.end());
    double e = 1e-9;
    if (abs(v[2] * v[2] - (v[1] * v[1] + v[0] * v[0])) < e) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

