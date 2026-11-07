class Solution {
public:
    string removeDuplicates(string s) {
    stack<char>ans ;

    for(int i = 0 ;i<s.size();i++)
    {
        if(!ans.empty())
        {
            if(ans.top() == s[i])
            {
                ans.pop();
            }
            else {
                ans.push(s[i]);
            }
        } 
        else {
            ans.push(s[i]);
        }  
    }
    string ans2 = "";
    while(!ans.empty())
    {
        ans2 += ans.top();
        ans.pop();
    }   
    reverse(ans2.begin(),ans2.end());
    return ans2;
    }
};