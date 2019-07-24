#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template<typename T, typename V = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, V, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

ll h[N], ok[N], endd[N], pos[N], ans[N];
std::vector<ll> a[N], sz;
std::vector<pair<ll, ll> > vv,query;



int main(){
	fast;
	ll n, m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		h[x]++;
	}
	for(int i = 1;i <= m; i++){
		a[h[i]].push_back(i);
		if(!ok[h[i]])
			sz.push_back(h[i]), ok[h[i]] = 1;
	}
	for(int i = 0; i <= n; i++){
		if(i != 0) endd[i] = endd[i - 1];
		endd[i] += a[i].size();
	}
	sort(sz.begin(), sz.end());
	ll prev = n, tot = 0;
	for(int i = 0; i < (int)sz.size() - 1; i++){
		ll diff = sz[i + 1] - sz[i];
		ll range = endd[sz[i]] * diff; 
		vv.push_back({prev + range, sz[i]});
		prev += range;
	}
	vv.push_back({1e18 + 5, sz[(int)sz.size() - 1]});
	for(int i = 0; i < q; i++){
		ll xx;
		cin >> xx;
		ll lo = -1, hi = (int)vv.size();
		while(hi - lo > 1){
			ll mid = lo + (hi - lo) / 2;
			if(vv[mid].first >= xx) hi = mid;
			else lo = mid;
		}
		ll prev = (hi - 1 >= 0) ? vv[hi - 1].first : n;
		ll length = xx - prev;
		pos[i] = length % endd[vv[hi].second];
		if(pos[i] == 0) pos[i] = endd[vv[hi].second];
		pos[i]--;
		query.push_back({vv[hi].second, i});
	}
	sort(query.begin(), query.end());
	ll pt = -1;
	ordered_set<ll> os;
	for(int i = 0; i < query.size(); i++){
		ll cur = query[i].first;
		while(pt < cur){
			pt++;
			for(auto j: a[pt]) os.insert(j);
			
		}
		ans[query[i].second] = *os.find_by_order(pos[query[i].second]);
	}
	for(int i = 0; i < query.size(); i++)
		cout << ans[i] << "\n";
	return 0;
}

