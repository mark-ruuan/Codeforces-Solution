#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<string> v;
ll n;
string s;
string go(ll pos){
	//cout << pos << " ";
	string ans;
	ll en = pos - 1, i;
	ll carry = 0;
	for(i = n - 1; i >= pos && en >= 0; i--, en--){
		ll x = s[i] - '0';
		ll y = s[en] - '0';
		ll res = x + y + carry;
		ans += (res % 10) + '0';
		carry = res / 10;
	}
	//cout << ans << " ";
	if(en >= 0){
		for(int j = en; j >= 0; j--){
			int x = s[j] - '0';
			int res = x + carry;
			ans += (res % 10) + '0';
			carry = res / 10;
		}
		
	}
	else if(i >= pos){
		for(int j = i; j >= pos; j--){
			int x = s[j] - '0';
			int res = x + carry;
			ans += (res % 10) + '0';
			carry = res / 10;
		}
	}
	if(carry) ans += carry + '0';
	reverse(ans.begin(), ans.end());
	return ans;
}

void calc(ll pos){
	if(s[pos] == '0'){
		ll orgpos = pos;
		while(pos < n && s[pos] == '0') pos++;
		if(pos != n)
			v.push_back(go(pos));
		pos = orgpos;
		while(pos >= 0 && s[pos] == '0') pos--;
		if(pos != -1)
			v.push_back(go(pos));
	}
	else v.push_back(go(pos));
}

int main(){
	fast;
	cin >> n;
	cin >> s;
	ll mid = (n + 1) / 2;
	calc(mid);
	if(mid - 1 != -1)
		calc(mid - 1);
	if(mid + 1 != n)
		calc(mid + 1);
	ll mn = 1e8;
	for(auto i: v){
		mn = min(mn, (ll)i.size());
	}
	std::vector<string> vv;
	for(auto i: v){
		if(i.size() == mn) vv.push_back(i);
	}
	sort(vv.begin(), vv.end());
	cout << vv[0];
	
	return 0;
}

