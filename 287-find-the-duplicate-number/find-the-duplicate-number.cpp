class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int sl = nums[0];
       int fs = nums[0];
        // i have detect cycle 
       do{
            sl = nums[sl];
            fs = nums[nums[fs]]; // duplicate move 
       }while(sl!=fs);
       

       // now let's get the idea 
        sl = nums[0];
       while(sl!=fs)
       {
        sl = nums[sl];
        fs = nums[fs];
       }
       return sl ;
    }
};