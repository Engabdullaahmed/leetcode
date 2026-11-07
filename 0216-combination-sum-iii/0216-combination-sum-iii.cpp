class Solution {
public:
    set<vector<int>>ans ;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums = {1,2,3,4,5,6,7,8,9};

        vector<int>cur ;
        
            // vector index target_size  curvector sum  target_sum
        recur( nums , 0,k,cur,0 , n);
        vector<vector<int>>ans2;
        while(!ans.empty())
        {
            ans2.push_back(*ans.begin());
            ans.erase(ans.begin());
        }
        return ans2;
    }
   void recur( vector<int>&nums,int index,int target_size,vector<int>cur_vector,int sum,int target_sum)
    {   
        // base 
        if(sum  == target_sum && cur_vector.size()== target_size)
        {
            ans.insert(cur_vector);
            return;
        }
        if(sum > target_sum || cur_vector.size()== target_size)
        {
            return ;
        }
        if(index>=nums.size())
        {
            return ;
        }
        
        sum += nums[index];
        cur_vector.push_back(nums[index]);
        recur(nums,index+1,target_size,cur_vector,sum,target_sum);
        sum -= nums[index];
        cur_vector.pop_back();
        recur(nums,index+1,target_size,cur_vector,sum,target_sum);


    }
};