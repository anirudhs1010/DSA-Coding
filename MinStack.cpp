class MinStack {
public:
    int min = INT_MAX;
    map<int, int> m;
    stack<int> s;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        m[val]++;
    }
    
    void pop() {
        int v = s.top();
        s.pop();
        m[v]--;
        if (m[v] == 0)
            m.erase(v);
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if (!m.empty()) {
            const auto b = m.begin();
            return b->first;
        }
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
