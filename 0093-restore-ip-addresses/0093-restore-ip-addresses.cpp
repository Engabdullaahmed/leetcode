class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // index vector_ans s part
        vector<string>ans ;
        string cur_ip = "";
        recur(0,ans,s,0,cur_ip);
        return ans ;
    }
    void recur(int index ,vector<string >&ans,string s ,int part,string cur_ip)
    {
        if(part==4)
        {
            if(index == s.size())
                {
                    ans.push_back(cur_ip);
                }
                return ;        
        }
  
        for (int i = index; i < min(index + 3, (int)s.size()); i++)
            {
                string temp = s.substr(index, i - index + 1);
                int num = stoi(temp);
                if (temp.size() > 1 && temp[0] == '0')
                    continue;
                
                if(num<= 255 )
                {
                    if(part<3)
                    {
                    recur(i+1,ans,s,part+1,cur_ip+temp+'.');
                    }else{
                         recur(i+1,ans,s,part+1,cur_ip+temp);
                    }
                }
                else {
                    continue ;
                }

            }
            // take one 
            // take two 
            // take three 
            // recursive 
            // normal mode 
            
        
    }
};