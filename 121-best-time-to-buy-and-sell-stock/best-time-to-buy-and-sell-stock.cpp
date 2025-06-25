class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int mn = prices[0];
     int profit = 0  ;
     int ans = 0  ;
     // idea when we iterate we subtract from min 
     // if there is value less than min we compare with prev 
     // to check we get max profit we can 
     for(int i = 1;i<prices.size();i++)
     {
        if(prices[i]<mn)
        {
            mn = prices[i];
        }
        else
        {
            profit = prices[i] - mn ;
            ans = max(profit, ans);
        }
     }   
return ans ;        
    }
};