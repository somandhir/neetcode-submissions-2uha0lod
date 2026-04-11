class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp;

        function<Node*(Node*)> dfs = [&](Node* curr) {
            if (mp.count(curr)) return mp[curr];

            Node* copy = new Node(curr->val);
            mp[curr] = copy;

            for (auto nei : curr->neighbors) {
                copy->neighbors.push_back(dfs(nei));
            }

            return copy;
        };

        return dfs(node);
    }
};