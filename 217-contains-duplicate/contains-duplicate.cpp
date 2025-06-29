class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // just use unorder_set to remove any dublicate number 
      unordered_set<int> s;

    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }
    // compare with size of set and original array 
    if(s.size() == nums.size())
    {
        return false;
    }
    else {
        return true ;
    }

    }
};