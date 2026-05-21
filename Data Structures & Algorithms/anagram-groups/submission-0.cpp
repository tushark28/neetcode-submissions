class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> mp;

        for (auto& str : strs) {
            vector<int> frequency(26, 0);
            for (auto& character : str) {
                frequency[character - 'a']++;
            }

            string hashKey;
            for (int x : frequency) {
                hashKey += to_string(x) + "#";
            }

            auto it = mp.find(hashKey);

            if(it != mp.end()){
                ans[it -> second].push_back(str);
            } else {
                ans.push_back({str});
                mp[hashKey] = mp.size();
            }
        }
        return ans;
    }
};
