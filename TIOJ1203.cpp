#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
    while (cin>>n>>m>>k) {
		int tmp=0;
		for(int i=n-k+1;i<=n;i++)tmp=(tmp+m)%i;
		cout<<tmp+1<<"\n";
	}
}
