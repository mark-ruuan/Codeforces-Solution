#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		char a[n][m];
		std::vector<int> v, vv;
		for(int i = 0; i < n; i++){
			int ct = 0;
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
				if(a[i][j] == '*') ct++;
			}
			v.push_back(m - ct);
		}
		for(int i = 0; i < m; i++){
			int ct = 0;
			for(int j = 0; j < n; j++){
				if(a[j][i] == '*') ct++;
			}
			vv.push_back(n - ct);
		}
		int out = 1e8;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == '*') out = min(out, v[i] + vv[j]);
				else out = min(out, v[i] + vv[j] - 1);
			}
		}
		cout << out << "\n";
	}
	
	
	return 0;
}
