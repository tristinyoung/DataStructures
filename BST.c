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
* Avg: O(log n) Worst: O(n)
*
* INSERT
* Avg: O(log n) Worst: O(n)
*
* SEARCH
* Avg: O(log n) Worst: O(n)
*
* DELETE
* Avg: O(log n) Worst: O(n)
*
*/



//struct for a node in a binary tree/ binary search tree
typedef struct Bnode
{

    int data;
    struct Bnode *left;
    struct Bnode *right;

} Bnode;


Bnode* search(Bnode *root, int val)
{
    //if the root is null (there is no tree)
    if(root == NULL || root->data == val)
    {
        //return null
        return root;
    }
    if(val < root->data)
    {
        return search(root->left, val);
    }
    else if(val > root->data)
    {
        return search(root->right, val);
    }


}
//pre order traversal of tree
void preOrderTrav(Bnode *root)
{
    if (root != NULL)
    {
        printf("%d	", root->data);
        preOrderTrav(root->left);
        preOrderTrav(root->right);
    }
}
//in order traversal of tree
void inOrderTrav(Bnode *root)
{
    if (root != NULL)
    {
        inOrderTrav(root->left);
        printf("%d	", root->data);
        inOrderTrav(root->right);
    }
}
//post order traversal of tree
void postOrderTrav(Bnode *root)
{
    if (root != NULL)
    {
        postOrderTrav(root->left);
        postOrderTrav(root->right);
        printf("%d	", root->data);
    }
}
//helper function to create the memory/ links for a Bnode
Bnode *createBNode(int val)
{
    //creating the memory for the new node
    Bnode *newNode = malloc(sizeof(Bnode));
    //setting the nodes left and right children to both be null (empty)
    newNode->left = NULL;
    newNode->right = NULL;
    // setting the new nodes data field to 'val'
    newNode->data = val;
}
//helper function to find the minimum value in a given BST
Bnode *minValueBST(Bnode *root)
{
    //get the current node we are at
    Bnode *currNode = root;
    //while the current node AND the current node's left child are not null
    while (currNode && currNode->left != NULL)
    {
        //set the current node equal to the left child
        currNode = currNode->left;
    }
    //return the current node when you cannot traverse any more
    return currNode;
}
//insertion of a new node into a BST
Bnode *insertBSTree(Bnode *root, int val)
{
    //call helper function to create a new node
    Bnode *newNode = createBNode(val);

    
    //if the root is null(there is no tree)
    if (root == NULL)
    {
        //assign the root to the newNode
        root = newNode;
        return root;
    }
    //if we find the value we are about to add
    if(search(root, val) != NULL)
    {
        printf("Cannot add a node already in the BST\n");
        //return the root (BST can only take a node in once)
        return root;
    }
    //if the value is less than the root's data value
    if (val < root->data)
    {
        //recursively call to insert down the left side of the tree
        root->left = insertBSTree(root->left, val);
    }
    else
    {
        //recursively call to insert down teh right side of the tree
        root->right = insertBSTree(root->right, val);
    }
    //return the root
    return root;
}
//deletion of a node in a BST
Bnode *deleteBSTnode(Bnode *root, int val)
{
    //if the root = null
    if (root == NULL)
    {
        //return
        return root;
    }

    //if the val is less than the roots value
    if (val < root->data)
    {
        //recursively call dow the left of the tree
        root->left = deleteBSTnode(root->left, val);
    }
    //else if the value is greater than the roots value
    else if (val > root->data)
    {
        //recursively call down the right side of the tree
        root->right = deleteBSTnode(root->right, val);
    }
    //else if the value is EQUAL to the roots value (now we need to delete)
    else
    {
        //if there us only one child, we set a temp node to hold that chid, delete the parent node
        //(the root) and we return the temp node
        if (root->left == NULL)
        {
            Bnode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Bnode *temp = root->left;
            free(root);
            return temp;
        }
        //if there are two children at the node that needs to be deleted, we set a temp node equal
        //to the minimum value in the binary search tree
        Bnode *temp = minValueBST(root->right);
        //then set the roots data to be equal to the data found in the minValueTree function above
        root->data = temp->data;
        //recursively call the delete function on the right side of the tree
        root->right = deleteBSTnode(root->right, temp->data);
    }
    //return the root
    return root;
}

//function to add the values of all the nodes in a BST
int totalOfAllNodes(Bnode *root)
{
    //base case (triggered by leaf nodes)
    if (root == NULL)
    {
        return 0;
    }

    //creating a subproblem for teh left side of the tree
    int sum1 = totalOfAllNodes(root->left);
    //creating a subproblem for the right side of the tree
    int sum2 = totalOfAllNodes(root->right);
    //adding the left side of the tree, the right side of the tree, and the root
    int total = sum1 + sum2 + root->data;

    //returning total
    return total;
}
//function to get the height of a specific node in a BST
int heightOfNode(Bnode *root, int val)
{
    //if the root is null
    if (root == NULL)
    {
        //do nothing
        return 0;
    }
    //if the value we are searching for is smaller than the root value
    if (val < root->data)
    {
        //add 1 to the height and recursively call down the left side of the tree
        return 1 + heightOfNode(root->left, val);
    }
    //if the value we are searching for is greater than the root value
    if (val > root->data)
    {
        //add 1 to the height and recursively call down the right side of the tree
        return 1 + heightOfNode(root->right, val);
    }
    //if the value we are searching for is equal to the root vaalue
    if (val == root->data)
    {
        //return 0 (at our destination)
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    Bnode *root = NULL;
    root = insertBSTree(root,80);
    root = insertBSTree(root, 70);
    root = insertBSTree(root, 60);
    root = insertBSTree(root, 50);
    root = insertBSTree(root, 40);
    root = insertBSTree(root, 30);
    root = insertBSTree(root, 20);
    root = insertBSTree(root, 10);
    preOrderTrav(root);
    printf("\n");
    inOrderTrav(root);
    return 0;
}