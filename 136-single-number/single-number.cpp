class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int catcher= 0 ;
        int m = nums.size();
        bool checker = false ;
        for(int i = 0 ;i<nums.size()-1;i+=2)
        {
            if(nums[i]!=nums[i+1])
            {
                catcher=nums[i];
                // if there is 0 1 1 
                // which mislead if catcher zero alreay 
                checker = true ;
                break ;
            }
        }
        // check if we have 11334 and to get four and prev test case 
        if(catcher == 0 &&nums[m-1] != 0 && checker== false) 
        {
            catcher = nums[nums.size()-1];
        }
        return catcher;

    }
};