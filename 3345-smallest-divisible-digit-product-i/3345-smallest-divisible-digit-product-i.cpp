class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int num = n ; num < n + 10; num++){
            if (digitProduct(num) % t == 0){
                return num;
            }
        }
        return -1;
        
        
    }
    private:
    int digitProduct(int num){
        int prod = 1;
        while(num > 0){
            prod *= (num % 10);
            num /= 10;
        }
        return prod;
    }
};