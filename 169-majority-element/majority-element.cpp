class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //nice problem 
        int counter= 0 ;
        int checker = 0 ;
        // we trace it and compare with prev value

        for(int i = 0 ;i<nums.size() ;i++)
        {
            // mean if there is number repeat like before sequence 
            if(counter ==0)
            {
                // to catch it and trace with next number 
                checker = nums[i] ;
            }
            // just add and remove 
            counter += (nums[i] == checker)? 1:-1 ;
        }
        return checker ;
    }
};