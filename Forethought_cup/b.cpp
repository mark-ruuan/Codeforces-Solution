#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	string s, t, tt;
	ll flag = -1;
	cin >> s;
	for(int i = (int)s.size() - 1; i >= 0; i--){
		if(s[i] != 'a' && flag == -1){
			t += s[i];
		}
		else if(s[i] == 'a' && flag == -1){
			flag = i;
			break;
		}
	}
	reverse(t.begin(), t.end());
	if(flag == -1){
		if((int)s.size() & 1) return cout << ":(", 0;
		for(int i = 0, j = (int)s.size() / 2; i < (int)s.size() / 2; i++, j++){
			if(s[i] != s[j]) return cout << ":(", 0;
		}
		for(int i = 0; i < (int)s.size() / 2; i++) cout << s[i];
		return 0;
	}
	for(int i = 0; i < flag; i++){
		if(s[i] != 'a') tt += s[i];
	}
	if(tt.size() < t.size()){
		reverse(t.begin(), t.end());
		while(tt.size() < t.size()){
			tt += t.back();
			t.pop_back();
			flag++;
		}
		reverse(t.begin(), t.end());
	}
	if(tt != t) return cout << ":(", 0;
	for(int i = 0; i <= flag; i++) cout << s[i];
	
	
	return 0;
}

