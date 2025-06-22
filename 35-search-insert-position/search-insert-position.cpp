class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        if (target <= nums[0]) return 0;

        if (target > nums[n - 1]) return n;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == target) return i;
            if (target > nums[i] && target <= nums[i + 1]) return i + 1;
        }

        return n; 
    }
};
