struct TrieNode {
    bool lastNode;
    TrieNode* next[26];
    TrieNode() {
        lastNode = false;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;

        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(!cur->next[idx]) {
                cur->next[idx] = new TrieNode();
            }
            cur = cur->next[idx];
        }

        cur->lastNode = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;

        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(!cur->next[idx]) return false;
            cur = cur->next[idx];
        }

        return cur->lastNode;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;

        for(int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if(!cur->next[idx]) return false;
            cur = cur->next[idx];
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