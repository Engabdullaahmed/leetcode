
class AllOne {

public:

    unordered_map<string,int>mp;
    set<pair<int,string>>st;

    AllOne() {
   
    }
    
    void inc(string key) {
        if(mp.find(key) == mp.end()) // not find 
        {
            mp[key]= 1 ;
            st.insert({1,key});
        }else{
                st.erase({mp[key],key});
                mp[key]++;
                st.insert({mp[key],key});
        }
    }
    
    void dec(string key) {
        if(mp.find(key) != mp.end()) 
        {

              st.erase({mp[key],key});
            mp[key]--;
            if(mp[key]!=0)
            {
            st.insert({mp[key],key});
            }
            else {
                // i need to remove from map 
                mp.erase(key);
            }
        }
    }
    string getMaxKey() {
        if(st.empty())
        {
            return "";
        }
        return prev(st.end())->second;
    }
    
    string getMinKey() {
          if(st.empty())
        {
            return "";
        }
        return st.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */