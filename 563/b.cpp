/*
Yea, those will be the days that I will be missing
	When I’m old and when I’m gray and when I stop working
I hope that I can say
	When all my days are done
That I had my fun!!!!!!!
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int a[N];
int main(){
	fast;
	int n, odd = 0, even = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] & 1) odd = 1;
		else even = 1;
	}
	if(odd && even)
		sort(a, a + n);
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	
	return 0;
}

