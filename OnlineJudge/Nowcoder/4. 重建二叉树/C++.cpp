/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        return reBuild(pre.begin(), pre.end(), vin.begin(), vin.end());
    }
    TreeNode* reBuild(vector<int>::iterator preB, vector<int>::iterator preE, vector<int>::iterator inB, vector<int>::iterator inE) {
        if (inE == inB) {
            return NULL;
        }
        TreeNode* ans = new TreeNode(*preB);
        auto root = find(inB, inE, *preB);
        ans->left = reBuild(preB + 1, preB + (root - inB) + 1, inB, root);
        ans->right = reBuild(preB + (root - inB) + 1, preE, root + 1, inE);
        return ans;
    }
};