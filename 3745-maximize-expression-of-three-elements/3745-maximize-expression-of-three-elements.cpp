class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();

        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX;

        for (int x : nums) {
            if (x > max1) {
                max2 = max1;
                max1 = x;
            }else if (x > max2) {
                max2 = x;
            }
            if (x < min1) {
                min1 = x;
            }
        }
        return max1 + max2 - min1;
        
    }
};