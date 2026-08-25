class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present(nums.begin(), nums.end());

        for (int multiple = k; ; multiple += k){
            if (!present.count(multiple)) {
                return multiple;
            }
        }        
    }
};