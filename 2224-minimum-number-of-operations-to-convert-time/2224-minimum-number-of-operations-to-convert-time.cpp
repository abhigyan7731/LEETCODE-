class Solution {
public:
    int convertTime(string current, string correct) {
        int currMinutes = stoi(current.substr(0,2))*60 + stoi(current.substr(3,2));
        int correctMinutes = stoi(correct.substr(0,2)) * 60 + stoi(correct.substr(3,2));

        int diff = correctMinutes - currMinutes;

        int operations = 0;
        int increment[] = {60,15,5,1};

        for (int inc : increment){
            operations += diff / inc;
            diff %= inc;
        }
        return operations;
        
    }
};