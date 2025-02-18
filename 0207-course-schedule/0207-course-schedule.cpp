class Solution {
private:
    vector<vector<int>> createList(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adList(numCourses);
        for (auto it : prerequisites) {
            adList[it[1]].push_back(it[0]); // it[1] -> it[0]
        }
        return adList;
    }

    //detect cycles
    bool dfs(int node, vector<bool>& visited, vector<bool>& pathVisited, vector<vector<int>>& adList) {
        visited[node] = true;
        pathVisited[node] = true;
        for (int neighbor : adList[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, pathVisited, adList)) {
                    return true; // Cycle detected
                }
            } else if (pathVisited[neighbor]) {
                return true; // Back edge found, cycle detected
            }
        }
        pathVisited[node] = false; // Backtrack
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList = createList(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, pathVisited, adjList)) {
                    return false; // If a cycle is detected, return false
                }
            }
        }
        return true; // No cycles detected, so all courses can be finished
    }
};
