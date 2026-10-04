class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        
        // Left to right: ensure we never have more ')' than '(' + '*'
        int openMin = 0, openMax = 0;
        for (char c : s) {
            if (c == '(') {
                openMin++;
                openMax++;
            } else if (c == ')') {
                openMin = max(0, openMin - 1);
                openMax--;
            } else { // c == '*'
                openMin = max(0, openMin - 1); // treat '*' as ')'
                openMax++;                     // treat '*' as '('
            }
            if (openMax < 0) return false; // too many ')'
        }
        
        return openMin == 0; // can we balance all '('?
    }
};