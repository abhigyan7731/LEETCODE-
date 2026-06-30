class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int last[3] = {-1, -1, -1};  // last positions of 'a', 'b', 'c'
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;           // update last position of current char

            // if we have seen all three characters at least once
            if (last[0] != -1 && last[1] != -1 && last[2] != -1) {
                // max of last positions gives earliest end index
                int maxLast = max(last[0], max(last[1], last[2]));
                // all substrings starting at or before min last index and ending >= maxLast are valid
                // simpler view: for current i == maxLast, number of valid starts is 1 + min(last[])
                int minLast = min(last[0], min(last[1], last[2]));
                ans += (minLast + 1);
            }
        }
        return (int)ans;
    }
};