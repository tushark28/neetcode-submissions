class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int two = st.top();
                st.pop();
                int one = st.top();
                st.pop();

                if (token[0] == '+') {
                    st.push(one + two);
                } else if (token[0] == '-') {
                    st.push(one - two);
                } else if (token[0] == '*') {
                    st.push(one * two);
                } else {
                    st.push(one / two);
                }
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
