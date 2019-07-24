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

set<ll> st;
multiset<ll> stt;
ll h[N];
int main(){
	fast;
	ll n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		ll x;
		cin >> x;
		h[x]++;
		if(stt.find(h[x] - 1) != stt.end()){
			stt.erase(stt.find(h[x] - 1));
			if(stt.find(h[x] - 1) == stt.end()){
				st.erase(st.find(h[x] - 1));
			}
		}
		stt.insert(h[x]);
		st.insert(h[x]);
		if(stt.size() <= 1) ans = i;
		if(st.size() == 2){
			ll x = *st.begin();
			ll y = *(++st.begin());
			//cout <<  i << " " << y << " " << x << endl;
			if(y - x == 1 || x == 1){
				auto it = stt.begin();
				it++;
				if(*it != x && x == 1){
					ans = i;
				}
				it = stt.end();
				it--;
				if(*it == y && y - x == 1){
					it--;
					if(*it == x) ans = i;
				}
				//cout << ans << endl;
			}
		}
		if(st.size() == 1 && *st.begin() == 1) ans = i;
	}
	cout << ans;
	return 0;
}

