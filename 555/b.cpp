#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[20];
int main(){
	fast;
	ll n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 1; i <= 9; i++){
		cin >> a[i];
	}
	ll flag = 0;
	for(int i = 0; i < n; ++i){
		//cout << s[i] - '0' << " " << a[s[i] - '0'] << "\n";
		if(a[s[i] - '0'] > (s[i] - '0')){
			if(flag == 0) flag = 1;
			if(flag == 1){
				s[i] = a[s[i] - '0']  + '0';
			}
		}
		else if(a[s[i] - '0'] == (s[i] - '0')){
			if(flag == 1) flag = 1;
		}
		else if(flag == 1){
			flag = 2;
		}
		//cout << s[i] << "\n";
	}
	cout << s;
	
	return 0;
}

