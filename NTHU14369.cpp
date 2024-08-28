#include<bits/stdc++.h>
using namespace std;
vector<int> pre, in, post, pos, ans;
struct Node {
	int val;
	Node *lc, *rc;
};
int now = 0;
bool cantbuild = 0;
Node *build(int l, int r) {
	if (l > r) return NULL;
	Node *res = new Node();
	res->val = pre[now];
	int m = pos[pre[now]];
	if (m < l or m > r) {
		cantbuild = 1;
		return NULL;
	}
	now++;
	res->lc = build(l, m - 1);
	res->rc = build(m + 1, r);
	return res;
}
void dfs(Node *t) {
	if (t == NULL) return;
	dfs(t->lc);
	dfs(t->rc);
	ans.push_back(t->val);
}
void f() {
	int n;
	cin >> n;
	pre.resize(n);
	in.resize(n);
	post.resize(n);
	pos.resize(n + 1);
	ans.clear();
	now = 0;
	cantbuild = 0;
	for (int i = 0;i < n;i++) cin >> pre[i];
	for (int i = 0;i < n;i++) cin >> in[i];
	for (int i = 0;i < n;i++) pos[in[i]] = i;
	for (int i = 0;i < n;i++) cin >> post[i];
	Node *t = build(0, n - 1);
	if (cantbuild) {
		cout << "no" << '\n';
		return;
	}
	dfs(t);
	if (ans == post) cout << "yes" << '\n';
	else cout << "no" << '\n';
}
int main() {
	int t;
	cin >> t;
	while(t--) f();
}
