class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded = "";
         for (auto& str : strs) {
            encoded += to_string(str.length()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int numStartIndex = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                int num = stoi(s.substr(numStartIndex, i));
                ans.push_back(s.substr(i+1, num));
                i += num;
                numStartIndex= i+1;
            }
        }
        return ans;
    }
};
