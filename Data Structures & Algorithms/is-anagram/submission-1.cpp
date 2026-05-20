class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector <int> frequencyVec (26,0);

        for (int i = 0; i< s.size(); i++){
            frequencyVec[s[i] - 'a']++;
            frequencyVec[t[i] - 'a']--;
        }

        for (auto &i: frequencyVec){
            if(i!=0)return false;
        }

        return true;
    }
};
