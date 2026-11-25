class Solution {
public:
    int reverse(int x) {
        bool flage = false;
        long long num = x ;
        if(num <= 0)
        {
            flage  = true;
            num = -1*num ;
        }
        long long  ans = 0  ;
        while(num>0)
        {
            int a = num%10; // get
            ans = a + ans*10; 
            num/=10; // remove 
            if(ans > INT_MAX)
            {
                return 0;
            }
            
        }
        if(flage)
        { ans = -ans ;
        }
        if (ans < INT_MIN || ans > INT_MAX) {
            return 0;
        }
        return ans ;
    }
};