class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if (sum > 9L * num || sum < 1) {
            return "";
        }

        StringBuilder ans = new StringBuilder();

        int nines = (int) (sum / 9);
        int rem = (int) (sum % 9);

        for (int i = 0; i < nines; i++) {
            ans.append('9');
        }

        if (rem > 0) {
            ans.append((char) ('0' + rem));
        }

        while (ans.length() < num) {
            ans.append('0');
        }

        return ans.toString();
    }
}