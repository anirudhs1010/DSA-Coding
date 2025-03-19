class MovingAverage {
public:
    int k = 0;
    int sum = 0;
    queue<int> q;
    MovingAverage(int size) {
        k = size;
    }
    
    double next(int val) {
        
        q.push(val);
        if (q.size() > k) {
            sum -= q.front();
            q.pop();
        }
        sum += val;
        
        return (sum*(1.0))/q.size();

    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
