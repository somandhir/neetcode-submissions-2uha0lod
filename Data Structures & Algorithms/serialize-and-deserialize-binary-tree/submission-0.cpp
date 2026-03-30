/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*>q;
        q.push(root);
        string str = "";
        while(q.size()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto curr = q.front();q.pop();
                if(!curr) str+="2000";
                else str+=to_string(curr->val);
                str+='.';
                if(!curr)continue;
                auto left = curr->left;
                auto right = curr->right;
                q.push(left);
                q.push(right);
            }
        } 
        cout<<str<<endl;
        return str;  
    }

    vector<int> parse(string s) {
        vector<int> res;
        stringstream ss(s);
        string token;

        while (getline(ss, token, '.')) {
            res.push_back(stoi(token));
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")return nullptr;
        vector<int>v = parse(data);
        TreeNode* head = new TreeNode(v[0]);
        int idx = 1;
        queue<TreeNode*>q;
        q.push(head);
        while(idx<v.size()){
            auto curr = q.front();q.pop();
            int leftNum = v[idx++];
            int rightNum;
            if(idx<v.size())
            rightNum = v[idx++];
            if(leftNum!=2000){
                curr->left = new TreeNode(leftNum);
                q.push(curr->left);
            }
            if(idx<v.size()){
            if(rightNum!=2000){
                curr->right = new TreeNode(rightNum);
                q.push(curr->right);
            }}
        }
        return head;

    }
};
