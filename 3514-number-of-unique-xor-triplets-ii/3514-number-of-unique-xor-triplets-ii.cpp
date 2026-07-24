class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        unordered_set<int> pairXors;

        for (int i = 0; i <n; i++){
            for (int j=0; j<n; j++){
                pairXors.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> tripletXors;

        for (int p : pairXors){
            for (int x : nums) {
                tripletXors.insert(p ^ x);
            }
        }
        return static_cast<int>(tripletXors.size());
        
    }
};