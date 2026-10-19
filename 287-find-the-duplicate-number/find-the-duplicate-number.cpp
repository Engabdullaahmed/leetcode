class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       set<int>st;
       int ans= -1 ;
       for(int i =0 ;i<nums.size();i++)
       {
        if(st.count(nums[i]))
        {
            ans  = nums[i];
        }else {
             st.insert(nums[i]);
        }
       }
       return ans ;
    }
};