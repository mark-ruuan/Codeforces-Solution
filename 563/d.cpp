/*
Yea, those will be the days that I will be missing
	When I’m old and when I’m gray and when I stop working
I hope that I can say
	When all my days are done
That I had my fun!!!!!!!
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll h[N];
std::vector<ll> ans;
int main(){
	fast;
	ll n, k;
	cin >> n >> k;
	h[0] = 1;
	ll cur = 0;
	while(1){
		bool flag = 0;
		for(int i = 1; i < (1LL << n); i++){
			if(!h[cur ^ i] && !h[cur ^ i ^ k]){
				ans.push_back(i);
				h[cur ^ i] = 1;
				cur ^= i;
				flag = 1;
				break;
			}
		}
		if(!flag) break;
	}
	cout << (int)ans.size() << "\n";
	for(auto i: ans) cout << i << " ";
	
	return 0;
}

