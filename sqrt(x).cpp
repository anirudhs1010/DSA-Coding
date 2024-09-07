class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        long long mid = (l+r)/2;
        while (l <= r) {
            if (mid*mid == x)
                return mid;
            else if (mid*mid < x)
                l = mid +1;
            else if (mid*mid > x)
                r = mid - 1;
            mid = (l+r)/2;
        }
        return r;
        
    }
};
