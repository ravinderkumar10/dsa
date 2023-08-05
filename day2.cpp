class Solution {
public:
    bool dfs(int node, vector<int> &col, vector<vector<int>> &graph){
         
         for(auto it : graph[node]){
             if(col[it]==-1){
                 col[it] = 1-col[node];
                 dfs(it, col, graph);
             }
             if(col[it]==col[node])
               return false;
         }
         return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> col(n, -1);
    for(int i=0; i<n; i++){
        if(col[i]==-1){
            col[i]=1;
        if(dfs(i, col, graph ))
           return true;;
    }
    }

    return false;

        //BFS
    //     int n = graph.size();
    //     vector<int> adj[n];
    //     vector<int> col(n, -1);
    //      queue<int> q;
    //    for(int i=0; i<n; i++){
    //     q.push(i);    
    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();
    //         for(auto it : graph[node]){
    //             if(col[it]==-1){
    //                 col[it] = 1 - col[node];
    //                 q.push(it);
    //             }
    //             else if(col[node]==col[it])
    //                return false;
    //         }
    //     }
    //    }
    //     return true;
    }
};