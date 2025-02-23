class Solution {
public:
    int op = 0;
    int countOperations(int num1, int num2) {
        if (num1 == 0 || num2 == 0)
            return op;
        op++;
        if (num1 >= num2) {
            
            return countOperations(num1-num2, num2);
        }
        return countOperations(num1, num2-num1);
    }
};
