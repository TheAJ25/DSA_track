class Solution {
    
  private:
    void dfs(int node, int visited[], vector<int> &res, vector<int> adj[]){
        visited[node] = 1;
        res.push_back(node);
        for(auto &it : adj[node]){
            if(!visited[it]){
                dfs(it, visited, res, adj);
            }
        }
    }
    
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int visited[V] = {0}; // Initialize visited array
        int start = 0;
        vector<int> res;
        
        dfs(start, visited, res, adj);
        
        return res;
    }
};
