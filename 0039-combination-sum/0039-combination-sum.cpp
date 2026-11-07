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
           
        for(int i = index ;i<ca.size();i++)
        {
            sum += ca[i];
            cur.push_back(ca[i]);
            // take 
            recur(ca,target,i,cur,sum);
            cur.pop_back();
            sum -= ca[i];
            // skip
            // recur(ca,target,i + 1,cur,sum);
            
        }

    }

};