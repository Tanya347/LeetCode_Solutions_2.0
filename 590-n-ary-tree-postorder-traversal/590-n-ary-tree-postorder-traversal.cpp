/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void postorder(vector<int>& ans, Node* root) {
        if(root) {
            for(int i = 0; i < root -> children.size(); i++) {
                postorder(ans, root -> children[i]);
            }
            ans.push_back(root -> val);
        }
    } 
    
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postorder(ans, root);
        return ans;
    }
};