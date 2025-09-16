class Solution {
public:

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;

        for (int x : nums) {
            st.push_back(x);

            while (st.size() >= 2) {
                int a = st.back();
                int b = st[st.size() - 2];
                int g = gcd(a, b);

                if (g > 1) {
                    long long l = lcm((long long)a, (long long)b); // Use std::lcm in C++17+
                    st.pop_back();
                    st.pop_back();
                    st.push_back((int)l);
                } else {
                    break;
                }
            }
        }
        return st;
    }
};