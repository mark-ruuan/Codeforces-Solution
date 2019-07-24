#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

deque<ll> dq;
std::vector<char> ans;
int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		dq.push_back(x);
	}
	if(n == 1){
		cout << 1 << "\n";
		cout << "L";
		return 0;
	}
	ll prev = 0, flag = 0;
	while(dq.size() > 1){
		ll L = dq.front();
		ll R = dq.back();
		if(L < R){
			if(prev < L){
				ans.push_back('L');
				dq.pop_front();
				prev = L;
			}
			else if(prev < R){
				ans.push_back('R');
				dq.pop_back();
				prev = R;
			}
			else{
				flag = 1;
				break;
			}
		}
		else if(R < L){
			if(prev < R){
				ans.push_back('R');
				dq.pop_back();
				prev = R;
			}
			else if(prev < L){
				ans.push_back('L');
				dq.pop_front();
				prev = L;
			}
			else {
				flag = 1;
				break;
			}
		}
	}
	if(flag == 0){
		if(dq.front() > prev){
			if(ans[ans.size() - 1] == 'L') ans.push_back('R');
			else ans.push_back('L');
		}
	}
	cout << (int)ans.size() << "\n";
	for(auto i: ans) cout << i;	
	
	return 0;
}

