class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //originally though about using prefix sums, but did not see the application of hashmap
        //furthermore modding by k simplifies the problem by a lot <- key insight
        map<int, int> m;
        int rsum = 0;
        m[0] = -1; //we make sure there is at least one occurence of the answer
        //this is in the case where the sum itself is mod k
        for (int i = 0; i < nums.size(); i++) {
            rsum += nums[i]; //update running sum
            if (m.find((rsum%k)) != m.end()) { //check if it exists for some pair
                if (i - m[(rsum%k)] > 1) //check if the length is 2 for the subarray
                    return true;
            }
            else
                m[(rsum%k)] = i; //update the first occurence of a remainder
        }
        return false;
    }
};
