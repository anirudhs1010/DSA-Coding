class MyCalendar {
public:
    map<int, int> m;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {

        m[start]++;
        m[end]--;
        int mx = INT_MIN;
        int curr = 0;
        for (const auto b: m) {
            curr += b.second;
            if (curr > 1) {
                m[start]--; // Rollback changes for this booking
                m[end]++;   // Rollback changes for this booking
                return false;
            }
        }

        // If we reach here, there was no overlap
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
