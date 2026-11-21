class Solution {
public:

    vector<string> letterCasePermutation(string s) {
      vector<string>ans ;
        recur(0,s,ans);
        return ans ;
    }
    void recur (int index ,string s , vector<string>&ans)
    {
        if(index == s.size())
        {
            ans.push_back(s);
            return ;
        }
      
            if(isalpha(s[index]))
            {
            // take     
            if(s[index]>='A'&&s[index]<='Z')
            {
                s[index] = char(s[index] + 32);
            
                recur(index+1,s,ans);
                s[index] = char(s[index] - 32);
                recur(index+1,s,ans);

            }
            else {
                 s[index] = char(s[index] - 32);
                  recur(index+1,s,ans);
                 s[index] = char(s[index] + 32);
                recur(index+1,s,ans);
            }
            
        }
        else {
             recur(index+1,s,ans);
        }
    }
   
};