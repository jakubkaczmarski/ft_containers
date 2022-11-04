#include <iostream>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};


struct Node *newNode(int item)
{
    struct Node *tmp = (struct Node *) malloc(sizeof(struct Node));
    tmp->key = item;
    tmp->left = tmp->right;
    return tmp;
}

void inorder(struct Node *root)
{
    if( root != NULL )
    {
        inorder(root->left);
        std::cout << root->key << "->";
        inorder(root->right);
    }
}

struct Node *insert(struct Node *node, int key)
{
    if(node == NULL)
    {
        return newNode(key);
    }
    if(key < node->key)
    {
        node->left = insert(node->left, key);
    }else{
        node->right = insert(node->right, key);
    }
    return node;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, -32);
    root = insert(root, 1);
    std::cout << "Inorder traversal" << std::endl;
    inorder(root);
}