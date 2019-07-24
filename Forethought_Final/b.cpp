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

ll a[55][55], b[55][55];
ll mn[55][55], mx[55][55];
int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cin >> a[i][j];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			cin >> b[i][j];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			mn[i][j] = min(a[i][j], b[i][j]);
			mx[i][j] = max(a[i][j], b[i][j]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mn[i][j] <= mn[i][j - 1] || mx[i][j] <= mx[i][j - 1]){
					return cout << "Impossible", 0;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(mn[j][i] <= mn[j - 1][i] || mx[j][i] <= mx[j - 1][i]){
					return cout << "Impossible", 0;
			}
		}
	}
	cout << "Possible";
	
	return 0;
}

