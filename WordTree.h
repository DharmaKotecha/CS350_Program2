#ifndef WORDTREE_H
#define WORDTREE_H

#include "WordNode.h"

class WordTree
{
    public:
        WordTree();
        void Insert(string key);
        void PrintTreeInOrder();
        bool Search(string key);
        string FindMin();
        string FindMax();
        void Remove(string v);
        string Successor(string key);
        string Predecessor(string key);
        int CountUniqueWords();
        int CountWords();

    protected:
        WordNode * Insert(WordNode * node, string key);
        void PrintTreeInOrder(WordNode * node);
        WordNode * Search(WordNode * node, string key);
        string FindMin(WordNode * node);
        string FindMax(WordNode * node);
        WordNode * Remove(WordNode * node, string v);
        string Successor(WordNode * node);
        string Predecessor(WordNode * node);
        int CountUniqueWords(WordNode * node);
        int CountWords(WordNode * node);

    private:
        WordNode * root;
};

#endif // WORDTREE_H
