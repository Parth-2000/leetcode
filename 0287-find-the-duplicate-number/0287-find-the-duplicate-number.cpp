class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(auto n : nums){
            m[n]++;
            if(m[n] > 1){
                return n;
            }
        }
        return -1;
    }
};