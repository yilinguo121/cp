#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;  // 讀取 A (表達愛的時間), B (睡覺時間), C (醒來時間)
	// 判斷 A 是否在睡覺時間 B 和醒來時間 C 之間，或處理跨過午夜的情況

	if ((a >= b and a <= c) or (b >= c and c >= a) or (b >= c and a >= b)) cout << "No";
	// 如果 A 在 B 和 C 之間，或 B 和 C 跨過午夜且 A 在睡覺區間內，則輸出 "No"
	else cout << "Yes";
	// 否則，輸出 "Yes"
}

