/* LeetCode Day 64: 208. Implement Trie (Prefix Tree) (Medium) 70/75 
 * Tyler Edwards | January 6th, 2024 
 * Code Credit: alexander
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
 * There are various applications of this data structure, such as autocomplete and spellchecker.
 * Implement the Trie class:
 * - Trie() Initializes the trie object.
 * - void insert(String word) Inserts the string word into the trie. 
 * - boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise. 
 * - boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise. */

class Trie {
private:
    unordered_map<char, Trie*> next = {};
    bool isword = false;

public:
    Trie() {}
    
    void insert(string word) 
    {
        Trie* node = this;

        for (char ch : word)
        {
            if (!node->next.count(ch))
            {
                node->next[ch] = new Trie();
            }

            node = node->next[ch];
        }

        node->isword = true;
    }
    
    bool search(string word) 
    {
        Trie* node = this;

        for (char ch: word)
        {
            if (!node->next.count(ch))
            {
                return false;
            }

            node = node->next[ch];
        }

        return node->isword;
    }
    
    bool startsWith(string prefix) 
    {
        Trie* node = this;

        for (char ch : prefix)
        {
            if (!node->next.count(ch))
            {
                return false;
            }

            node = node->next[ch];
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