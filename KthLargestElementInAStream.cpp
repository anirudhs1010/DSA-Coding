class KthLargest { //review
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    //queue is in increasing order
    int k;
    KthLargest(int h, vector<int>& nums) {
        k = h;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {
        //if (val > pq.top()) //shift Kth
        //    top = ;
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};
