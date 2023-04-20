class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int m=0;
        while(m<=e){
            if(nums[m]!=0){
                swap(nums, s, m);                  
                s++;
            }
            m++;
        }

    }
};