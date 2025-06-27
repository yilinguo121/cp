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
string ox[2][3] = {
	{
		"00",
		"01",
		"x1"
	},
	{
		"00",
		"10",
		"1x"
	}
};
string s[505];
bool vis[505][505];
bool cmp(int x, int y, int k) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 2;j++) {
			if (ox[k][i][j] == 'x') continue;
			if (vis[i + x][j + y]) return 0;
			if (s[i + x][j + y] != ox[k][i][j]) return 0;
		}
	}
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 2;j++) {
			if (ox[k][i][j] == 'x') continue;
			vis[i + x][j + y] = 1;
		}
	}
	return 1;	
}
int main() {
	int n, m;
	n = read();
	m = read();
	for (int i = 0;i < n;i++) {
		cin >> s[i];
	}
	long long ans = 0;
	for (int i = 0;i < m - 1;i++) {
		for (int j = 0;j < n - 2;j++) {
			for (int k = 0;k < 2;k++) {
				if (cmp(j, i, k)) {
					ans++;
				}
			}
		}
	}
	cout << ans;
}

