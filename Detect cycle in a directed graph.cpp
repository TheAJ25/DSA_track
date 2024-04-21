Detect cycle in a directed graph







class Solution {
    
  private:
    bool iscycleDFS(vector<int> adj[], int u, vector<bool> &visited, vector<bool> &inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        
        for(auto v : adj[u]){
            if(visited[v] == false && iscycleDFS(adj, v, visited, inRecursion)){
                return true;
            }
            else if(inRecursion[v] == true){
                return true;
            }
        }
        
        inRecursion[u] = false;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && iscycleDFS(adj, i, visited, inRecursion)){
                return true;
            }
        }
        return false;
    }
};
