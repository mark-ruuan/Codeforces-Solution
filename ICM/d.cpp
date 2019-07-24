#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

ll h[N];

ll tree[4 * N];
ll lazy[4 * N];



void  update(ll node, ll st, ll end, ll l, ll r, ll val){
	if(lazy[node] != 0){
		tree[node] =  lazy[node];
		if(st != end){
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
	if(st > end || st > r || end < l) return;
	if(st >= l && end <= r){
		tree[node] = val;
		if(st != end){
			lazy[node * 2] = val;
			lazy[node * 2 + 1] = val;
		}
		return;
	}
	ll mid = (st + end) >> 1;
	update(node * 2, st, mid, l, r, val);
	update(node * 2 + 1, mid + 1, end, l, r, val);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

ll querry(ll node, ll st, ll end, ll l, ll r){
	if(st > end || l > r || st > r || end < l) return 0;
	if(lazy[node] != 0){
		tree[node] = lazy[node];
		if(st != end){
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
	if(l <= st && end <= r) return tree[node];
	ll mid = (st + end) >> 1;
	ll t = querry(node * 2, st, mid, l, r);
	ll tt = querry(node * 2 + 1, mid + 1, end, l, r);
	return max(t, tt);
}


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		memset(tree, 0, sizeof tree);
		memset(lazy, 0, sizeof lazy);
		ll n, q;
		cin >> n >> q;
		while(q--){
			ll type, x, y;
			cin >> type >> x >> y;
			if(type == 1){
				ll mx = 0;
				mx = querry(1, 1, n, x, min(n, x + y));
				//cerr << mx << "\n";
				update(1, 1, n, x, min(n, x + y), mx + y);
				//cerr << "\n";

			}
			else{
				ll mx = 0;
				mx = querry(1, 1, n, x, y);
				//cerr << "\n";
				cout << mx  << "\n";
			}
		}
	}
	
	return 0;
}

