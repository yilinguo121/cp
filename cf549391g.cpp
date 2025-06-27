#include <bits/stdc++.h>
using namespace std;
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
int main() {
	int n;
	n = read();
	int h[225][2] = {};
	for (int i = 0;i < n;i++) {
		int t, v;
		t = read();
		v = read();
		if (v > h[t][0]) {
			h[t][1] = h[t][0];
			h[t][0] = v;
		}
		else if (v > h[t][1]) {
			h[t][1] = v;
		}
	}
	vector<pair<int, int>> a;
	for (int i = 140;i <= 220;i++) {
		for (int j = 0;j < 2;j++) {
			if (h[i][j]) a.push_back({h[i][j], i});
		}
	}
	int ans = -1e7;
	for (int i = 0;i < a.size();i++) {
		for (int j = i + 1;j < a.size();j++) {
			int x = a[i].first + a[j].first;
			if (abs(a[i].second - a[j].second) > 5) x -= 5 * abs(a[i].second - a[j].second);
			ans = max(ans, x);
		}
	}
	cout << ans;
}

