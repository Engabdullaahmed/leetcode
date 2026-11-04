class Solution
{
public:
        set<vector<int>> st;
        vector<vector<int>> permuteUnique(vector<int> &nums)
        {

                recur(0, nums);
                vector<vector<int>> ans;
                // int count = 0;
                while (!st.empty())
                {
                        ans.push_back(*st.begin());
                        st.erase(*st.begin());
                        
                }
                return ans;
        }
        void recur(int index, vector<int> v)
        {

                for (int i = index; i < v.size(); i++)
                {
                        if (index == v.size() - 1)
                        {
                                st.insert(v);
                                return;
                        }
                        swap(v[i], v[index ]);
                        recur(index + 1, v);
                        swap(v[i], v[index ]);
                }
        }
};