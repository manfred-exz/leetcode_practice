#include <cstdlib>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
//
// Created by manfred on 7/16/17.
//
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
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> res;
        auto cmp = [](TreeNode* lhs, TreeNode* rhs) -> bool{
            return lhs->val < rhs->val;
        };
        std::deque<TreeNode*> current_level;
        current_level.push_back(root);
        
        while(!current_level.empty()){
            std::priority_queue<TreeNode*, std::vector<TreeNode*>, decltype(cmp)> pri(cmp);
            for(TreeNode* node: current_level){
                pri.push(node);
            }
            res.push_back(pri.top()->val);

            unsigned long size = current_level.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *pNode = current_level.front();
                current_level.pop_front();

                if(pNode->left) current_level.push_back(pNode->left);
                if(pNode->right) current_level.push_back(pNode->right);
            }
        }
        
        return res;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(9);
    
    Solution s;
    auto res = s.largestValues(root);
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << std::endl;
    }
}