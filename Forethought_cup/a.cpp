#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	ll sz = (int)s.size();
	int i = 0, ct = 0;
	while(s[i] == 'a'){
		ct++;
		i++;
	}
	while(sz && ct * 2 <= sz){
		char ch  = s.back();
		sz--;
		if(ch == 'a') ct--;
	}
	cout << sz;
	
	return 0;
}

