/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "X";
        return "(" + serialize(root->left) + ")"
                   + to_string(root->val) +
               "(" + serialize(root->right) + ")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ptr = 0;
        return parse(data, ptr);
    }

    TreeNode* parse(string& data, int& ptr) {
        if (data[ptr] == 'X') {
            ptr++;
            return nullptr;
        }
        ptr++;
        TreeNode* l = parse(data, ptr);
        ptr++;
        TreeNode* root = new TreeNode(0);
        bool tag = false;
        if (data[ptr] == '-') {
            tag = true;
            ptr++;
        }
        while (data[ptr] != '(') {
            root->val = root->val * 10 + (data[ptr] - '0');
            ptr++;
        }
        if (tag) root->val = -root->val;
        ptr++;
        TreeNode* r = parse(data, ptr);
        ptr++;
        root->left = l;
        root->right = r;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

