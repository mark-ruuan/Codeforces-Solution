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


int main(){
	fast;
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = n - 1, ct = 0; i >= 0; i--, ct++){
		if(ct < y && s[i] != '0') ans++;
		else if(ct == y && s[i] == '0') ans++;
		else if(ct > y && ct < x && s[i] == '1') ans++;
		//cout << i << " " << s[i] <<  " " << ct << " " << ans << endl;
	}
	cout << ans;
	
	return 0;
}

