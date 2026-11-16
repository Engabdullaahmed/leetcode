class Solution {
public:
    vector<string>ans ;
    vector<string> generateParenthesis(int n) {
        int index = 0  ;
        int index2 = 0  ;
        string s= "";
        recur(index,index2,n,s);
        return ans ;
    }
    void recur(int open, int close, int n, string cur)
    {
        if(open == n && close == n)
        {
            ans.push_back(cur);cur ="";
            return; 
        }
        if(open < n)
        {
            recur(open+1, close, n, cur + '(');
        }
        if(close<open)
        {
         recur(open,close+1,n,cur+')');
        }
       
        
    }

};