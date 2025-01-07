class TrieNode {
public:
    int freq;

    TrieNode* next[26];

    TrieNode() {
        freq = 0;
        for(int i = 0; i < 26; i++) next[i] = NULL;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word, int start) {
        TrieNode* curr = root;

        for(int i = start; i < word.size(); i++) {
            int idx = word[i]-'a';

            if(!curr->next[idx]) {
                curr->next[idx] = new TrieNode();
            }
            curr = curr->next[idx];
            curr->freq++;
        }
    }

    bool isSubstring(string word) {
        TrieNode* curr = root;

        for(int i = 0; i < word.size(); i++) {
            int idx = word[i]-'a';
            curr = curr->next[idx];
        }

        // the last node frequency will be more than 1 for substrings
        return curr->freq > 1;
    }
};

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        Trie trie;

        for(int i = 0; i < words.size(); i++) {
            string word = words[i];

            for(int j = 0; j < word.size(); j++) {
                trie.insert(word, j); // generating suffix trie
            }
        }

        vector<string> res;

        for(int i = 0; i < words.size(); i++) {
            if(trie.isSubstring(words[i])) res.push_back(words[i]);
        }

        return res;
    }
};