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
    
    Node* dfs(Node* node, unordered_map<int, Node*>& visited) {
        
        // make a new node with current val and mark it visited
        Node* newnode = new Node(node -> val);
        visited[node -> val] = newnode;
        
        
        // travel the neighbours of this node
        for(int i = 0; i < node -> neighbors.size(); i++) {
            
            if(visited.find(node -> neighbors[i] -> val) == visited.end()) {
                Node *n = dfs(node -> neighbors[i], visited);
                newnode -> neighbors.push_back(n);
            }
            else {
                newnode -> neighbors.push_back(visited.find(node -> neighbors[i] -> val) -> second);
            }
        }
        
        return newnode;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        
        unordered_map<int, Node*> visited;
        return dfs(node, visited);
    }
};