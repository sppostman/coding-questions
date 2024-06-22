class Solution {
public:
    bool areAdj(string &a, string &b){
        bool allowDiff = true;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i]){
                if(allowDiff)
                    allowDiff = false;
                else
                    return false;
            }
        }
        return !allowDiff;
    }
    void prepareAdjList(string &a, int aidx, unordered_map<string, int> &strs, vector<vector<int>> &adjList){
        for(int i=0; i<a.size(); i++){
            char og = a[i];
            for(char j='a'; j<='z'; j++){
                a[i] = j;

                if(a[i] != og && strs.find(a) != strs.end()){
                    adjList[aidx].push_back(strs[a]);
                }
            }
            a[i] = og;
        }
    }
    pair<int, map<string, int>> ladderLength(string beginWord, string endWord, vector<string>& givenWordList) {
        map<string,int> wordMinDist;

        vector<string> wordList = givenWordList;
        wordList.push_back(beginWord);

        int n = wordList.size();
        vector<vector<int>> adjList(n);

        int target = -1;

        unordered_map<string,int> strs;
        for(int i=0; i<wordList.size(); i++){
            if(wordList[i] == endWord)
                target = i;
            strs[wordList[i]] = i;
        }
        for(int i=0; i<wordList.size(); i++){
            prepareAdjList(wordList[i], i, strs, adjList);
        }
        // for(int i=0; i<wordList.size(); i++){
        //     if(wordList[i] == endWord)
        //         target = i;
        //     for(int j=i; j<wordList.size(); j++){
        //         if(areAdj(wordList[i], wordList[j])){
        //             adjList[i].push_back(j);
        //             adjList[j].push_back(i);
        //         }
        //     }
        // }

        if(target == -1)
            return {0, wordMinDist};
        
        vector<bool> vis(n, false);
        queue<int> rem;

        int src = n-1;
        vis[src] = true;
        rem.push(src);
        wordMinDist[wordList[src]] = 0;


        int currDist =0;
        while(rem.size()){
            currDist++;
            int reachableByCurrDist = rem.size();
            while(reachableByCurrDist--){
                int x = rem.front();
                rem.pop();

                for(auto y : adjList[x])
                    if(!vis[y]){
                        vis[y] = true;
                        rem.push(y);

                        if(wordList[y] == endWord){
                            wordMinDist[endWord] = currDist;
                            return {currDist, wordMinDist};
                        }

                        if(wordMinDist.find(wordList[y]) == wordMinDist.end())
                            wordMinDist[wordList[y]] = currDist;
                    }
            }
        }
        return {0, wordMinDist};
    }

    void dfs(
        string curr, string dest, int dist, map<string, int> &bestPath, set<string> &allowed,
        vector<string> &currPath, vector<vector<string>> &result
    ){
        currPath.push_back(curr);

        cout<<curr<<endl;
        if(curr == dest){
            vector<string> tmpRev = currPath;
            reverse(tmpRev.begin(), tmpRev.end());
            result.push_back(tmpRev);
        } else {
            for(int i=0; i<curr.size(); i++){
                char og = curr[i];
                for(char c='a'; c<='z'; c++){
                    curr[i] = c;

                    if(!allowed.count(curr))
                        continue;
                    
                    if(dist-1 == bestPath[curr])
                        dfs(curr, dest, dist-1, bestPath, allowed, currPath, result);
                    

                }
                curr[i] = og;
            }
        }
        currPath.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        vector<string> currPath;

        set<string> allowed;
        for(auto s : wordList)
            allowed.insert(s);
        allowed.insert(beginWord);

        auto it = ladderLength(beginWord, endWord, wordList);
        int minDist = it.first;
        map<string, int> bestPath = it.second;

        dfs(endWord, beginWord, minDist, bestPath, allowed, currPath, result);
        return result;
    }

    // TLE
    // vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    //     int n = beginWord.size();

    //     set<string> allowed;
    //     for(auto s : wordList)
    //         allowed.insert(s);
    //     if(!allowed.count(endWord))
    //         return {};

    //     queue<vector<string>> rem;
    //     rem.push({beginWord});
    //     allowed.erase(beginWord);

    //     vector<vector<string>> result;

    //     int time = 0;
    //     while(rem.size() && result.empty()){
    //         time++;
    //         int pending = rem.size();
    //         set<string> thisLevelNodes;
            
    //         while(pending--){
    //             auto history = rem.front();
    //             rem.pop();

    //             string curr = history.back();

    //             if(curr == endWord){
    //                 result.push_back(history);
    //                 continue;
    //             }


    //             for(int i=0; i<n; i++){
    //                 char og = curr[i];
    //                 for(char c='a'; c<='z'; c++){
    //                     if(og == c)
    //                         continue;

    //                     curr[i] = c;


    //                     if(!allowed.count(curr))
    //                         continue;

    //                     thisLevelNodes.insert(curr);

    //                     history.push_back(curr);
    //                     rem.push(history);
    //                     history.pop_back();
    //                 }
    //                 curr[i] = og;
    //             }
    //         }
    //         for(auto s : thisLevelNodes){
    //             allowed.erase(s);
    //         }
    //     }
    //     return result;
    // }
};