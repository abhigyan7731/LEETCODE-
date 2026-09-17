class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        // best[i] = minimum length of a valid subarray ending at or before i
        vector<int> best(n, INF);

        int left = 0, sum = 0;
        int answer = INF;
        int minLenSoFar = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int currentLen = right - left + 1;

                // A previous valid subarray must end before 'left'
                if (left > 0 && best[left - 1] != INF) {
                    answer = min(answer, currentLen + best[left - 1]);
                }

                minLenSoFar = min(minLenSoFar, currentLen);
            }

            best[right] = minLenSoFar;
        }

        return answer == INF ? -1 : answer;
    }
};