class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> result;
        stack<int> st;

        for(int ast : asteroids){
            if(ast >= 0)
                st.push(ast);
            else {
                while(st.size() && abs(st.top()) < abs(ast)){
                    st.pop();
                }
                if(st.empty())
                    result.push_back(ast);
                else if(st.top() == -ast)
                    st.pop();
            }
        }

        result.resize(result.size() + st.size());
        int j = result.size()-1;
        while(st.size() > 0){
            result[j--] = st.top();
            st.pop();
        }

        return result;
    }
};