class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int max_length = 0;
        int current_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]) current_sum++;
            else current_sum--;
            
            if(m.find(current_sum) != m.end()){
                max_length = max(max_length, i - m[current_sum]);
            }else{
                m[current_sum] = i;
            }
        
        }
        
        return max_length;
        
    }
};