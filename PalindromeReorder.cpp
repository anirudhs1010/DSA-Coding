// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string s;
	cin >> s;
	map<char, int> m;
	for (long unsigned int i = 0; i < s.size(); i++) {
		m[s[i]]++;
	}
	string ans = "";
	string rev = "";
	int counter = 0;
	for (const auto b : m) {
		if (b.second %2 == 1) {
			for (int i = 0; i < b.second; i++)
				ans += b.first;
			counter++;
			if (counter > 1) {
				cout << "NO SOLUTION" << endl;
				return 0;
			}
		}
		else if (b.second %2 == 0) {
			for (int i = 0; i < b.second/2; i++)
				rev += b.first;
		}
		else {
			cout << "NO SOLUTION" << endl;
			return 0;
		}
	}
	string rv = rev;
	reverse(rev.begin(), rev.end());
	cout << rev + ans + rv << endl;
	return 0;
}
