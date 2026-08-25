class Encrypter {
public:
    unordered_map<char, string> mp;
    unordered_map<string, int> freq;

    Encrypter(vector<char>& keys, vector<string>& values,
              vector<string>& dictionary) {

        // Character -> encrypted string
        for (int i = 0; i < keys.size(); i++) {
            mp[keys[i]] = values[i];
        }

        // Encrypt every dictionary word and store its frequency
        for (string word : dictionary) {
            string encrypted = encrypt(word);
            freq[encrypted]++;
        }
    }

    string encrypt(string word1) {
        string ans = "";

        for (char c : word1) {
            if (!mp.count(c))
                return "";

            ans += mp[c];
        }

        return ans;
    }

    int decrypt(string word2) {
        // Only encrypted dictionary words should be counted
        return freq[word2];
    }
};