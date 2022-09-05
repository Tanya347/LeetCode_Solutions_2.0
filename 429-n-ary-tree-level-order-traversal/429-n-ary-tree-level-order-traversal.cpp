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
        
        if(root == NULL)
            return {};
    
        vector<vector<int>> traversal(1000);
        
        queue<Node*> nodes;
        unordered_map<Node*, int> parent;
        parent[root] = 0;
        nodes.push(root);
        
        while(!nodes.empty()) {
            Node* n = nodes.front();
            nodes.pop();
            traversal[parent[n]].push_back(n -> val);
            
            for(int i = 0; i < n->children.size(); i++) {
                nodes.push(n -> children[i]);
                parent[n -> children[i]] = parent[n] + 1;
            }
        }
        
        int i = 0;
        for(i = 0; i < traversal.size(); i++) {
            if(traversal[i].empty())
                break;
        }
        
        traversal.erase(traversal.begin() + i, traversal.end());
        
        return traversal;
    }
};