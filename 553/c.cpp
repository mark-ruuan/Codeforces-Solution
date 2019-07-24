#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll unsigned long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll sumgp

int main(){
	fast;
	ll l, r;
	cin >> l >> r;
	ll lo = -1, hi = 63, ok = 1;
	while(hi - lo > 1){
		ll mid = (hi + lo) >> 1LL;
		ll sum = ((ok << (mid + 1)) - 1);
		if(sum >= l) hi = mid;
		else lo = mid;
	}
	ll st = hi;
	lo = -1, hi = 63, ok = 1;
	while(hi - lo > 1){
		ll mid = (hi + lo) >> 1LL;
		ll sum = ((ok << (mid + 1)) - 1);
		if(sum >= r) hi = mid;
		else lo = mid;
	}
	ll en = hi;
	if(st % 2 == 0){
		ll prev = (st != 0) ? (okk << st - 1) : 0;
		ll rem = l - prev;
		ll st = 1;
		ll ct = 0;
		for(int i = 0; i < st; i += 2){
			ct += (st);
			st *= 4;
		}
		ct += rem;
		stodd = 1 + (rem - 1) * 2;
		st = 2;
		for(int i = 1; i < st; i += 2){
			ct += st;
			st *= 4;
		}
		steve = 2 + (ct) * 2;
	}
 	
	return 0;
}

