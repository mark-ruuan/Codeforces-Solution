#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) { 
    return (a.second < b.second); 
} 


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		vector<pair<ll, ll> > v[27], vv;
		bool dir[27] = {0};
		ll n, m;
		string ans = "YES";
		cin >> n >> m;
		//cout << "yo" << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				//cout << "yo" << endl;
				char ch;
				cin >> ch;
				if(ch != '.')
				v[ch - 'a'].push_back({i, j});
			}
		}
		//cout << "yo" << endl;
		for(int i = 0; i < 26; i++){
			//cout << "yo" << endl;
			if(v[i].size() == 0) continue;
			bool flag = 0;
			for(int j = 1; j < (int)v[i].size(); j++){
				if(v[i][j].first != v[i][j - 1].first){
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				sort(v[i].begin(), v[i].end());
				continue;
			}
			flag = 0;
			for(int j = 1; j < (int)v[i].size(); j++){
				//cout << v[i][j - 1].second << " " << v[i][j].second << endl;
				if(v[i][j].second != v[i][j - 1].second){
					flag = 1;
					break;
				}
			}
			if(flag == 1){
				ans = "NO";
				cout << i << "\n";
				break;
			}
			dir[i] = 1;
			sort(v[i].begin(), v[i].end(), cmp);
		}
		if(ans == "NO"){
			cout << ans << "\n";
			continue;
		}
		ll out = 0;
		for(int i = 0; i < 26; i++){
			if(v[i].size() == 0) continue;
			out++;
			ll ct = 0;
			if(dir[i] == 0){
				for(int j = 1; j < (int)v[i].size(); j++)
					ct += v[i][j].second - v[i][j - 1].second - 1;
			}
			else{
				for(int j = 1; j < (int)v[i].size(); j++)
					ct += v[i][j].first - v[i][j - 1].first- 1;
			}
			vv.push_back({ct, i});
		}
		sort(vv.rbegin(), vv.rend());
		cout << ans << "\n";
		cout << out << "\n";
		for(int i = 0; i < vv.size(); i++){
			ll idx = vv[i].second;
			ll sz = v[idx].size() - 1;
			cout << v[idx][0].first + 1 << " " << v[idx][0].second + 1 << " " << v[idx][sz].first + 1 << " " << v[idx][sz].second + 1 << "\n";
		}

	}
	//cout << "yo" << endl;
	return 0;
}

