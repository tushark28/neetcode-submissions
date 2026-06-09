class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars(position.size());

        for (int i = 0; i < position.size(); i++) {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        stack<double> st;

        for (int i = 0; i < cars.size(); i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            if (!st.empty() && st.top() < time) {
                st.push(time);
            } else if (st.empty()) {
                st.push(time);
            }
        }
        return st.size();
    }
};
