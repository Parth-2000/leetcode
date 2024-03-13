class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;
        int curr = 0;
        if(n == 1) return 1;
        for(int i = 1; i < n; i++){
            curr += i;
            if(curr == (sum - curr + i)){
                return i;
            }
        }
        return -1;
    }
};