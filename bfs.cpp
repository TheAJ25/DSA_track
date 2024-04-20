class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visit[V] = {0};
        visit[0] = 1;
        queue<int> q;
        q.push(0);
        
        vector<int> result;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto &it : adj[node]){
                if(!visit[it]){
                    visit[it] = 1;
                    q.push(it);
                }
            }
        }
        return result;
    }
};
