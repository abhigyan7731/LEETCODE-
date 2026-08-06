class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid % 2 == 1) mid--;          // ensure mid is even
            if (nums[mid] == nums[mid + 1])   // pair intact, go right
                l = mid + 2;
            else                              // pattern breaks, go left (including mid)
                r = mid;
        }
        return nums[l];
    }
};