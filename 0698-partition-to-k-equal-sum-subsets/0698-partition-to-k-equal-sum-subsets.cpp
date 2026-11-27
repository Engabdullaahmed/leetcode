class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long sum  = 0  ;
        sort(nums.rbegin(),nums.rend());
        for(int i =0 ;i<nums.size();i++)
        {
            sum += nums[i];
        }
        if(sum % k != 0 )
        {
            return false ;
        }
        else {
            int target  = sum / k;
            vector<bool>used(nums.size());
         return  recur(target , k ,0,nums,0,0,used );
        
        }
    }
    bool recur(int target , int k ,int index ,vector<int>&arr,long long counter_subset,int counter_parts,vector<bool>&used)
    {
        //  base 
        if(counter_subset == target)
        {
            counter_subset = 0 ;
            counter_parts++;
            index = 0  ;
        }
        if(counter_parts == k)
        {
            return true ;
        }
        for(int i = index;i<arr.size();i++)
        {
            if(!used[i])
            {
                
                if(counter_subset + arr[i] > target)
                {
                    continue ;
                }    
                counter_subset += arr[i];
                used[i] = true;
                if(recur(target,k,i+1,arr,counter_subset,counter_parts,used))
                {
                    return true;
                }
                counter_subset -= arr[i];
                used[i] = false;
                
            }
        }
            return false ; // focuse .. -- 
    }
  
};