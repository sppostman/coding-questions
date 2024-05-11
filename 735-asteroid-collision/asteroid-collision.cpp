class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> rights;
        vector<int> safe;

        for(int ast : asteroids){
            if(ast >= 0){
                rights.push(ast);
            } else {
                int size = -ast;
                while(rights.size() && rights.top() < size)
                    rights.pop();
                
                if(rights.empty())
                    safe.push_back(ast);
                else if(rights.top() == size)
                    rights.pop();
            }
        }

        safe.resize(safe.size() + rights.size());
        int placeAt = safe.size()-1;
        while(rights.size()){
            safe[placeAt--] = rights.top();
            rights.pop();
        }

        return safe;
    }
};