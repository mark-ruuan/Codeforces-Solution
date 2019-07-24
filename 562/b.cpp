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
int n, m;
bool visit[N];
std::vector<pair<int, int> > v;
void check(int x){
	for(int i = 1; i < m; i++){
		if(!visit[i]){
			if((v[i].first == x) || v[i].second == x){
				visit[i] = 1;
			}
		}
	}
}

int main(){
	fast;
	//cout << "yo" << endl;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		if(x > y) swap(x, y);
		v.push_back({x, y});
	}
	check(v[0].first);
	bool flag = 0;
	//cout << "yo" << endl;
	for(int i = 1; i < m; i++){
		//cout << "yo" << endl;
		if(!visit[i]){
			check(v[i].first);
			for(int j = 1; j < m; j++){
				if(!visit[j]){
					flag = 1;
					break;
				}
			}
			//cout << "yo" << endl;
			if(flag == 0) return cout << "YES", 0;
			memset(visit, 0, sizeof visit);
			check(v[0].first);
			check(v[i].second);
			flag = 0;
			for(int j = 1; j < m; j++){
				if(!visit[j]){
					flag = 1;
					break;
				}
			}
			if(flag == 0) return cout << "YES", 0;
			break;
		}
	}
	//cout << "yo" << endl;
	if(flag == 0) return cout << "YES", 0;
	memset(visit, 0, sizeof visit);
	check(v[0].second);
	flag = 0;
	for(int i = 1; i < m; i++){
		if(!visit[i]){
			check(v[i].first);
			for(int j = 1; j < m; j++){
				if(!visit[j]){
					flag = 1;
					break;
				}
			}
			if(flag == 0) return cout << "YES", 0;
			memset(visit, 0, sizeof visit);
			check(v[0].second);
			check(v[i].second);
			flag = 0;
			for(int j = 1; j < m; j++){
				if(!visit[j]){
					flag = 1;
					break;
				}
			}
			if(flag == 0) return cout << "YES", 0;
			break;
		}
	}
	if(flag == 0) return cout << "YES", 0;
	cout << "NO";
	return 0;
}

