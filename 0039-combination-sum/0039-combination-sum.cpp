class Solution {
public:
    set<vector<int>>ans ;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>cur ;
        long long sum = 0  ;
        recur(candidates , target,0,cur,sum) ;      
        vector<vector<int>>ans2;
        while(!ans.empty())
        {
            ans2.push_back(*ans.begin());
            ans.erase(ans.begin());
        } 
        return ans2;
    }
    void recur(vector<int>& ca,int target,int index,vector<int>cur,long long sum)
    {
            if(sum == target )
            {
                ans.insert(cur);
                return ;
            }

            if(sum > target){
                return ;
            }

            if(index == ca.size())
            {
                return ;
            }
           
        // for(int i = index ;i<ca.size();i++)
        // {
            sum += ca[index];
            cur.push_back(ca[index]);
            // take 
            recur(ca,target,index,cur,sum);
            cur.pop_back();
            sum -= ca[index];
            // skip
            recur(ca,target,index + 1,cur,sum);
            
        // }

    }

};