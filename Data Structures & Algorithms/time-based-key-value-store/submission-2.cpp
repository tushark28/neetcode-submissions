class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> timeMap;
    TimeMap() { 
       
    }

    void set(string key, string value, int timestamp) {
        auto itr = timeMap.find(key);
        if (itr != timeMap.end()) {
            timeMap[key].push_back({timestamp, value});
            return;
        }
        timeMap[key] = vector<pair<int, string>>{{timestamp, value}};
    }

    string get(string key, int timestamp) {
        auto itr = timeMap.find(key);
        if (itr == timeMap.end()) {
            return "";
        }

        string bestAns = "";
        int bestTimestamp = timestamp;

        int low = 0;
        int high = timeMap[key].size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;

            auto ele = timeMap[key][mid];

            if (ele.first <= timestamp){
                bestTimestamp = ele.first;
                bestAns = ele.second;
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        return bestAns;
    }
};
