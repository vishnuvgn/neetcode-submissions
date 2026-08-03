class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        std::unordered_set<std::string> operations{"+","-","*","/"};
        for (const std::string& s : tokens) {
            if (operations.find(s) != operations.end()) {
                int val_2 = st.top();
                st.pop();
                int val_1 = st.top();
                st.pop();

                if (s == "+") {
                    st.push(val_1 + val_2);
                }
                else if (s == "-") {
                    st.push(val_1 - val_2);
                }
                else if (s == "*") {
                    st.push(val_1 * val_2);
                }
                else if (s == "/") {
                    st.push(val_1 / val_2);
                }
            }
            else {
                st.push(std::stoi(s));
            }
        }
        return st.top();
    }
};
