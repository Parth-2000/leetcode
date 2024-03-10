class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        
        for(auto n: nums1){
            m[n]++;
        }
        vector<int> ans;
        for(auto n: nums2){
            if(m[n] != 0){
                ans.push_back(n);
                m[n] = 0;
            }
        }
        return ans;
    }
};