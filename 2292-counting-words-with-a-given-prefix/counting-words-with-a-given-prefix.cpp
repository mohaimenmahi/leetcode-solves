class TrieNode {
public:
    int freq;
    TrieNode* next[26];

    TrieNode() {
        freq = 0;
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
        TrieNode* curr = root;

        for(int i = 0; i < word.size(); i++) {
            int idx = word[i]-'a';

            if(!curr->next[idx]) {
                curr->next[idx] = new TrieNode();
            }
            curr = curr->next[idx];
            curr->freq++;
        }
    }

    int search(string word) {
        TrieNode* curr = root;

        for(int i = 0; i < word.size(); i++) {
            int idx = word[i]-'a';

            if(!curr->next[idx]) return 0;
            curr = curr->next[idx];
        }

        return curr->freq;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;

        for(int i = 0; i < words.size(); i++) {
            trie.insert(words[i]);
        }

        return trie.search(pref);
    }
};