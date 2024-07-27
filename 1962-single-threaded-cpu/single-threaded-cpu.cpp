class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& givenTasks) {
        vector<pair<pair<int,int>, int>> tasks;
        for(int i=0; i<givenTasks.size(); i++)
            tasks.push_back({{ givenTasks[i][0], givenTasks[i][1]}, i});

        sort(tasks.begin(), tasks.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pending;

        int n = tasks.size();
        long time = 0, i = 0;
        vector<int> done;

        while(pending.size() || i < n){
            if(pending.size() == 0)
                time = max((long)tasks[i].first.first, time);
            while(i < n && tasks[i].first.first <= time){
                pending.push({ tasks[i].first.second, tasks[i].second });
                i++;
            }
            auto curr = pending.top();
            pending.pop();
            time += curr.first;
            done.push_back(curr.second);
        }
        return done;
    }
};