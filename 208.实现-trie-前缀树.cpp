/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class TrieNode {
public:
    char val;
    bool isEnd;
    TrieNode** son;
    TrieNode(char val, bool isEnd, TrieNode** son) 
    : val(val), isEnd(isEnd), son(son) {}
    TrieNode(char val, bool isEnd) 
    : val(val), isEnd(isEnd) {
        son = new TrieNode*[26];
        for (int i = 0; i < 26; i++) son[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode(0, false);
    }
    
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->son[word[i]-'a'] == nullptr) {
                p->son[word[i]-'a'] = new TrieNode(word[i], false);
            }
            p = p->son[word[i]-'a'];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *p = root;
        for (char ch: word) {
            if (p->son[ch-'a'] == nullptr) return false;
            p = p->son[ch-'a'];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char ch: prefix) {
            if (p->son[ch-'a'] == nullptr) return false;
            p = p->son[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

