class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for (int x : amount){
            if (x > 0) pq.push(x);
        }
        int seconds = 0;
        while (pq.size() >= 2) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            seconds++;
            if (a > 1) pq.push(a-1);
            if (b > 1) pq.push(b-1);
        }
        if (!pq.empty()) {
            seconds += pq.top();
        }
        return seconds;
        
    }
};