/*
I got a long way to go
		And a long memory
I've been searching for an answer
		Always just out of reach!!!!
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool check(string t){
	for(int i = 1; i < (int)t.size(); i++)
		if(abs(t[i] - t[i - 1]) == 1) return 0;
	return 1;
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		string s, s1, s2;
		ll h[27] = {0};
		cin >> s;
		for(int i = 0; i < (int)s.size(); i++) h[s[i] - 'a']++;
		for(int i = 0; i < 26; i += 2){
			while(h[i]--) s1 += (char)('a' + i);
		}
		for(int i = 1; i < 26; i += 2){
			while(h[i]--) s2 += (char)('a' + i);
		}
		if(check(s1 + s2)) cout << s1 << s2;
		else if(check(s2 + s1)) cout << s2 << s1;
		else cout << "No answer";
		cout << "\n";	

	}
	
	return 0;
}

