#include <iostream>
#include <memory>

// enum color{
//         black,
//         red
//     };
// template<typename T, typename key_type>
// struct Node
// {
//     T   *data;
//     key_type *key;
//     Node *left;
//     Node *right;
//     Node *parent;

//     bool color;  //  0 == black | 1 == red
// };
// //

// //Every path from a node to any of its descendants NULL nodes has the same number of black nodes
// //
// template<typename T, typename key_type,typename allocator = std::allocator<T> >
// class Red_B_T
// {
//     typedef allocator allocator_type;
//     typedef T value_type;
//     typedef typename allocator_type::reference reference;
//     typedef typename allocator_type::const_reference const_reference;

//     public:
//     void init_null_node(Node<T, key_type> *node, Node<T, key_type>* parent, T* data)
//     {
//         node->data = NULL;
//         node->parent = parent;
//         node->left = nullptr;
//         node->right = nullptr;
//         node->color = black;
//     }

//     void preOrdering(Node<T, key_type>* node)
//     {
//         if(node != TNULL)
//         {
//             std::cout << node->data << std::endl;
//             preOrdering(node->left);
//             preOrdering(node->right);
//         }
//     }
//     Node<T, key_type> create_new_node(T *data)
//     {
//         this->alloc = alloc();
//     }
//     void insert(Node<T, key_type> *node, T *data)
//     {
//         if(node == NULL)
//         {
//             return create_new_node(data);            
//         }else if(data < node->data)
//         {
//             node->right = insert(node->left, data);
//         }else if(data > node->data)
//         {
//             node->right = insert(node->right, data);
//         }
//     }
//     private:
//     Node<T, key_type>* root;
//     Node<T, key_type>* TNULL;
//     allocator alloc;
// };

// //RED Black tree requirements
// //Every node has a color either red or black
// //The root node is always black
// //All null leaves are black
// //A red node cannot have a red parent or any children

// typedef struct Node<int> t_node;
// struct Node *newNode(int item)
// {
//     t_node *tmp = (struct Node *) malloc(sizeof(t_node));
//     tmp->key = item;
//     tmp->left = tmp->right;
//     return tmp;
// };

// void inorder(t_node *root)
// {
//     if( root != NULL )
//     {
//         inorder(root->left);
//         std::cout << root->key << "->";
//         inorder(root->right);
//     }
// }

// t_node *insert(t_node *node, int key)
// {
//     if(node == NULL)
//     {
//         return newNode(key);
//     }
//     if(key < node->key)
//     {
//         node->left = insert(node->left, key);
//     }else{
//         node->right = insert(node->right, key);
//     }
//     return node;
// }


// t_node *deleteNode(t_node  *root, int key)
// {
//     if(root == NULL)
//         return root;
    
//     if(key < root->key)
//     {
//         root->left = deleteNode(root->left, key);
//     }else if(key > root->key){
//         root->right = deleteNode(root->right, key);
//     }else
//     {
//         if(root->left == NULL)
//         {
//             struct Node *tmp = root->right;
//             free(root);
//             return tmp;
//         }else if(root->right == NULL){
//             struct Node  *tmp = root->left;
//             free(root);
//             return tmp;
//         }
//     }
//     return  NULL;
// }
#include <iostream>

enum color{
    red,
    black,
};

template<typename T>
struct Node
{
    T   *data;
    Node *parent;
    Node *right;
    Node *left;
    int color;
};

template <typename T>
class RBT
{
    public:
    typedef struct Node<T> t_node;
    void    sort_insert(t_node *ptr)
    {
        t_node *temp;
        while(ptr->parent->color == 1)
        {
            if(ptr->parent == ptr->parent->parent->right)
            {
                temp = ptr->parent->parent->left;
                if(temp->color == 1)
                {
                    temp->color = 0;
                    ptr->parent->color = 0;
                    ptr->parent->parent->color = 1;
                    ptr = ptr->parent->parent;
                }else{
                    if(ptr == ptr->parent->left)
                    {
                        ptr = ptr->parent;
                        rot_right(ptr);
                    }
                    ptr->parent->color = 0;
                    ptr->parent->parent->color = 1;
                    rot_left(ptr->parent->parent);
                }
            }else{
                temp = ptr->parent->parent->right;

                if(temp->color == 1)
                {
                    temp->color = 0;
                    ptr->parent->color = 0;
                    ptr->parent->parent->color = 1;
                    temp = temp->parent->parent;
                }else{
                    if (ptr == ptr->parent->right)
                    {
                        ptr = ptr->parent;
                        rot_left(ptr);
                    }
                    ptr->parent->color = 0;
                    ptr->parent->parent->color = 1;
                    rot_right(ptr->parent->parent);
                }
                if(ptr == root)
                {
                    break;
                }
            }
            root->color = 0;
        }

    }
    void rot_left(t_node *ptr)
    {
        t_node *y = ptr->right;
        ptr->right = y->left;
        if(y->left != nullnode)
        {
            y->left->parent = ptr;
        }
        y->parent = ptr->parent;
        if(ptr->parent == nullptr)
        {
            this->root = y;
        }else if(ptr == ptr->parent->left)
        {
            ptr->parent->left = y;
        }else{
            ptr->parent->right = y;
        }
        y->left = ptr;
        ptr->parent = y;
    }
    void rot_right(t_node *ptr)
    {
        t_node *x = ptr->left;
        ptr->left = x->right;
        if(x->right != nullnode)
        {
            x->right->parent = ptr;
        }
        x->parent = ptr->parent;
        if(ptr->parent == nullptr)
        {
            this->root = x;
        }else if(ptr == ptr->parent->right)
        {
            ptr->parent->right = x;
        }else{
            ptr->parent->left = x;
        }
        x->right = ptr;
        ptr->parent = x;
    }


    void    insert(int key)
    {
        t_node *ptr = new t_node;
        ptr->parent = nullptr;
        ptr->data = &key;
        ptr->left = nullnode;
        ptr->right = nullnode;
        ptr->color = 1;

        t_node * y = nullptr;
        t_node *x = this->root;

        while(x != nullnode)
        {
            y = x;
            if(ptr->data < ptr->data)
            {
                x = x->left;
            }else
            {
                x = x->right;
            }
        }
        ptr->parent = y;
        if(y == nullptr)
        {
            root = ptr;
        }else if(ptr->data < y ->data)
        {
            y->left = ptr;
        }else{
            y->right = ptr;
        }

        if(ptr->parent == nullptr)
        {
            ptr->color = 0;
            return ;
        }
        if(ptr->parent->parent == nullptr)
        {
            return ;
        }
        sort_insert(ptr);
    }
    private:
    t_node *root;
    t_node *nullnode;
};

