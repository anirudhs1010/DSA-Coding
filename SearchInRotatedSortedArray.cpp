class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int mid = l+(r-l)/2;
        //find min index
        while (l <= r) {
            if (nums[mid] == target)
                return mid;
            if (nums[l] == target)
                return l;
            if (nums[r] == target)
                return r;
            if (nums[l] < nums[mid] && nums[l] < target && target < nums[mid])
            //normal case
                r = mid-1;
            if (nums[l] < nums[mid] && !(nums[l] < target && target < nums[mid]))
            //ew case
                l = mid+1;
            else if (nums[mid] < target && target < nums[r])
                l = mid+1;
            else
                r = mid-1;
            mid = l+(r-l)/2;
        }
        return -1;
    }
};
