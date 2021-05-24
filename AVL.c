#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
*
* SPACE
* Avg: O(n) Worst: O(n)
* 
* ACCESS
* Avg: O(log n) Worst: O(log n)
*
* INSERT
* Avg: O(log n) Worst: O(log n)
*
* SEARCH
* Avg: O(log n) Worst: O(log n)
*
* DELETE
* Avg: O(log n) Worst: O(log n)
*
*/

#define LH -1
#define EQ 0
#define RH 1

//struct for a node in a binary tree/ binary search tree
typedef struct Node
{

    int data;
    struct Node *left;
    struct Node *right;
    int height;

} Node;

//pre order traversal of tree
void preOrderTrav(Node *root)
{
    if (root != NULL)
    {
        printf("%d	", root->data);
        preOrderTrav(root->left);
        preOrderTrav(root->right);
    }

}
//in order traversal of tree
void inOrderTrav(Node *root)
{
    if (root != NULL)
    {
        inOrderTrav(root->left);
        printf("%d	", root->data);
        inOrderTrav(root->right);
    }
}
//post order traversal of tree
void postOrderTrav(Node *root)
{
    if (root != NULL)
    {
        postOrderTrav(root->left);
        postOrderTrav(root->right);
        printf("%d	", root->data);
    }
}
//helper function to create the memory/ links for a Node
Node *createNode(int val)
{
    //creating the memory for the new node
    Node *newNode = malloc(sizeof(Node));
    //setting the nodes left and right children to both be null (empty)
    newNode->left = NULL;
    newNode->right = NULL;
    // setting the new nodes data field to 'val'
    newNode->data = val;
    //height initially set to a leaf
    newNode->height = 1;

    return newNode;
}
//helper function to get height of tree
int height(Node *head)
{
    //if teh head is null return 0
    if (head == NULL)
    {
        return 0;
    }
    //else return the height of the node asked for
    return head->height;
}
//helper function to determine the larger of 2 numbers
int larger(int x, int y)
{
    return (x > y) ? x : y;
}
//helper function to rotate a subtree to teh right, rooted at the root node
Node *rotateRight(Node *root)
{
    Node *temp = root->left;
    Node *temp2 = temp->right;

    //perform the rotation
    temp->right = root;
    root->left = temp2;

    root->height = larger(height(root->left), height(root->right)) + 1;
    temp->height = larger(height(temp->left), height(temp->right)) + 1;

    return temp;
}
//helper function to rotate a subtree to teh left, rotating at teh root node
Node *rotateLeft(Node *root)
{
    Node *temp = root->right;
    Node *temp2 = temp->left;

    //perform the rotation
    temp->left = root;
    root->right = temp2;

    root->height = larger(height(root->left), height(root->right)) + 1;
    temp->height = larger(height(temp->left), height(temp->right)) + 1;

    return temp;
}
//gets teh balance factor of a given node
int getBalance(Node *root)
{
    //if the tree is empty
    if (root == NULL)
    {
        return 0;
    }
    //return teh diff in heigh from both sides
    return height(root->left) - height(root->right);
}
//function to recursively insert a node into the tree, returning the new root
Node *insert(Node *root, int value)
{
    //create the new nodes memory
    Node *new = createNode(value);
    //if the tree is empty
    if (root == NULL)
    {
        return (new);
    }

    //if teh value is smaller than teh data at root
    if (value < root->data)
    {
        //recursivelyt insert to teh left
        root->left = insert(root->left, value);
    }
    //else if the value is larger
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    //duplicates not allowed
    else
    {
        return root;
    }
    //settign the height of our new node
    root->height = 1 + larger(height(root->left), height(root->right));

    //check for balance
    int bal = getBalance(root);

    //cases to correct unbalanced trees
    //LL Case
    if (bal > 1 && value < root->left->data)
    {
        return rotateRight(root);
    }
    //RR Case
    if (bal < -1 && value > root->right->data)
    {
        return rotateLeft(root);
    }
    //LR Case
    if (bal > 1 && value > root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    //RL Case
    if (bal < -1 && value < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    //return the root
    return root;
}
//helper function to get the minimum value in a tree
Node *minValue(Node *head)
{
    Node *curr = head;
    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
//recursive function to delete a node with a given value, given teh root of the tree
//will return the root of the new tree
Node *delete (Node *root, int value)
{
    //if teh list is empty
    if (root == NULL)
    {
        return root;
    }
    //if the value is smaller than the data at teh current node
    if (value < root->data)
    {
        //recursively call delete to the left
        root->left = delete (root->left, value);
    }
    //otherwise if the value is larger than the data at root
    else if (value > root->data)
    {
        //recursively delete down to right side of the tree
        root->right = delete (root->right, value);
    }
    //we are exactly at the node we need to delete
    else
    {
        //case for a node with at most one child
        if ((root->left == NULL) || (root->right) == NULL)
        {
            //temp to store the child that is NOT null
            Node *temp = ((root->left) ? root->left : root->right);
            //case where node has no children
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            //case for one child
            else
            {
                //save the child node
                *root = *temp;
            }

            free(temp);
        }
        //case for two children
        else
        {
            //create a temp node with the minimum tree value
            Node *temp = minValue(root->right);
            //set the current node to hold the minimum tree value
            root->data = temp->data;
            //delete the successor
            root->right = delete (root->right, temp->data);
        }
    }

    //if the tree only had one node then return
    if (root == NULL)
    {
        return root;
    }
    //set the height to be 1 + the larger height of the trees subtrees
    root->height = 1 + larger(height(root->left), height(root->right));

    //see if the tree became unbalanced
    int balance = getBalance(root);
    //LL Case
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rotateRight(root);
    }
    //LR Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateLeft(root);
    }
    //RR Case
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return rotateLeft(root);
    }
    //RL Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        rotateLeft(root);
    }

    return root;
}
//helper function to search for a value
Node* search(Node *root, int val)
{
    //if the root is null (there is no tree)
    //OR
    //we found the data we were searching for
    if(root == NULL || root->data == val)
    {
        //return null / the answer
        return root;
    }
    //if the value we are searching for is less than the current nodes data
    if(val < root->data)
    {
        //recursively serch to the left
        return search(root->left, val);
    }
    //otherwise if the value is larger than the current nodes data
    else if(val > root->data)
    {
        //recursively search to the right
        return search(root->right, val);
    }
    else
    {
        return NULL;
    }


}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    preOrderTrav(root);
    printf("\n");
    if(search(root, 10))
    {
        printf("FOUND\n");
    }
    else
    {
        printf("NOT FOUND\n");
    }
    root = delete(root, 10);
     if(search(root, 10))
    {
        printf("FOUND\n");
    }
    else
    {
        printf("NOT FOUND\n");
    }
    preOrderTrav(root);
    printf("\n");
    return 0;
}