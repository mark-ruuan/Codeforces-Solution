#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll int
#define ld long double
using namespace std;
const int N = 150000 + 5;
const int MOD = 1e9 + 7;

std::vector<pair<ll,ll> > ans;
stack<ll> pos[N], pos1[N], rem, rem1;
int main(){
	fast;
	ll n, ct = 0, ct1 = 0;
	cin >> n;
	string s, ss;
	cin >> s >> ss;
	for(int i = 0; i < n; i++){
		if(s[i] != '?')
			pos[s[i] - 'a'].push(i + 1);
		else
			rem.push(i + 1);
		if(ss[i] != '?')
			pos1[ss[i] - 'a'].push(i + 1);
		else 
			rem1.push(i + 1);

	}
	for(int i = 0; i < 26; i++){
		while(!pos[i].empty() && !pos1[i].empty()){
			ans.push_back({pos[i].top(), pos1[i].top()});
			pos[i].pop();
			pos1[i].pop();
		}
	}
	for(int i = 0; i < 26; i++){
		while(!pos[i].empty() && !rem1.empty()){
			ans.push_back({pos[i].top(), rem1.top()});
			pos[i].pop();
			rem1.pop();
		}
		while(!pos1[i].empty() && !rem.empty()){ 	 	
			ans.push_back({rem.top(), pos1[i].top()});
			pos1[i].pop();
			rem.pop();
		}
	}
	while(!rem.empty() && !rem1.empty()){
		ans.push_back({rem.top(), rem1.top()});
		rem.pop();
		rem1.pop();
	}
	cout << (int)ans.size() << "\n";
	for(auto i: ans){
		cout << i.first << " " << i.second << "\n";
	}
	return 0;
}

