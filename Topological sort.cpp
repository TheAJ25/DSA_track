// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

// Example 1:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 3, 2, 1, 0.
// Example 2:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 5, 4, 2, 1, 3, 0.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).












class Solution
{
    
    private:
        
        void topoSort(vector<bool> &visited, stack<int> &stack, int u, vector<int> adj[]){
            visited[u] = true;
            
            for(auto v : adj[u]){
                if(!visited[v]){
                     topoSort(visited, stack, v, adj);
                }
            }
            
            stack.push(u);
        }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> visited(V, false);
	    stack<int> stack;
	    
	    
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            topoSort(visited, stack, i, adj);
	        }
	    }
	    
	    vector<int> result;
	    for(int i=0; i<V; i++){
	        int temp = stack.top();
            stack.pop();
	        result.push_back(temp);
	    }
	    
	    return result;
	}
};
