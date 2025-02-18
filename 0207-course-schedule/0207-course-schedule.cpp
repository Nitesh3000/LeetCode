class Solution {
private:
    vector<vector<int>> makeAdjList(int numCourses,vector<vector<int>>& prerequisites){
        vector<vector<int>> adjList(numCourses);
        for(auto& courses: prerequisites){
            adjList[courses[1]].push_back(courses[0]);
        }
        return adjList;
    }

    bool dfs(vector<vector<int>>& adjList, vector<int>& visited, vector<int>& pathVisited,int node){
        visited[node] = 1;
        pathVisited[node] = 1;
        for(int neighbor : adjList[node]){
            if(!visited[neighbor]){
                if(dfs(adjList, visited, pathVisited, neighbor)){
                    return true;
                }
            }
            else if(pathVisited[neighbor]){
                return true;
            }
            
        }
        pathVisited[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList = makeAdjList(numCourses,prerequisites);
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        for(int i = 0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(adjList, visited, pathVisited,i))
                    return false;
            }
    
        }
        return true;
    }
};