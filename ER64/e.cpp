/*
I got a long way to go
		And a long memory
I've been searching for an answer
		Always just out of reach!!!!
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

stack<ll> st;
ll a[N], pos[N], nxtg[N], prevg[N];

int main(){
	fast;
	ll n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	st.push(1);
	for(int i = 2; i <= n; i++){
		if(st.empty()){
			st.push(i);
			continue;
		}
		while(!st.empty() && a[st.top()] < a[i]){
			nxtg[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		nxtg[st.top()] = -1;
		st.pop();
	}
	st.push(n);
	for(int i = n - 1; i > 0; i--){
		if(st.empty()){
			st.push(i);
			continue;
		}
		while(!st.empty() && a[st.top()] < a[i]){
			prevg[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		prevg[st.top()] = -1;
		st.pop();
	}
	for(int i = 1; i <= n; i++){
		ll curmax = a[i];
		ll rl = prevg[i], rr = nxtg[i];
		if(rl == -1) rl = 0;
		if(rr == -1) rr = n + 1;
		if(abs(rl - i) <= abs(rr - i)){
			for(int j = rl + 1; j < i; j++){
				if(pos[curmax - a[j]] > i && pos[curmax - a[j]] < rr) ans++;
			}
		}
		else{
			for(int j = i + 1; j < rr; j++){
				if(pos[curmax - a[j]] > rl && pos[curmax - a[j]] < i) ans++;
			}
		}
	}
	cout << ans;

	
	return 0;
}
