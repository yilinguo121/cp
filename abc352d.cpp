#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main() {
	int n, k;
	cin >> n >> k;
	int map[n + 1] = {};  // O(N) 空間，用於存儲元素的位置
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		map[p] = i;  // 儲存每個元素的位置
	}
	set<int> st;  // set 用於跟踪當前子序列中的索引
	int ans = 1e7;  // 初始化答案為較大值
	for (int i = 1; i <= n; i++) {  // O(N) 時間複雜度
		st.insert(map[i]);  // 將當前元素的位置插入到 set 中
		if (st.size() > k) st.erase(map[i - k]);  // 維持 set 的大小為 k，O(log K) 操作
		if (st.size() == k) ans = min(ans, *--st.end() - *st.begin());  // 計算最小的索引差值，O(log K) 操作
	}
	cout << ans;
}

