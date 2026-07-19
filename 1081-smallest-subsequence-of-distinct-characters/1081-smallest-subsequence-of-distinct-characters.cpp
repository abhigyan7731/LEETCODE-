class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        vector<int> last(26,-1);

        for (int i=0; i<n; i++){
            last[s[i] - 'a'] = i;
        }
        vector<bool> inStack(26, false);
        string st;

        for (int i=0; i <n; i++){
            char c = s[i];
            int idx = c - 'a';

            if (inStack[idx]) continue;

            while (!st.empty() && st.back() > c && last[st.back() - 'a'] > i){
                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(c);
            inStack[idx] = true;
        }
        return st;

        
    }
};