class Solution {
public:
    int pivotInteger(int n) {
        int i = 1;
        int j = n;
        if(n == 1) return 1;
        int sum = n * (n+1) / 2;
        while(i < j){
            int mid = (i + j) / 2;
            if(mid*mid == sum) return mid;
            else if(mid*mid - sum < 0) i = mid + 1;
            else j = mid - 1;
        }
        return -1;
    }
};