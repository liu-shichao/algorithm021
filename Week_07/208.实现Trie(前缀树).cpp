struct TrieNode {
    TrieNode() : links(r, nullptr), is_end_(false) {}
    bool contain_key(char c) {
        return (links[c - 'a'] != nullptr);
    }
    TrieNode* get(char c) {
        return links[c - 'a'];
    }
    void put(char c, TrieNode* node) {
        links[c - 'a'] = node;
    }
    bool is_end() {
        return is_end_;
    }
    void set_end() {
        is_end_ = true;
    }
    int r = 26;
    bool is_end_;
    vector<TrieNode*> links;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (auto c : word) {
            if (!node->contain_key(c)) {
                node->put(c, new TrieNode());
            }
            node = node->get(c);
        }
        node->set_end();
    }
    
    TrieNode* search_prefix(string prefix) {
        TrieNode* node = root;
        for (auto& c : prefix) {
            if (node->contain_key(c)) {
                node = node->get(c);
            } else {
                return nullptr;
            }
        }
        return node;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = search_prefix(word);
        return (node != nullptr && node->is_end());
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return (search_prefix(prefix) != nullptr);
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */