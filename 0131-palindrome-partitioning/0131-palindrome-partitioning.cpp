class Solution {
public:
    vector<vector<string>>ans ;
    vector<vector<string>> partition(string s) {
        // index 
        string s2 = ""; 
        vector<string>path;
        recur(0 ,path,s);
        return ans ;
    }
    bool ispalindrom (string cur)
    {
        if(cur.size() == 1)
        {
            return true;
        }
        int r = cur.size() - 1;
        int l = 0 ;
        while(l<= r)
        {
            if(cur[l]!=cur[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void recur(int ind, vector<string>& path, string& s)
    {
        if(ind == s.size())
        {
            ans.push_back(path);
            return ;
        }
        string cur = "";
        for(int i = ind ; i < s.size();i++)
        {
                cur +=s[i];
            if(ispalindrom(cur))
            {
                path.push_back(cur);
                recur(i+1 ,path,s);
                path.pop_back();
            }   
        }
    }
    // a a b 
    // if a is baldrom take it 
    // take next 
    // is aa is complete
    // aab is no stop 

    // a is balndorm ok com
    // ab is no stop
    // b is baldrom ok com
};