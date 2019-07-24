#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		string s, t, p;
		cin >> s >> t >> p;
		int h[26] = {0};
		bool flag = 0;
		for(int i = 0; i < t.size(); i++)
			h[t[i] - 'a']++;
		for(int i = 0; i < s.size(); i++){
			if(h[s[i] - 'a']){
				h[s[i] - 'a']--;
			}
			else{
				flag = 1;
				 break;
			}
		}
		if(flag == 1){
			cout << "NO\n";
			continue;
		}
		for(int i = 0; i < p.size(); i++){
			if(h[p[i] - 'a']){
				h[p[i] - 'a']--;
			}
		}
		for(int i = 0; i < 26; i++)
			if(h[i]) flag = 1;
		if(flag == 0){
			int pt = 0;
			for(int i = 0; i < s.size(); i++){
				while(pt < t.size() && t[pt] != s[i]) pt++;
				if(pt == t.size()){
					flag = 1;
					break;
				}
				pt++;
			}
		}
		if(flag) cout << "NO\n";
		else cout << "YES\n";
	}
	
	return 0;
}
