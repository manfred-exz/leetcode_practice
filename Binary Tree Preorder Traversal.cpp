//
// Created by manfred-exz on 2018/3/7.
//
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        vector<TreeNode*> stack;
        stack.push_back(root);
        while(!stack.empty()) {
            TreeNode* curr = stack.back();
            stack.pop_back();

            if(curr == nullptr)
                continue;

            // visit
            res.push_back(curr->val);
            // push children
            if(curr->right) stack.push_back(curr->right);
            if(curr->left) stack.push_back(curr->left);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}