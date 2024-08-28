#include <stdio.h>
#include "lib1044.h"
int main(void) {
	int n;
	n = Initialize();
	int l = 1, r = n, ans;
	while (l <= r) {
		int m = (l + r) / 2;
		bool f = Guess(m);
		if (f) {
			r = m - 1;
			ans = m;
		}
		else l = m + 1;
	}
	Report(ans);
}
