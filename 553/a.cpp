#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll check(string s){
	ll ct = 0;
	ct += min(abs(s[0] - 'A'), 'Z' - s[0] + 1);
	ct += min(abs(s[1] - 'C'), 'Z' - s[1] + 3);
	ct += min(abs(s[2] - 'T'),  s[2] - 'A' + 7);
	ct += min(abs(s[3] - 'G'), 'Z' - s[3] + 7);
	return ct;
}

int main(){
	fast;
	ll n, ans = 1e12;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < n - 3; i++){
		string ss ;
		ss += s[i];
		ss += s[i + 1];
		ss += s[i + 2];
		ss += s[i + 3];
		ans = min(ans, check(ss));
	}
	cout << ans;
	return 0;
}

