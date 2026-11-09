class Solution {
public:
  vector<string>ans ;
        map<char, vector<char>> mp;
    vector<string> letterCombinations(string digits) {
        // should declare 

        // 2 -> abc  -> 3
        // 3 -> def  -> 3
        // 4 -> ghi  -> 3
        // 5 -> jkl  -> 3
        // 6 -> mno  -> 3
        // 7 -> pqrs -> 4
        // 8 -> tuv  -> 3
        // 9 -> wxyz -> 4


        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        int index = 0 ;
        string cur = "";
        recur(index, cur ,digits);
       
        return ans;   
    }
    void recur(int index , string cur,string digits)
    {
        // base 
        if(index == digits.size())
        {
            ans.push_back(cur);
            return ;
        }
        if(cur.size()==digits.size())
        {
            
            ans.push_back(cur);
            return ;
        }
        // get cur key ;
        string s;
        int key = digits[index];
        for(auto c :mp[key])
        {
            // get
            cur += c ;
            // recur 
            recur(index+1,cur,digits);
            // pop 

            cur.pop_back();
        }
    }
};