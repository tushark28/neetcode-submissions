class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> s1freq(26, 0);
        vector<int> windowfreq(26, 0);

        for (auto& cr : s1) {
            s1freq[cr - 'a']++;
        }

        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            windowfreq[s2[r] - 'a']++;

            if (r - l + 1 > s1.size()){
                windowfreq[s2[l] - 'a']--;
                l ++;
            }

            if (windowfreq == s1freq){
                return true;
            }
        }

        return false;
    }
};
