class Solution {
public:
    static const long long MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!A[i][k]) continue;
                for (int j = 0; j < n; j++) {
                    if (!B[k][j]) continue;
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<long long> multiplyMatVec(
        const Matrix& A,
        const vector<long long>& v
    ) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i] = (res[i] + A[i][j] * v[j]) % MOD;
            }
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        vector<long long> state(sz, 0);

        for (int i = 0; i < m; i++) {
            state[i] = (i < m - 1);
            state[m + i] = (i > 0);
        }

        Matrix M(sz, vector<long long>(sz, 0));

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++)
                M[i][m + j] = 1;

            for (int j = 0; j < i; j++)
                M[m + i][j] = 1;
        }

        long long p = n - 1;

        Matrix base = M;
        vector<long long> vec = state;

        while (p > 0) {
            if (p & 1)
                vec = multiplyMatVec(base, vec);

            base = multiply(base, base);
            p >>= 1;
        }

        long long ans = 0;
        for (long long x : vec)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};