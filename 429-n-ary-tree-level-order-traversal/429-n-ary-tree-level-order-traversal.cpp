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
    vector<vector<int>> levelOrder(Node* root) {
    
        vector<vector<int>> traversal;
        
        if(root == NULL)
            return traversal;
        
        queue<Node*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()) {
            int size = nodes.size();
            vector<int> temp;
            for(int i = 0; i < size; i++) {
                
                Node* front = nodes.front();
                nodes.pop();
                temp.push_back(front -> val);
            
                for(int i = 0; i < front -> children.size(); i++) {
                    nodes.push(front -> children[i]);
                }
            }
            
            traversal.push_back(temp);
        }
        
        return traversal;
    }
};