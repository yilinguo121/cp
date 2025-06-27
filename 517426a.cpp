#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    long long S1, S2, X1, X2, Y1, Y2, Z1, Z2;
    cin >> S1 >> S2 >> X1 >> X2 >> Y1 >> Y2 >> Z1 >> Z2;
    int answer = 0;
    for(long long x = S1; x <= S2; x++) {
        bool found = 0;
		for(long long B = Y1; B <= Y2; B++) {
			for(long long C = Z1; C <= Z2; C++) {
				if(x % (B * C) == 0 and x / B / C >= X1 and x / B / C <= X2) {
					found = 1;
				}
			}
		}
        answer += found;
    }
    cout << answer << endl;
    return 0;
}
