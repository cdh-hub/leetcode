/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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
private:
    TreeNode* parse(string& data, int& ptr) {
        if (data[ptr] == 'X') {
            ptr++;
            return nullptr;
        }
        ptr++;
        TreeNode* l = parse(data, ptr);
        bool minus = false;
        ptr++;
        if (data[ptr] == '-') {
            minus = true;
            ptr++;
        }
        TreeNode* root = new TreeNode(0);
        while (data[ptr] != '(') {
            root->val = root->val * 10 + (data[ptr] - '0');
            ptr++;
        }
        root->left = l;
        ptr++;
        root->right = parse(data, ptr);
        ptr++;
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "X";
        return "(" + serialize(root->left) + ")"
                   + to_string(root->val)  +
               "(" + serialize(root->right) + ")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ptr = 0;
        return parse(data, ptr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

