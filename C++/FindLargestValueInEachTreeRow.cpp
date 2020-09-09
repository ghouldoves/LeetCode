//Ian Hays
//08-11-2020
//https://leetcode.com/problems/find-largest-value-in-each-tree-row/
//SC: O(N^M) TC: O(N^M)

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
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int m = q.size();
            int val = INT_MIN;
            for(int i = 0; i < m; i++){
                TreeNode* node = q.front();
                q.pop();
                val = max(val,node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(val);
        }
        return res;
    }
};
