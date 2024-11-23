#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ALPHABET_SIZE 26


#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
};


struct TrieNode* getNode(void) {
    struct TrieNode* pNode = NULL;

    pNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));

    if (pNode) {
        pNode->isEndOfWord = 0;

        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}


void insert(struct TrieNode* root, const char* key) {
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode* pCrawl = root;

    for (level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = 1;
}


int search(struct TrieNode* root, const char* key) {
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode* pCrawl = root;

    for (level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return 0;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main() {
    
    char keys[][8] = {"hello", "world", "trie", "algorithm"};

    struct TrieNode* root = getNode();

  
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
        insert(root, keys[i]);

   
    printf("Search for \"hello\": %s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("Search for \"world\": %s\n", search(root, "world") ? "Found" : "Not Found");
    printf("Search for \"trie\": %s\n", search(root, "trie") ? "Found" : "Not Found");
    printf("Search for \"data\": %s\n", search(root, "data") ? "Not Found" : "Not Found");
    printf("Search for \"algo\": %s\n", search(root, "algo") ? "Not Found" : "Not Found");
    printf("Search for \"algorithm\": %s\n", search(root, "algorithm") ? "Found" : "Not Found");

    return 0;
}
