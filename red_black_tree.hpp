#include <iostream>
#include <memory>

enum color{
        black,
        red
    };
template<typename T, typename key_type>
struct Node
{
    T   *data;
    key_type *key;
    Node *left;
    Node *right;
    Node *parent;

    bool color;  //  0 == black | 1 == red
};
//
//RED Black tree requirements
//Every node has a color either red or black
//The root node is always black
//All null leaves are black
//A red node cannot have a red parent or any children
//Every path from a node to any of its descendants NULL nodes has the same number of black nodes
//
template<typename T, typename key_type,typename allocator = std::allocator<T> >
class Red_B_T
{
    typedef allocator allocator_type;
    typedef T value_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;

    public:
    void init_null_node(Node<T, key_type> *node, Node<T, key_type>* parent, T* data)
    {
        node->data = NULL;
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = black;
    }

    void preOrdering(Node<T, key_type>* node)
    {
        if(node != TNULL)
        {
            std::cout << node->data << std::endl;
            preOrdering(node->left);
            preOrdering(node->right);
        }
    }
    Node<T, key_type> create_new_node(T *data)
    {
        this->alloc = alloc();
    }
    void insert(Node<T, key_type> *node, T *data)
    {
        if(node == NULL)
        {
            return create_new_node(data);            
        }else if(data < node->data)
        {
            node->right = insert(node->left, data);
        }else if(data > node->data)
        {
            node->right = insert(node->right, data);
        }
    }
    private:
    Node<T, key_type>* root;
    Node<T, key_type>* TNULL;
    allocator alloc;
};