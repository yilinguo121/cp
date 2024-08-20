#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, a, b;
	cin >> n >> a >> b;  // 讀取計劃數量 n、假日天數 a、工作日天數 b
	vector<int> d;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		d.push_back(t % (a + b));  // 計算每個計劃落在週期內的哪一天
		// 這一部分的時間複雜度為 O(N)，因為每個計劃都需要進行模運算並存入向量中
	}
	sort(d.begin(), d.end());  // 將計劃日子按模值進行排序
	// 排序的時間複雜度為 O(N log N)

	for (int i = 0; i < n; i++) {
		// 如果最晚的計劃日子和當前計劃日子的差值小於假日天數 a，則計劃可以安排在假日
		if (d.back() - d[i] < a) {
			cout << "Yes";  // 可以在假日安排所有計劃
			return 0;
		}
		// 考慮將計劃推移一個週期並再次檢查是否符合條件
		d.push_back(d[i] + a + b);
		// 這一部分的時間複雜度為 O(N)，因為每個計劃都可能被推入到下一個週期
	}
	cout << "No";  // 無法在假日安排所有計劃
	// 最終輸出的時間複雜度為 O(1)
}

