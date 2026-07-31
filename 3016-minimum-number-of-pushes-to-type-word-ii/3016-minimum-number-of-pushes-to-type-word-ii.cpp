class Solution {
public:
    int minimumPushes(string word) {
        // Count frequencies of each letter
        int cnt[26] = {0};
        for (char c : word) {
            cnt[c - 'a']++;
        }

        // Collect non-zero frequencies
        vector<int> freq;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                freq.push_back(cnt[i]);
            }
        }

        // Sort in descending order
        sort(freq.begin(), freq.end(), greater<int>());

        long long ans = 0;
        for (int i = 0; i < (int)freq.size(); ++i) {
            int cost = i / 8 + 1;        // position group cost
            ans += 1LL * freq[i] * cost;
        }

        return (int)ans;
    }
};