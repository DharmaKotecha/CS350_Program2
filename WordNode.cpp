#include "WordNode.h"

class WordNode {

    public:
    string word;
    int lineNumber;
    WordNode *left;
    WordNode *right;

    WordNode(string word, int lineNumber) {
        this->word = word;
        this->lineNumber = lineNumber;
        this->left = NULL;
        this->right = NULL;
    }
};
