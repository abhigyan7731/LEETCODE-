class Solution {
    struct Node {
        char leftChar, rightChar;
        int len, pref, suff, best;
    };

    vector<Node> seg;
    string s;

    Node merge(const Node& a, const Node& b) {
        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        if (a.pref == a.len && a.rightChar == b.leftChar) {
            res.pref = a.len + b.pref;
        }

        res.suff = b.suff;
        if (b.suff == b.len && a.rightChar == b.leftChar) {
            res.suff = b.len + a.suff;
        }

        res.best = max(a.best, b.best);
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(int idx, int left, int right) {
        if (left == right) {
            seg[idx] = {s[left], s[left], 1, 1, 1, 1};
            return;
        }

        int mid = left + (right - left) / 2;
        build(2 * idx, left, mid);
        build(2 * idx + 1, mid + 1, right);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int left, int right, int pos, char ch) {
        if (left == right) {
            seg[idx] = {ch, ch, 1, 1, 1, 1};
            return;
        }

        int mid = left + (right - left) / 2;

        if (pos <= mid) {
            update(2 * idx, left, mid, pos, ch);
        } else {
            update(2 * idx + 1, mid + 1, right, pos, ch);
        }

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;
        int n = s.size();

        seg.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> ans;
        for (int i = 0; i < queryCharacters.size(); i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(seg[1].best);
        }

        return ans;
    }
};