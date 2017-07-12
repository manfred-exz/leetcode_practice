//
// Created by manfred on 7/12/2017.
//

#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
    std::map<TreeNode*, int> dp;    // maximum rob value of sub-tree
public:
    int rob(TreeNode* root) {
        rob_p(root);
        return dp[root];
    }

    void rob_p(TreeNode* root) {
        if (root == nullptr) {
            dp[root] = 0;
            return;
        }

        rob_p(root->left);
        rob_p(root->right);

        int me_and_grandchildren = root->val;
        if(root->left){
            me_and_grandchildren += (root->left->left ? dp[root->left->left] : 0) + (root->left->right ? dp[root->left->right] : 0);
        }
        if(root->right){
            me_and_grandchildren += (root->right->left ? dp[root->right->left] : 0) + (root->right->right ? dp[root->right->right] : 0);
        }

        int children = (root->left ? dp[root->left] : 0) + (root->right ? dp[root->right] : 0);

        dp[root] = std::max(me_and_grandchildren , children);
    }
};

int main(){
    Solution s;
    s.rob();

    return 0;
}