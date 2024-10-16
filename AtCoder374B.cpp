// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
	string s, ans;

	cin >> s >> ans;
	int x=0, count = 0, y = 0;
	if (ans.size() < s.size()) {
		x = ans.size();
		y = s.size();
	}
	else {
		x = s.size();
		y = ans.size();
	}
	for (int i = 0; i < x; i++) {
		if (ans[i] == s[i]) {
			count++;
		}
		else
			break;
	}
	if (count == y)
		cout << 0 << endl;
	else
		cout << count+1 << endl;
}
