class TrieNode {
public:
    map<pair<char, char>, TrieNode*> next;
    int count = 0;

    TrieNode() {}
 };

class Trie {
private:
    TrieNode* root = new TrieNode();
public:
    void insert(string word) {
        TrieNode* cur = root;
        int n = word.size();

        for(int i = 0; i < n; i++) {
            char c1 = word[i], c2 = word[n-1-i];
            if(cur->next.find({c1, c2}) == cur->next.end()) 
                cur->next[{c1, c2}] = new TrieNode();

            cur = cur->next[{c1, c2}];
            cur->count++;
        }
    }

    int search(string word) {
        TrieNode* cur = root;
        int n = word.size();

        for(int i = 0; i < n; i++) {
            char c1 = word[i], c2 = word[n-1-i];

            if(cur->next.find({c1, c2}) != cur->next.end()) 
                cur = cur->next[{c1, c2}];
            else return 0;
        }

        return cur->count;
    }
 };

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        Trie trie;

        int n = words.size();

        long long res = 0;

        for(int i = n-1; i >= 0; i--) {
            res += (long long) trie.search(words[i]);
            trie.insert(words[i]);
        }

        return res;
    }
};