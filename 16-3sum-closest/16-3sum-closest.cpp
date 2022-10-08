class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 1000000;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            int j = i+1, k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;
                if( abs(target - sum) < abs(target - ans)){
                    ans = sum;
                }
                if(sum > target){
                    k--;
                }else{
                    j++;
                }
            }
        }
        
        return ans;
    }
};