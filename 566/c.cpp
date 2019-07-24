#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;



pair<pair<int, int>, pair<int, int> > ans[N];
string s[N];
map<pair<int, char>, vector<int> > mp;
std::vector<int> st[N];
bool isvowel(char ch){
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(){
	fast;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		char lst;
		int ct = 0;
		for(auto j: s[i]){
			if(isvowel(j)){
				ct++;
				lst = j;
			}
		}
		mp[{ct, lst}].push_back(i);
	}	
	int at = 0;
	//cout << mp.size() << "\n";
	for(auto i: mp){
		if(i.second.size() % 2){
			st[i.first.first].push_back(i.second.back());
			i.second.pop_back();
		}
		while(i.second.size()){
			ll fs = i.second.back();
			i.second.pop_back();
			ll ss = i.second.back();
			i.second.pop_back();
			ans[at].second.first = fs;
			ans[at++].second.second = ss;
		}
	}
	int en = at - 1;
	at = 0;
	for(int i = 1; i <= 1e6; i++){
		while(st[i].size() >= 2){
			ll fs = st[i].back();
			st[i].pop_back();
			ll ss = st[i].back();
			st[i].pop_back();
			ans[at].first.first = fs;
			ans[at++].first.second =  ss;
		}
	}
	ll lst = min(at - 1, en);
	for(int i = at; i < en; i++, en--){
		ans[i].first = ans[en].second;
		lst = i;
	}
	cout << lst + 1 << "\n";
	for(int i = 0; i <= lst; i++){
		cout << s[ans[i].first.first] << " " << s[ans[i].second.first] << "\n";
		cout << s[ans[i].first.second] << " " << s[ans[i].second.second] << "\n";
	}
	
	return 0;
}

