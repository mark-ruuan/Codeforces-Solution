#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool flag = 0;
		map<ll, ll> mp;
		for(int i = 0; i < n; i++){
			string phno;
			cin >> phno;
			ll phno1 = 0;
			for(int j = 0; j < phno.size(); j++){
				phno1 = phno1 * 10 + (phno[j] - '0');
				if(mp[phno1] == 1) flag = 1; 
			}
			mp[phno1] = 1;
		}
		if(flag == 0) cout << "YES\n";
		else cout << "NO\n";
	}

}