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
    void rangesum(TreeNode* root,int& sum,int& low,int&high){
        if(!root) return ;

        if(root->val > low && root->val > high){
            rangesum(root->left,sum,low,high);
        }

        else if(root->val < low && root->val < high){
            rangesum(root->right,sum,low,high);
        }

        else{
            rangesum(root->left,sum,low,high);
            sum+=root->val;
            rangesum(root->right,sum,low,high);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        rangesum(root,sum,low,high);
        return sum;
    }
};