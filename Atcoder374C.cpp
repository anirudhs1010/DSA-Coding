#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long int;
const int N = 1e5;
//same as apple division
int n;
int apples[N];
LL res = 1e9;
LL ans = 1e9;

void dfs(LL group_a, LL group_b, int depth) {
  if (depth == n) {
    LL diff = abs(group_a - group_b);
    
    if (res > diff) {
        res = diff;
        ans = max(group_a, group_b);
    }
    
  } else {
    dfs(group_a + apples[depth], group_b, depth + 1);
    dfs(group_a, group_b + apples[depth], depth + 1);
  } 
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> apples[i];
    dfs(0, 0, 0);
    cout << ans << endl;
   
   
}
