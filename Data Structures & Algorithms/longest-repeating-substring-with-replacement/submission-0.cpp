class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0, maxFreq = 0, ans = 0;
        vector<int> freq(26, 0);

        for (int r = 0; r < s.size(); r++) {
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            int windowSize = r - l + 1;

            while(windowSize - maxFreq > k){
                freq[s[l] - 'A']--;
                l++;

                windowSize = r-l+1;
            }

            ans = max(ans, windowSize);
        }
        return ans;
    }
};
