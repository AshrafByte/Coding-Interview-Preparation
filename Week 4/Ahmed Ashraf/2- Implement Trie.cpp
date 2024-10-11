class TrieNode
{
public:
    bool isEndOfWord;
    unordered_map<char, TrieNode *> children;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *currentNode = root;
        for (auto ch : word)
        {
            if (currentNode->children.find(ch) == currentNode->children.end())
                currentNode->children[ch] = new TrieNode();

            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *currentNode = root;
        for (auto ch : word)
        {
            if (currentNode->children.find(ch) == currentNode->children.end())
                return false;

            currentNode = currentNode->children[ch];
        }
        return currentNode->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *currentNode = root;
        for (auto ch : prefix)
        {
            if (currentNode->children.find(ch) == currentNode->children.end())
                return false;

            currentNode = currentNode->children[ch];
        }
        return true;
    }
};