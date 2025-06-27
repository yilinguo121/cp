#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace IO {
	#if ONLINE_JUDGE
	#define getc() (IS == IT && (IT = (IS = ibuf) + fread(ibuf, 1, IL, stdin), IS == IT) ? EOF : *IS++)
	#else
	#define getc() getchar()
	#endif
	const int IL = 1 << 21, OL = 1 << 21;
	int olen = 0;
	char ibuf[IL], *IS = ibuf, *IT = ibuf, obuf[OL];
	inline int read() {
		char ch = getc(); int x = 0, f = 1;
		while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getc(); }
		while(isdigit(ch)) x = x * 10 + ch - 48, ch = getc();
		return x * f;
	}
	inline double readdb() {
		char ch = getc(); double x = 0, f = 1;
		while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getc(); }
		while(isdigit(ch)) x = x * 10 + ch - 48, ch = getc();
		if(ch == '.') {
			double b = 0.1;
			ch = getc();
			while(isdigit(ch)) x += (ch - 48) * b, b *= 0.1, ch = getc();
		}
		return x * f;
	}
	inline int readstr(char *s) {
		char ch = getc(); int len = 0;
		while(!isalpha(ch)) ch = getc();
		while(isalpha(ch)) s[len++] = ch, ch = getc();
		s[len] = '\0';  // 在字符串末尾加上 '\0' 結束符
		return len;
	}
	inline void flush() { fwrite(obuf, 1, olen, stdout); olen = 0; }
	inline void putc(char ch) { obuf[olen++] = ch; }
	template<class T>
	inline void write(T x) {
		if(x < 0) obuf[olen++] = '-', x = -x;
		if(x > 9) write(x / 10);
		obuf[olen++] = x % 10 + 48;
	}
} using namespace IO;
signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(m);
	for (int i = 0;i < m;i++) cin >> x[i];
	if (m == 1) {
		cout << 0;
		return 0;
	}
	sort(x.begin(), x.end());
	vector<int> dis(m - 1);
	for (int i = 0;i < m - 1;i++) {
		dis[i] = x[i + 1] - x[i];
	}
	int ans = 0;
	sort(dis.begin(), dis.end());
	for (int i = 0;i < m - n;i++) {
		ans += dis[i];
	}
	cout << ans;
}

