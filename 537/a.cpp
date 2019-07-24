 /*
    __                      _    _            __                 __
   / /_/\__        __ _    | | _| | __     _  \ \       __/\__  / /
  / /\    /       / _` |   | |/ / |/ /    (_)  | |      \    / / / 
 / / /_  _\      | (_| |   |   <|   <      _   | |      /_  _\/ /  
/_/    \/         \__,_|___|_|\_\_|\_\    (_)  | |        \/ /_/   
                      |_____|                 /_/                  

*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

string v = "aeiou";
bool is_vowel(char ch){
	for(auto i: v){
		if(ch == i) return 1;
	}
	return 0;
}

int main(){
	fast;
	string s, ss;
	cin >> s >> ss;
	if((int)s.size() != (int)ss.size()) return cout << "No", 0;
	for(int i = 0; i < (int)s.size(); i++){
		if(is_vowel(s[i])){
			if(!is_vowel(ss[i])) return cout << "No", 0;
		}
		else{
			if(is_vowel(ss[i])) return cout << "No", 0;
		}
	}
	cout << "Yes";

	
	return 0;
}
