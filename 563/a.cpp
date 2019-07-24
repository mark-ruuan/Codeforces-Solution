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
	int n;
	cin >> n;
	for(int i = 0; i < 2 * n; i++) cin >> a[i];
	sort(a, a + 2 * n);
	ll sum = 0, sum1 = 0;
	for(int i = 0; i < n; i++) sum += a[i];
	for(int i = n; i < 2 * n; i++) sum1 += a[i];
	if(sum == sum1) return cout << -1, 0;
	for(int i = 0; i < 2 * n; i++) cout << a[i] << " ";
	
	
	return 0;
}

