class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        if (n==0){
            return {{0}};
        }
        vector<vector<int>> smaller = specialGrid(n - 1);
        int size = smaller.size();
        int offset = size * size;

        vector<vector<int>> result(2* size, vector<int>(2 * size));

        for (int i = 0; i <size; i++){
            for (int j =0; j<size; j++){
                result[i][j + size] = smaller[i][j];
                result[i + size][j + size] = smaller[i][j] + 1 * offset;
                result[i + size][j] = smaller[i][j] + 2 * offset;
                result[i][j] = smaller[i][j] + 3 * offset;
            }
        }
        return result;
        
    }
};