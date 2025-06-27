#include<bits/stdc++.h>
using namespace std;
int main() {
	char q, w, e;
	cin >> q >> w >> e;
	if ((q == '<' and w == '<' and e == '<') or (q == '>' and w == '>' and e == '>')) cout << 'B';
	if ((q == '<' and w == '<' and e == '>') or (q == '>' and w == '>' and e == '<')) cout << 'C';
	if ((q == '<' and w == '>' and e == '>') or (q == '>' and w == '<' and e == '<')) cout << 'A';
}
