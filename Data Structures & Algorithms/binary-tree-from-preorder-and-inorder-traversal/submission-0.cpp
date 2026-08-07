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
    unordered_map<int,int> pos;
    TreeNode* build(vector<int>&preorder, vector<int>& inorder, int preL , int preR, int inL, int inR){
        if(preL>preR)return nullptr;
        int rootVal = preorder[preL];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];
        int leftSize = mid - inL;
        
        root->left = build(preorder,inorder,preL+1, preL+leftSize, inL, mid-1);
        root->right = build(preorder,inorder,preL+leftSize+1, preR, mid+1, inR);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i<(int)inorder.size();i++){
            pos[inorder[i]]= i;
        }
        return build(preorder, inorder, 0, (int)preorder.size()-1,0, (int)inorder.size()-1);

    }
};
