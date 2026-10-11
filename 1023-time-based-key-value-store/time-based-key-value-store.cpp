class TimeMap {
    private :
 unordered_map<string, vector<pair<int, string>>> mp; 
public:
    
    TimeMap() {
        mp.clear() ;
    }

    void set(string key, string value, int timestamp) {
        pair<int,string>temp = {timestamp,value} ;
        mp[key].push_back(temp);
        return;
    }

    string get(string key, int timestamp) {
        // if (mp.find(key) == mp.end())
        //     return "";
        vector<pair<int, string>> &temp = mp[key];
        int low = 0;
        int high = temp.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (temp[mid].first <= timestamp) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        if (ans == -1)
            return "";
        return temp[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */