class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>f;
        stack<char>sec;
        for(int i = 0  ;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                if(!f.empty())
                {
                    f.pop();
                }
            }
            else {
                f.push(s[i]);
            }
        }

         for(int i = 0  ;i<t.size();i++)
        {
            if(t[i]=='#')
            {
                if(!sec.empty())
                {
                    sec.pop();
                }
            }
            else {
                sec.push(t[i]);
            }
        }
        if(sec.size()!=f.size())
        {
            return false; 
        }
        else {
            
            while(!sec.empty())
            {
                if(sec.top()==f.top())
                {
                    sec.pop();
                    f.pop();
                }
                else {
                    return false;
                }
            }
            if(sec.size()==f.size())
            {
                return true;
            }return false;
        }
    }
};