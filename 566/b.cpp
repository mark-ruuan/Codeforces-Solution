#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 500 + 5;
const int MOD = 1e9 + 7;

char a[N][N];
int main(){
	fast;
	ll h, w;
	cin >> h >> w;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++) cin >> a[i][j];
	}
	int flag = 0;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			flag = 0;
			for(int k = i - 1; k <= i + 1; k++){
				if(a[k][j] != '*') flag = 1;
			}
			for(int k = j - 1; k <= j + 1; k++){
				if(a[i][k] != '*') flag = 1;
			}
			if(flag == 0){
				a[i][j] = '.';
				int k = i - 1;
				while(a[k][j] == '*'){
					a[k][j] = '.';
					k--;
				}
				 k = i + 1;
				while(a[k][j] == '*'){
					a[k][j] = '.';
					k++;
				}
				 k = j - 1;
				while(a[i][k] == '*'){
					a[i][k] = '.';
					k--;
				}
				k = j + 1;
				while(a[i][k] == '*'){
					a[i][k] = '.';
					k++;
				}
				break;
			}
		}
		if(flag == 0) break;
	}
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++) if(a[i][j] == '*') return cout << "NO", 0;
	if(flag == 0) cout << "YES";
	else cout << "NO";
	
	
	return 0;
}

