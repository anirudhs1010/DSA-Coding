//https://open.kattis.com/contests/tf9hum/problems/progressivescramble
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int main()
{
    int t = 0;
    string alphab = "abcdefghijklmnopqrstuvwxyz";
    map<char, int> df;
    map<int, char> m;
    df[' '] = 0;
    for (int i = 1; i <= 26; i++) {
        df[alphab[i-1]]=i;
        m[i] = alphab[i-1];
    }
    m[0] = ' ';
    cin >> t;
    for (int j = 0; j < t; j++) {
        //encode
        char x;
        int counter = 0;
        string inp;
        string ans;
        cin >> x;
        getline(cin, inp);
        if (x == 'e') {
            for (int i =0; i < inp.size(); i++) {
                int y = (df[inp[i]] + counter)%27;
                ans += m[y];
                counter = y;
            }
        }
        else if (x == 'd') {
            int counter = 0;
            for (int i = 0; i < inp.size(); i++) {
                int y = (df[inp[i]] - counter + 27) % 27;
                ans += m[y];
                counter = df[inp[i]];
            }
        }
        cout << ans.substr(1, ans.size()) << endl;
    }
    
    return 0;
}
