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

stack<ll> st;
int main(){
	fast;
	ll n, mul = 1;
	cin >> n;
	ll ans = 0,  big = (1LL << 32) - 1, ct = 0;
	for(int i = 0; i < n; i++){
		string x;
		cin >> x;
		if(x == "add"){
			if(st.empty())
				ans++;
			else{
				if(ct) return cout << "OVERFLOW!!!", 0;
				ans += mul;
			}
		}
		else if(x == "for"){
			ll y;
			cin >> y;
			if(mul * y > big) ct++;
			else{
				mul *= y;
			}
			st.push(y);
		}
		else{
			if(ct == 0)
				mul /= st.top();
			else 
				ct--;
			st.pop();
		}
		//cout << mul << " " << ans << "\n";
		if(ans > big) return cout << "OVERFLOW!!!", 0;
	}
	cout << ans;
	
	return 0;
}

