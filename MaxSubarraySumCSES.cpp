#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <limits.h>
using namespace std;
int main()
{
    //either you start a new subarray or add to the current one
    
    vector<long long> nums;
    long long a= 0, b = 0;
    cin >> a;
    for (long long i = 0; i < a;i++) {
        cin >> b;
        nums.push_back(b);
    }
    
    long long maxs = nums[0];
    long long curr = nums[0];
    for (long long i = 1; i < a; i++) {
        curr = max(curr+nums[i], nums[i]);
        maxs = max(maxs, curr);
    }
    cout << maxs << endl;
    return 0;
}
