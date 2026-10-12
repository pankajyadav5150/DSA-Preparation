#include <iostream>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
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

    void insertWord(string s)
    {
        TrieNode *current = root;

        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';

            if (current->children[index] == nullptr)
            {
                TrieNode *newChar = new TrieNode();
                current->children[index] = newChar;
                current = newChar;
            }

            else
            {
                current = current->children[index];
            }
        }
        current->isEndOfWord = true;
        cout << "done";
    }

    bool search(string s)
    {
        TrieNode *current = root;

        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            if (current->children[index] == nullptr)
            {
                return false;
            }
            current = current->children[index];
        }


        return current->isEndOfWord;
    }
};

int main()
{

    Trie *trie = new Trie();
    trie->insertWord("pankaj");
    trie->insertWord("rahul");
    trie->insertWord("sandeep");
cout<<endl;
cout << trie->search("pankaj");

    return 0;
}