class Solution {
public:
    set<vector<int>>ans; 
    vector<vector<int>> combine(int n, int k) {
        vector<int>tst;
        recur(n,k,tst,1);
        vector<vector<int>>fin ; 
        while(!ans.empty())
        {
            fin.push_back(*ans.begin());
            ans.erase(ans.begin());
        }
        return fin;
    }
    // just in simple way

    // 1 2 and 1 3 and 1 4 and 2 3 and 2 4 and 3 4 
void recur(int n, int k ,vector<int>tst,int index)
{
        if(tst.size() == k)
        {
            ans.insert(tst);
            return ;
        }
    for(int i = index ;i<=n;i++)
    {
        tst.push_back(i);
        recur(n, k,tst,i+1);
        tst.pop_back();
       
    }
    }
};