class Solution {
public:
        vector<string>ans ;

        int leds[10] = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1}; 
        // first four hour next is min
    vector<string> readBinaryWatch(int turnedOn) {
        // start our recusion here 
        solve(0,turnedOn,0,0);
        return ans ;

    }
    void solve(int index , int count ,int hour , int minute)
    {
        // base 
        if(hour >= 12 || minute >= 60)
        {
            return ;
        }
        if(count == 0)
        {
            string m = to_string(minute);
            if (minute < 10) {
                m = "0" + m; 
            }
            ans.push_back(to_string(hour) + ":" + m);
            return ;
        }
        if(index == 10)
        {
            return ;
        }
        // take 
        if(index < 4)
        {
            solve( index+1 ,  count-1 , hour + leds[index] ,  minute);
        }else {
            solve( index+1 ,  count-1 , hour  ,  minute + leds[index]);
        }
       
        // leave ; 
        solve( index+1 ,  count , hour ,  minute);
    }
};