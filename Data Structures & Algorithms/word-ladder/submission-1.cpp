class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> graph;
        bool foundBeginWord = false;
        int wordLen = endWord.length();

        for (int i = 0; i < wordList.size(); i++) {
            int numDiff = 0;
            for (int k = 0; k < wordLen; k++) {
                if (wordList[i][k] != beginWord[k]) {
                    numDiff++;
                }
            }

            if (numDiff == 1) {
                graph[wordList[i]].push_back(beginWord);
                graph[beginWord].push_back(wordList[i]);
            }
        }
        
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i+1; j < wordList.size(); j++) {
                int numDiff = 0;
                for (int k = 0; k < wordLen; k++) {
                    if (wordList[i][k] != wordList[j][k]) {
                        numDiff++;
                    }
                }

                if (numDiff == 1) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        int res = 0;
        unordered_map<string, bool> visited;
        unordered_map<string, string> parent;

        for (const auto& word : wordList) {
            visited[word] = false;
        }

        queue<string> q;
        visited[beginWord] = true;
        q.push(beginWord);
        bool pathFound = false;

        while (!q.empty()) {
            string currVertex = q.front();
            q.pop();

            if (currVertex == endWord) {
                pathFound = true;
                break;
            }

            for (const auto & neigh : graph[currVertex]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    parent[neigh] = currVertex;
                    q.push(neigh);
                }
            }
        }

        if (pathFound) {
            string currVertex = endWord;
            while (parent.contains(currVertex)) {
                res++;
                currVertex = parent[currVertex];
            }
            res++;
        }

        return res;
    }
};