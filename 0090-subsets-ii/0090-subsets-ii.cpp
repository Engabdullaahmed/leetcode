class Solution {
public:
    set<vector<int>>st ;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>cur;
        sort(nums.begin(),nums.end());
        recur(0,nums,cur);
        vector<vector<int>>ans ;
        while(!st.empty())
        {
            ans.push_back(*st.begin());
           st.erase(st.begin());
        }
        return ans ;
    }

    void recur(int index, vector<int>nums, vector<int>& curr)
    {
        if(index == nums.size())
        {
            st.insert(curr);
            return ;
        }

        curr.push_back(nums[index]);
        recur(index+1 , nums,curr);
        curr.pop_back();
        recur(index+1,nums,curr);
    }
};