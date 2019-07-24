/*
    __                      _    _            __                 __
   / /_/\__        __ _    | | _| | __     _  \ \       __/\__  / /
  / /\    /       / _` |   | |/ / |/ /    (_)  | |      \    / / / 
 / / /_  _\      | (_| |   |   <|   <      _   | |      /_  _\/ /  
/_/    \/         \__,_|___|_|\_\_|\_\    (_)  | |        \/ /_/   
                      |_____|                 /_/                  

*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N];
std::vector<ll> v;
ll n, k, A, B;
ll go(ll st, ll end){
	ll ans = 0;
	ll len = end - st + 1;
	ll ct1 = lower_bound(v.begin(), v.end(), st) - v.begin();
	ll ct2 = upper_bound(v.begin(), v.end(), end) - v.begin();
	ans = ct2 - ct1;
	if(ans == 0)return A;
	else ans = ans * B * len;
	if(st == end) return ans;
	ll ans1 = 0;
	ans1 += go(st, st + (len / 2) - 1);
	ans1 += go(st + (len / 2), end);
	return min(ans, ans1);
}

int main(){
	fast;
	cin >> n >> k >> A >> B;
	for(int i = 0; i < k; i++){
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	cout << go(1, (1LL << n));
	
	
	return 0;
}