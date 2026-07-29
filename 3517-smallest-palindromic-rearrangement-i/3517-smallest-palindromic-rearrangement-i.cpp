class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        string left = s.substr(0, n/2);

        sort(left.begin(), left.end());
        string ans = left;
        if (n % 2 == 1){
            ans.push_back(s[n/2]);
        }
        string right = left;
        reverse(right.begin(), right.end());
        ans += right;

        return ans;
        
    }
};