class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = parseExpr(expression, i);
        return vector<string>(result.begin(), result.end());
    }

private:
    set<string> parseExpr(const string& s, int& i) {
        set<string> res;
        set<string> term = parseTerm(s, i);
        res.insert(term.begin(), term.end());

        while (i < s.size() && s[i] == ',') {
            i++; // skip ','
            term = parseTerm(s, i);
            res.insert(term.begin(), term.end());
        }
        return res;
    }

    set<string> parseTerm(const string& s, int& i) {
        set<string> res = {""};

        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            set<string> factor;
            if (isalpha(s[i])) {
                string t;
                while (i < s.size() && isalpha(s[i])) {
                    t += s[i++];
                }
                factor = {t};
            } else if (s[i] == '{') {
                i++; // skip '{'
                factor = parseExpr(s, i);
                i++; // skip '}'
            }

            // Concatenate res with factor
            set<string> next;
            for (const string& a : res) {
                for (const string& b : factor) {
                    next.insert(a + b);
                }
            }
            res = move(next);
        }
        return res;
    }
};