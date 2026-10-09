class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;  // insertions added so far
        int open = 0;        // unmatched '(' count

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // Need two closing brackets: "))"
                if (i + 1 < (int)s.size() && s[i + 1] == ')') {
                    // Found "))"
                    if (open > 0) {
                        open--;
                    } else {
                        insertions++; // need to add '('
                    }
                    i++; // consume the second ')'
                } else {
                    // Only one ')' available: add one ')' to make "))"
                    if (open > 0) {
                        open--;
                    } else {
                        insertions++;
                    }
                    insertions++;
                }
            }
        }

        // Every remaining unmatched '(' needs two ')'
        insertions += 2 * open;

        return insertions;
    }
};