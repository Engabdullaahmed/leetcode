class Solution
{
public:

        vector<int> asteroidCollision(vector<int> &asteroids)
        {
        stack<int> st;

         
            for(auto m : asteroids)
            {
                bool flage = true ;
                while(flage && m < 0&&!st.empty() && st.top() > 0)
                {
                    if(abs(m)==abs(st.top()))
                    {
                        flage = false ;
                        st.pop();
                    }
                    else if(abs(m)>abs(st.top()))
                    {
                        st.pop();
                    }
                    else {
                        flage = false ;
                    }
                }
                if(flage)
                {
                    st.push(m);
                }
            }
            vector<int> ans;
                while (!st.empty())
                {
                        ans.push_back(st.top());
                        st.pop();
                }
                reverse(ans.begin(), ans.end());
                return ans;
        }
};