class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDeg(numCourses,0);
        map<int,vector<int>>adj;
        for(auto&v:prerequisites){
            adj[v[1]].push_back(v[0]);
            inDeg[v[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDeg[i]==0)q.push(i);
        }
        vector<int>topo;
        
        while(q.size()){
            int node = q.front();q.pop();
            topo.push_back(node);
            for(auto&el:adj[node]){
                inDeg[el]--;
                if(inDeg[el]==0)q.push(el);
            }
        }
        if( topo.size()==numCourses) return topo;
        return 
        {};
    }
};
