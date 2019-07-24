#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++){
		std::vector<pair<char, ll> > v, vv;
		bool flag = 0;
		string s, ss;
		cin >> s >> ss;
		for(int j = 0; j < (int)s.size(); j++){
			char ch = s[j];
			ll cur = j;
			while(cur < (int)s.size() && s[cur] == ch) cur++;
			v.push_back({ch, cur - j});
			j = cur - 1;
		}
		//cout << "yo" << endl;
		for(int j = 0; j < (int)ss.size(); j++){
			char ch = ss[j];
			int cur = j;
			while(cur < (int)ss.size() && ss[cur] == ch) cur++;
			vv.push_back({ch, cur - j});
			j = cur - 1;
		}
		//cout << "yo" << endl;
		if(v.size() == vv.size())
			for(int j = 0; j < (int)v.size(); j++){
				if(v[j].first != vv[j].first || v[j].second > vv[j].second){
					flag = 1;
					break;
				}
			}
		else flag = 1;
		if(flag) cout << "NO\n";
		else cout << "YES\n";
	}
	
	return 0;
}

