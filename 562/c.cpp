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

int a[N], c[N];
int main(){
	fast;
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	if(n == 1) return cout << 0, 0;
	int lo = -1, hi = k + 1, mid;
	while(hi - lo > 1){
		mid = (hi + lo) / 2;
		bool flag = 0;
		for(int i = 0; i < n; i++) c[i] = a[i];
		if(c[n - 1] != k){
			c[n - 1] += mid;
			if(c[n - 1] >= k) c[n - 1] = k - 1;
		}
		for(int i = n - 2; i >= 0; i--){
			if(c[i] < c[i + 1]){
				c[i] += mid;
				if(c[i] > c[i + 1]) c[i] = c[i + 1];
				if(c[i] == c[i + 1] && c[i + 1] == k) c[i] = k - 1; 
			}
			else if(c[i] > c[i + 1]){
				c[i] = min(c[i] + mid) % k;
			}
		}
		for(int i = n - 1; i > 0; i--){
			if(c[i] < c[i - 1]){
				flag = 1;
				break;
			}
		}
		if(flag == 1) lo = mid;
		else hi = mid;
	}
	cout << hi;
	return 0;
}

