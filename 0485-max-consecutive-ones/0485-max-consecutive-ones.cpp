class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int current = 0, maximum = 0;
        for (int i=0; i <nums.size(); i++){
            int x = nums[i];
            if (x == 1){
                current++;
                maximum = max(maximum, current);
            }else{
                current = 0;
            }
        }
        return maximum;
        
    }
};