class Solution {
   public:
    string minWindow(string s, string t) {
        int l = 0, have = 0, len = INT_MAX, index = 0;
        unordered_map<char, int> mp, window;

        for (auto& c : t) {
            mp[c]++;
        }

        for (int r = 0; r < s.size(); r++) {
            window[s[r]]++;

            if (mp.count(s[r]) && mp[s[r]] == window[s[r]]){
                have++;
            }

            while(have == mp.size()){
                if (len > r-l+1){
                    len = r-l+1;
                    index = l;
                }
                window[s[l]]--;
                if(mp.count(s[l]) && mp[s[l]] > window[s[l]]){
                    have--;
                }
                l++;
            }
        }

        return len == INT_MAX ? "" : s.substr(index, len);
    }
};
