#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		string s;
		cin >> s;
		if(s[0] == '>') cout << 0 << "\n";
		else if(s[n - 1] == '<') cout << 0 << "\n";
		else{
			ll ct = 0, ct1 = 0; 
			for(int i = 0; i < n; i++){
				if(s[i] != '>') ct++;
				else break;
			}
			for(int i = n - 1; i >= 0; i--){
				if(s[i] != '<') ct1++;
				else break;
			}
			cout << min(ct, ct1) << "\n";
		}
	}
	
	
	return 0;
}

