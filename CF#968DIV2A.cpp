#include <iostream>
using namespace std;
int main()
{
    int n, a;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> s;
        if (s[0] != s[s.size()-1])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
 
    return 0;
}