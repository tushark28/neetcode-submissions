class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        int sLen = s.length();
        int tLen = t.length();

        if (sLen != tLen) {
            return false;
        }

        for (int i = 0; i < sLen; i++) {
            sMap[s[i]]++;
            tMap[t[i]]++;
        }

        for (const auto& [character, frequency] : sMap) {
            auto it = tMap.find(character);

            if (!(it != tMap.end() && it->second == frequency)) {
                return false;
            }
        }
        return true;
    }
};
