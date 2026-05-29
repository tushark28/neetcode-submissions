class Solution {
   public:
    string minWindow(string s, string t) {
        int l = 0, have = 0, len = INT_MIN;
        string ans = "";
        unordered_map<char, int> mp, window;

        for (auto& c : t) {
            mp[c]++;
        }

        for (int r = 0; r < s.size(); r++) {
            // cout << r << endl;
            window[s[r]]++;

            if (mp.count(s[r]) && mp[s[r]] == window[s[r]]){
                have++;
            }

            while(have == mp.size()){
                if (len == INT_MIN || len > r-l+1){
                    len = r-l+1;
                    ans = s.substr(l, len);
                    // cout << ans << "ans" << endl;
                }
                // cout << have << " "<<  len << " " << r-l+1 <<" "<<ans << endl;
                window[s[l]]--;
                if(mp.count(s[l]) && mp[s[l]] > window[s[l]]){
                    have--;
                }
                l++;
            }
        }

        return ans;
    }
};
