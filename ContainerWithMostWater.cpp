class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, m = 0;
        while (l != r) {
            int dis = (r-l)*(min(height[l], height[r]));
            if (height[l] < height[r])
                l++;
            else
                r--;
            m = max(m, dis);
        }
        return m;
    }
};
