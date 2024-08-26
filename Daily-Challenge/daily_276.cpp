/* Daily Question: 590. N-ary Tree Postorder Traversal
 * by Tyler Edwards | August 25th, 2024 
 * Code Credit: pratyush63
 * Given the root of an n-ary tree, return the postorder traversal of its nodes' values.
* Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples) */

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
    vector<int> postorder(Node* root) {
        if(root==NULL) return {};
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            Node* temp=stk.top();
            stk.pop();
            for(int i=0;i<temp->children.size();i++) stk.push(temp->children[i]);
            res.push_back(temp->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};