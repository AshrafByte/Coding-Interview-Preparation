class TimeMap {
public:
    unordered_map <string,vector<pair<int,string>>> timeMap;
    TimeMap() 
    {
        timeMap.clear();
    }
    
    void set(string key, string value, int timestamp) 
    {
        timeMap[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) 
    {
        auto it = upper_bound(timeMap[key].begin() , timeMap[key].end() , timestamp ,
        [](int val, const pair<int, string>& p) 
        {
            return val < p.first; 
        }
        );
        
        if (it == timeMap[key].begin())
            return "";
    
        return (*prev(it)).second;
    }
};