class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> timeMap;
    TimeMap() { 
       
    }

    void set(string key, string value, int timestamp) {
        timeMap[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        string bestAns = "";

        int low = 0;
        int high = timeMap[key].size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;

            auto &ele = timeMap[key][mid];

            if (ele.first <= timestamp){
                bestAns = ele.second;
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        return bestAns;
    }
};
