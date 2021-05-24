#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define CHILDREN 26
#define MAX 100

typedef struct TrieNode
{
    struct TrieNode *children[CHILDREN];
    //a bool to indicate if this node is the
    //last node in a word
    bool isEndofWord;
} TrieNode;
//creating memory for node
TrieNode *createNode(void)
{
    //malloc memory
    TrieNode *temp = malloc(sizeof(TrieNode));
    //if the mem alloc is successful
    if (temp)
    {
        //set the EOW to false
        //default param
        temp->isEndofWord = false;

        //initializing all children to NULL
        for (int i = 0; i < CHILDREN; i++)
        {
            temp->children[i] = NULL;
        }
    }
    //returning the node
    return temp;
}
//recursive insert
//takes in root of Trie, the string to be added, and an int = 0
//(int = 0 is to keep track of where we are in regards to the word)
void insertRec(TrieNode *root, const char *string, int i)
{
    //if i is less than the string length
    if (i < strlen(string))
    {
        //getting the index of the char
        int index = string[i] - 'a';
        //if the child node of teh root at index is null
        //if we are trying to add a letter where one doesnt exist
        if (root->children[index] == NULL)
        {
            //create the node and assign it to root -> children[index]
            root->children[index] = createNode();
        }
        //recursively call, but incrementing i
        //this moves to teh next letter in the string
        insertRec(root->children[index], string, i + 1);
    }
    //when i reaches teh string length
    else
    {
        //change the last letter of the word
        //to have an EOW value of true
        root->isEndofWord = true;
    }
}
//helper function to check if a current node is a leaf node or not
bool isLeaf(TrieNode *root)
{
    return root->isEndofWord != false;
}
//helper function to insert recursively without manually having to
//enter a value for i
void insert(TrieNode *root, char *string)
{
    insertRec(root, string, 0);
}
//displays teh contents of the trie
void displayContent(TrieNode *root, char str[], int level)
{
    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
    if (isLeaf(root))
    {
        // Assign a null character in temporary string
        str[level] = '\0';
        printf("%s\n", str);
    }

    for (int i = 0; i < CHILDREN; i++)
    {
        // If NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->children[i])
        {
            str[level] = i + 'a';
            displayContent(root->children[i], str, level + 1);
        }
    }
}

// Function call for displaying content
void display(TrieNode *itr)
{
    int level = 0;
    char str[MAX];

    // Function call with necessary arguments
    displayContent(itr, str, level);
}

// Driver code
int main()
{
    TrieNode *root = createNode();
    insert(root, "thier");
    insert(root, "there");
    insert(root, "answer");
    insert(root, "any");

    /* After inserting strings, trie will look like
                                        root
                                        / \
                                        a     t    
                                        |     |    
                                        n     h    
                                        | \ |
                                        s y e    
                                        |     | \
                                        w     i r
                                        |     | |
                                        e     r e
                                        |    
                                        r
    */

    display(root);

    return 0;
}