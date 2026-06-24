class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector <bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        int limit = sqrt(n - 1);
        for (int i=2; i <= limit; i++){
            if (!isPrime[i]) continue;
            for (long long j = 1LL * i * i; j <n; j += i)
            isPrime[j] = false;
        }
        int cnt = 0;
        for (int i=2; i< n; i++){
            if(isPrime[i]) cnt++;
            
        }
        return cnt;
        
    }
};