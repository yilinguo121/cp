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
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		v[i] = read();
	}
	sort(v.begin(), v.end());
	for (int i = n - 1;i >= 2;i--) {
		if (v[i] < v[i - 1] + v[i - 2]) {
			cout << v[i - 2] << ' ' << v[i - 1] << ' ' << v[i];
			return 0;
		}
	}
	cout << -1;
}

