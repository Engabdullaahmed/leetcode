class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       // now that i now we not deal only three 
       // we make at any number not only three numbers 

       //123
       //132
       // first we will find first 
       // the number start changing from decreasing 

       // which we work at two 
       // and after that 
       // will found the next greater number after postion i 
       // on it 
       // and swap 
       // and if there is remain number sort and target to be 
       // min
        int i = nums.size() - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
