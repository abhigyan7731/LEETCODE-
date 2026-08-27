class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int n = s.size();
        int matched = 0;

        while (matched < n && cnt[target[matched] - 'a'] > 0) {
            cnt[target[matched] - 'a']--;
            matched++;
        }

        for (int i = matched; i >= 0; --i) {
            if (i < matched) {
                cnt[target[i] - 'a']++;
            }

            if (i == n) continue;

            for (int ch = target[i] - 'a' + 1; ch < 26; ++ch) {
                if (cnt[ch] == 0) continue;

                string ans = target.substr(0, i);
                ans += char('a' + ch);
                cnt[ch]--;

                for (int k = 0; k < 26; ++k) {
                    ans.append(cnt[k], char('a' + k));
                }

                return ans;
            }
        }

        return "";
    }
};