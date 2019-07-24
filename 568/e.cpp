#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

multiset<ll> mst;
set<ll> st;
ll a[N];
std::vector<pair<ll, ll> > v;
int main(){
	fast;
	ll n;
	cin >> n;
	if(n <= 3) return cout << 1, 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		v.push_back({a[i], i});
	}
	sort(v.begin(), v.end());
	for(int i = 1; i < n; i++){
		mst.insert(v[i].first - v[i - 1].first);
		st.insert(v[i].first - v[i - 1].first);
	}
	/*cout << st.size() << "\n";
	cout << mst.size() << "\n";*/
	for(int i = 0; i < n; i++){
		if(i == 0){
			ll diff = v[i + 1].first - v[i].first;
			mst.erase(mst.find(diff));
			if(mst.find(diff) == mst.end()) st.erase(st.find(diff));
			if(st.size() == 1) return cout << v[i].second, 0;
			mst.insert(diff);
			st.insert(diff);
		}
		else if(i != n - 1){
			ll diff = v[i + 1].first - v[i].first;
			mst.erase(mst.find(diff));
			if(mst.find(diff) == mst.end()) st.erase(st.find(diff));
			ll diff1 = v[i].first - v[i - 1].first;
			mst.erase(mst.find(diff1));
			if(mst.find(diff1) == mst.end()) st.erase(st.find(diff1));
			ll diff3 = v[i + 1].first - v[i - 1].first;
			mst.insert(diff3);
			st.insert(diff3);
			if(st.size() == 1) return cout << v[i].second, 0;
			mst.erase(mst.find(diff3));
			if(mst.find(diff3) == mst.end()) st.erase(st.find(diff3));
			mst.insert(diff);
			mst.insert(diff1);
			st.insert(diff);
			st.insert(diff1);
		}
		else{
			ll diff1 = v[i].first - v[i - 1].first;
			mst.erase(mst.find(diff1));
			if(mst.find(diff1) == mst.end()) st.erase(st.find(diff1));
			if(st.size() == 1) return cout << v[i].second, 0;
			mst.insert(diff1);
			st.insert(diff1);
		}
	}
	cout << -1;

	
	return 0;
}

