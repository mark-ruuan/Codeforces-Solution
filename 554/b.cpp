#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<ll> ans;
int main(){
	fast;
	ll n, flag, ct = 0;
	cin >> n;
	ll x = n;
	for(int i = 40; i >= 0; i--){
		if(n & (1LL << i)){
			flag = i;
			break;
		}
	}
	while(1){
		ll t = -1;
		for(int i = flag; i >= 0; i--){
			if(x & (1LL << i)){
				continue;
			}
			else{
				t = i;
				break;
			}
		}
		if(t == -1){
			break;
		}
		ans.push_back(t + 1);
		x ^= ((1LL << (t + 1)) - 1);
		ct++;
		t = -1;
		for(int i = flag; i >= 0; i--){
			if(x & (1LL << i)){
				continue;
			}
			else{
				t = i;
				break;
			}
		}
		if(t== -1) break;
		x = x + 1;
		ct++;
	}
	cout << ct << "\n";
	for(auto i: ans) cout << i << " ";
	
	return 0;
}
