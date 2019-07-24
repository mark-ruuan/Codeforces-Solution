#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll mx;

vector<ll> convert(ll x){
	std::vector<ll> v;
	while(x){
		v.push_back(x % 2);
		x /= 2;
	}
	reverse(v.begin(), v.end());
	return v;
}

std::vector<ll> check(vector<ll> v){
	if(v.size() == mx) return v;
	reverse(v.begin(), v.end());
	while(v.size() != mx){
		v.push_back(0);
	}
	reverse(v.begin(), v.end());
	return v;
}

void print(vector<ll> v){
	for(auto i: v) cerr << i;
	cerr<<"\n";
}
int main(){
	fast;
	ll x, y, z;
	cin >> x >> y >> z;
	vector<ll> xx, yy, zz;
	xx = convert(x);
	yy = convert(y);
	zz = convert(z);
	mx = max(xx.size(), max(yy.size(), zz.size()));
	xx = check(xx);
	yy = check(yy);
	zz = check(zz);
	//swap(yy, zz);
	vector<ll> ans, ans1;
	for(int i = 0; i < (int)xx.size(); i++){
		//cout << xx[i] << " " << yy[i] << " " << zz[i] << "\n";
		if(xx[i] == 1){
			//cerr << "yo\n";
			if(zz[i] == 1 && yy[i] == 0){
				//cerr << i << "\n";
				ans.push_back(1);
				ans1.push_back(1);
			}
			else if(zz[i] == 0 && yy[i] == 1){
				ans.push_back(1);
				ans1.push_back(0);
			}
			else return cout << -1, 0;
		}
		else{
			if(zz[i] == 0 && yy[i] == 0){
				ans.push_back(0);
				ans1.push_back(0);
			}
			else return cout << -1, 0;
		}
	}
	ll out = 0, out1 = 0;
	reverse(ans.begin(), ans.end());
	reverse(ans1.begin(), ans1.end());
	for(int i = 0, ct = 0; i < (int)ans.size(); i++, ct++){
		out |= (1LL << ct) * ans[i];
		out1 |= (1LL << ct) * ans1[i];
	}
	cout << out << " " << out1;
	//cerr << (out|out1) << " " << (out^out1) << " " << (out&out1);


	
	return 0;
}

