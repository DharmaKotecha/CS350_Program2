#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "WordNode.h"
#include "WordTree.h"

using namespace std;

class WordTree {
public:
    WordNode* root;

    WordTree() {
        root = NULL;
    }

    // Inserts a word into the tree, incrementing the count if it already exists.
    void Insert(string word, int lineNumber) {
        if (root == NULL) {
            root = new WordNode(word, lineNumber);
            return;
        }

        WordNode* curr = root;
        while (true) {
            if (word == curr->word) {
                curr->lineNumberCount[lineNumber]++;
                return;
            }
            else if (word < curr->word) {
                if (curr->left == NULL) {
                    curr->left = new WordNode(word, lineNumber);
                    return;
                }
                curr = curr->left;
            }
            else {
                if (curr->right == NULL) {
                    curr->right = new WordNode(word, lineNumber);
                    return;
                }
                curr = curr->right;
            }
        }
    }

    // Prints the tree in alphabetical order, along with how many times each word appears.
    void PrintTreeInOrder() {
        InOrderTraversal(root);
    }

    // Returns the number of unique words in the tree.
    int CountUniqueWords() {
        return CountUniqueWordsHelper(root);
    }

    // Returns the total number of words in the input file.
    int CountWords() {
        return CountWordsHelper(root);
    }

    // Returns the first word in the tree.
    string FindMin() {
        if (root == NULL) {
            return "";
        }
        WordNode* curr = root;
        while (curr->left != NULL) {
            curr = curr->left;
        }
        return curr->word;
    }

    // Returns the last word in the tree.
    string FindMax() {
        if (root == NULL) {
            return "";
        }
        WordNode* curr = root;
        while (curr->right != NULL) {
            curr = curr->right;
        }
        return curr->word;
    }

    // Returns a vector of line numbers for a word.
    vector<int> GetWordLines(string word) {
        vector<int> lines;
        WordNode* curr = root;
        while (curr != NULL) {
            if (word == curr->word) {
                for (auto it = curr->lineNumberCount.begin(); it != curr->lineNumberCount.end(); ++it) {
                    lines.push_back(it->first);
                }
                break;
            }
            else if (word < curr->word) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        return lines;
    }

private:
    // Traverses the tree in order and prints each word along with how many times it appears.
    void InOrderTraversal(WordNode* node) {
        if (node != NULL) {
            InOrderTraversal(node->left);
            cout << node->word << " appears " << node->GetTotalCount() << " times" << endl;
            InOrderTraversal(node->right);
        }
    }

    // Recursively counts the number of unique words in the tree.
    int CountUniqueWordsHelper(WordNode* node) {
        if (node == NULL) {
            return 0;
        }
        return CountUniqueWordsHelper(node->left) + CountUniqueWordsHelper(node->right) + 1;
    }

    //
