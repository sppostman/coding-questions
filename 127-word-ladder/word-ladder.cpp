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
    int ladderLength(string beginWord, string endWord, vector<string>& givenWordList) {
        vector<string> wordList = givenWordList;
        wordList.push_back(beginWord);

        int n = wordList.size();
        vector<vector<int>> adjList(n);

        int target = -1;

        for(int i=0; i<wordList.size(); i++){
            if(wordList[i] == endWord)
                target = i;
            for(int j=i; j<wordList.size(); j++){
                if(areAdj(wordList[i], wordList[j])){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        if(target == -1)
            return 0;
        
        vector<bool> vis(n, false);
        queue<int> rem;

        int src = n-1;
        vis[src] = true;
        rem.push(src);

        int currDist =0;
        while(rem.size()){
            currDist++;
            int reachableByCurrDist = rem.size();
            while(reachableByCurrDist--){
                int x = rem.front();
                rem.pop();

                if(x == target)
                    return currDist;
                    
                for(auto y : adjList[x])
                    if(!vis[y]){
                        vis[y] = true;
                        rem.push(y);
                    }
            }
        }
        return 0;
    }
};