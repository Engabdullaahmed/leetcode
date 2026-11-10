class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st ;

        int counter = 0 ;
        // int count = 0 ;
        for(int i = 0 ; i<s.size();i++)
        {
                //  (( ))
         if(s[i] == '(')
         {
           if(i+1 <s.size() && s[i+1] == ')')
           {
            st.push(1);
           }
           else {
            st.push(0);
           }
            
         }  
         else {
            int sum  =0  ;
            if(i+1 <s.size() && s[i+1] == ')')
            {
            while(!st.empty() && st.top()!=0  )
            {
                int op = st.top();
                sum += op;
                st.pop();
            }
            sum*= 2 ;
            if (!st.empty()) {
                st.pop(); // remove the marker
            }
            st.push(sum);
            }
         } 
           
        }
    

        int ans  = 0 ;
            while(!st.empty() )
                {
                    int op = st.top();
                     ans += op ;
                    st.pop();
                }
                return ans ;
    }
};