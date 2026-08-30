class Solution {
public:
    string oddString(vector<string>& words) {
        auto pattern = [](const string& s) {
            vector<int> diff;
            for (int i = 1; i < s.size(); i++){
                diff.push_back(s[i] - s[i - 1]);
            }
            return diff;
        };
        vector<int> p0 = pattern(words[0]);
        vector<int> p1 = pattern(words[1]);
        vector<int> p2 = pattern(words[2]);

        vector<int> common = (p0 == p1 || p0 == p2) ? p0 : p1;

        for (const string& word : words){
            if (pattern (word) != common){
                return word;
            }
        }
        return "";
        
    }
};