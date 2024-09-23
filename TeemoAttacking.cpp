class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        long long sum = timeSeries.size()*duration;
        for (int i = 0; i < timeSeries.size()-1; i++) {
            if (timeSeries[i] + duration >= timeSeries[i+1]) {
                sum -= abs((timeSeries[i] + duration)-timeSeries[i+1]);
            }
        }
        return sum;
    }
};
