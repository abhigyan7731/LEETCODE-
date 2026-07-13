class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string base = "123456789";
        vector<int> ans;

        int minLen = to_string(low).size();
        int maxLen = to_string(high).size();

        for (int len = minLen; len <= maxLen; ++len) {
            // start index i so that substring of length len stays within "123456789"
            for (int i = 0; i + len <= 9; ++i) {
                int num = stoi(base.substr(i, len));
                if (num > high) break;      // further substrings will be even larger
                if (num >= low) ans.push_back(num);
            }
        }

        return ans;    // already sorted by construction
    }
};