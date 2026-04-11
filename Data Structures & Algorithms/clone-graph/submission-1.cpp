/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        unordered_map<Node*,Node*>mp;
        auto dfs = [&](auto&&self,Node*node){
            if(mp.count(node))return mp[node];
            Node* copyNode = new Node(node->val);
            mp[node]=copyNode;
            for(auto&neigh: node->neighbors){
                copyNode->neighbors.push_back(self(self,neigh));
            }
            return copyNode;
        };

        return dfs(dfs,node);
    }
};
