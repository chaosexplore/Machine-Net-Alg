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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;

        que.push(root);
        int level = 0, pre = 0, cur = 0;
        bool isodd;

        while (!que.empty()) {
            isodd = level % 2;
            pre = isodd ? (1 << 30) : 0;

            int size = que.size();  // record the level size
            for (int i = 0; i < size; ++i) {
                auto t = que.front();
                que.pop();

                cur = t->val;

                if (isodd) {
                    if (cur % 2) return false;
                    if (cur >= pre) return false;
                }
                else {
                    if (cur % 2 == 0) return false;
                    if (cur <= pre) return false;
                }

                pre = cur;

                if (t->left) que.push(t->left);
                if (t->right) que.push(t->right);
            }

            ++level;
        }

        return true;
    }
};