class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false ;
        }
        else {
            vector<int>ans ;
            while(x>0)
            {
                int m = x%10;
                ans.push_back(m);
                x/=10;
            }
            bool flage= true;
            int z = ans.size();
            for(int i = 0 ;i<ans.size();i++)
            {
                if(ans[i] != ans[z -i - 1] )
                {
                    flage = false ;
                    break;
                }
            }
            if(flage) return true;else return false ;
        }
        
    }
};