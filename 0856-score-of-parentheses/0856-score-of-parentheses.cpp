class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;
        
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') {
                depth++;
            } else {
                if (s[i - 1] == '(') {
                    // Found a "()" pair
                    score += 1 << (depth - 1);
                }
                depth--;
            }
        }
        
        return score;
    }
};