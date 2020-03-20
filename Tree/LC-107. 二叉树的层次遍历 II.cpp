/**
 * 107. 二叉树的层次遍历 II
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int n=q.size();
            for(int i=0;i<n;i++){ //当前层节点都在队列中，依次取出
                TreeNode* t=q.front();
                temp.push_back(t->val);
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            //头插法，自底向上输出
            res.insert(res.begin(), temp);
        }
        return res;
    }
};