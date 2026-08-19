class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Store reserved seats as bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            mp[row] |= (1 << (col - 1));
        }

        int ans = (n - mp.size()) * 2;

        // Masks for valid blocks
        int left = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);      // 2-5
        int mid  = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);      // 4-7
        int right= (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);      // 6-9

        for (auto &[row, mask] : mp) {
            bool l = (mask & left) == 0;
            bool m = (mask & mid) == 0;
            bool r = (mask & right) == 0;

            if (l && r)
                ans += 2;
            else if (l || m || r)
                ans += 1;
        }

        return ans;
    }
};