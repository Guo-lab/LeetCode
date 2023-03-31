/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {

    // 26位的前缀树，带isEnd标识位
    struct TreeNode {
        bool isEnd;
        TreeNode* next[26];
        TreeNode() : isEnd(false), next() {}
    };
    TreeNode* root;

public:
    Trie() {
        root = new TreeNode(); 
    }
    
    void insert(string word) {
        TreeNode* pointer = root;
        for (int i = 0; i < word.size(); i++) { 
            if (pointer->next[word[i] - 'a'] == nullptr) {
                TreeNode* tmp = new TreeNode();
                if (i == word.size() - 1) {
                    tmp->isEnd = true;                
                } else {
                    tmp->isEnd = false;
                }
                pointer->next[word[i] - 'a'] = tmp;
                pointer = pointer->next[word[i] - 'a'];
                ////cout << pointer->isEnd << word[i] - 'a' << endl;
            } 
            else {
                pointer = pointer->next[word[i] - 'a'];
                if (i == word.size() - 1) {
                    pointer->isEnd = true;
                }
            }
        }
    }
    
    bool search(string word) {
        TreeNode* pointer = root;
        for (int i = 0; i < word.size(); i++) { 
            if (pointer->next[word[i] - 'a'] == nullptr) {
                return false;
            } 
            else {
                pointer = pointer->next[word[i] - 'a'];
                if (i == word.size() - 1) {
                    if (pointer->isEnd == true) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TreeNode* pointer = root;
        for (int i = 0; i < prefix.size(); i++) { 
            if (pointer->next[prefix[i] - 'a'] == nullptr) {
                return false;
            } 
            else {
                pointer = pointer->next[prefix[i] - 'a'];
            }
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

