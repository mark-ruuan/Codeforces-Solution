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

map<pair<int, int>, set<int> > mp;
int a[N], b[N];
int main(){
	fast;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++){
			int aa = b[i] - b[j];
			int bb = a[j] - a[i];
			int cc = a[i] * b[j] - a[j] * b[i];
			int gg = __gcd((aa), __gcd((bb), (cc)));			
			if(gg == 0) gg = 1;
			aa /= gg; bb /= gg; cc /= gg;
			if(aa < 0){
				aa *= -1;
				bb *= -1;
				cc *= -1;
			}
			mp[{aa, bb}].insert(cc);
		}
	int ans = 0, sz = 0;
	for(auto i: mp){
		int x = i.second.size();
		ans -= 1LL * x * (x - 1) / 2;
		sz += x;
	}
	cout << 1LL * sz * (sz - 1) / 2 + ans;
	return 0;
}

