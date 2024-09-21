//https://open.kattis.com/contests/tf9hum/problems
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, a;
    cin >> t;
    
    int spec = 0;
    for (int i = 0; i < t; i++) {
        cin >> a;
        vector<int> nums(a, 0);
        int prev = nums[0];
        int count = 0;
        for (int i = 0; i < a; i++) {
            cin >> nums[i];
            if (i != 0 && nums[i] != nums[0]+(count-1)) {
                spec = i;
            }
            prev = nums[i];
            count++;
        }
        cout << spec+1 << endl;
        
    }

    return 0;
}
