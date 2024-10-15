// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
	string s;
	cin >> s;
	string ans = "";
	for (int i = s.size()-1; i >= s.size()-3; i--) {
		ans += s[i];
	}
	reverse(ans.begin(), ans.end());
	if (ans == "san")
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
