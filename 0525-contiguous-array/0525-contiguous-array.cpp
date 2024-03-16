class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        int current_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]) current_sum++;
            else current_sum--;
            
            if(current_sum == 0){
                ans=i+1;
            }
            else if(m.find(current_sum) != m.end()){
                ans = max(ans, i - m[current_sum]);
            }else{
                m[current_sum] = i;
            }
        }
        
        return ans;
        
    }
};