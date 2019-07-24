#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N];
deque<ll> dq;
vector<ll> v;

int main(){
	fast;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	dq.push_back(a[n - 1]);
	int xr = 0;
	for(int j = n - 2; j >= 0; j--){
		if(xr == 0) dq.push_front(a[j]);
		else dq.push_back(a[j]);
		xr ^= 1;
	}
	while(!dq.empty()){
		v.push_back(dq.front());
		dq.pop_front();
	}
	for(int i = 0; i < n; i++){
		if(i == 0){
			if(v[i + 1] + v[n - 1] <= v[i]) return cout << "NO\n", 0;
		}
		else if(i == n - 1){
			if(v[i - 1] + v[0] <= v[i]) return cout << "NO\n", 0;
		}
		else if(v[i - 1] + v[i + 1] <= v[i]) return cout << "NO\n", 0;
	}
	cout << "YES\n";
	for(auto i: v) cout << i << " ";
	return 0;
}
