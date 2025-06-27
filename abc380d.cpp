#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
// 0xff = 0b1111 1111
// 0x41 A = 0b0100 0001
// 0x61 a = 0b0110 0001
// 0x41 ^ 0x20 = 0b0100 0001 ^ 0b0010 0000 = 0b0110 0001
// 0x61 ^ 0x20 = 0b0110 0001 ^ 0b0010 0000 = 0b0100 0001
template<typename Type>
inline void read(Type& res) {
    Type x=0,f=1;
    char c=' ';
    while(!isdigit(c)) {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    res=x*f;
}
int main() {
	char s[200000];
	scanf("%s", s);
	int q;
	read(q);
	int n = strlen(s);
	while (q--) {
		long long int k;
		read(k);
		k--;
		//cout << (char)((1ll * (__builtin_popcountll(k / n) % 2) << 5) ^ s[k % n]) << ' ';
		putchar((char)((1ll * (__builtin_popcountll(k / n) % 2) << 5) ^ s[k % n]));
		putchar(' ');
	}
}

