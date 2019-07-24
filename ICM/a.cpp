#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

vector<ll> convert(string a){
	std::vector<ll> v;
	for(auto i: a){
		v.push_back(i - '0');
	}
	return v;
}

ll get(vector<ll> v){
	ll no = 0;
	for(auto i: v){
		no = no * 10 + i;
	}
	return no;
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
	    ll ff;
	    cin >> ff;
		string a, b, c;
		cin >> a >> b >> c;
		vector<ll> aa, bb, cc;
		aa = convert(a);
		sort(aa.begin(), aa.end());
		bb = convert(b);
		sort(bb.begin(), bb.end());
		cc = convert(c);
		ll pro = get(cc);
		//cerr << pro << "\n";
		bool flag = 0;
		do{
			ll cur = get(aa);
			ll nw = pro - cur;
			//cerr << nw << " " << cur << "\n";
			if(nw < 0) continue;
			string now = to_string(nw);
			vector<ll> temp = convert(now);
			sort(temp.begin(), temp.end());
			if(temp == bb){
				flag = 1;
				break;
			}
		}while(next_permutation(aa.begin(), aa.end()));
		if(flag) cout << "YES\n";
		else cout << "NO\n";

	}
	
	return 0;
}

