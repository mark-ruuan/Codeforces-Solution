#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<pair<ll, ll> > v[N], vv;
ll n, m, p;
ll flag[N], mp[N], ctt[N];
ll dp[100][100];
ll go(ll idx, ll ct, ll cost){
    if(flag[idx] && flag[idx] == ct){
        cost -= ctt[mp[idx]];
    }
    if(cost > p || idx == (int)vv.size()){
        return 0;
    }
    //if(dp[idx][ct] != -1) return dp[idx][ct];
    ll aa = 0;
    aa = max(aa, go(idx + 1, (flag[idx]) ? 0 : ct, cost));
    if(cost + vv[idx].first <= p)
        aa = max(aa, vv[idx].second + go(idx + 1, (flag[idx]) ? 1 : ct + 1, cost + vv[idx].first));
    //return dp[idx][ct] = aa;
    return aa;
}
int main(){
    fast;   
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++){
        ll type, x, y;
        cin >> type >> x >> y;
        v[type].push_back({x, y}); 
    }
    for(int i = 1; i <= m; i++){
        ll sum = 0;
        for(auto j: v[i]){
            vv.push_back(j);
            mp[(int)vv.size()] = i;
            sum += j.first;
        }
        ctt[i] = sum;
        flag[(int)vv.size()] = (int)v[i].size();
    }
    for(int i = 1; i <= m; i++){
        ll x;
        cin >> x;
        if(ctt[i] < x) ctt[i] = 0;
        else ctt[i] = ctt[i] - x;
    }
    memset(dp, -1, sizeof dp);
    cout << go(0, 0, 0);
    
    return 0;
}

