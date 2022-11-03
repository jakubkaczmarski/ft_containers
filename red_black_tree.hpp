#include <iostream>
#include <memory>

enum color{
        black,
        red
    };
template<typename T>
struct Node
{
    T   *data;
    key_type *key;
    Node *left;
    Node *right;
    Node *parent;

    bool color;  //  0 == black | 1 == red
};
template<typename T, typename allocator = std::allocator<T> >
class Red_B_T
{
    typedef allocator allocator_type;
    typedef T value_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;

    public:
    void init_null_node(*Node<T> node, *Node<T> parent, T* data)
    {
        node->data = NULL;
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = black;
    }

    void preOrdering(*Node<T> node)
    {
        if(node != TNULL)
        {
            std::cout << node->data << std::endl;
            preOrdering(node->left);
            preOrdering(node->right);
        }
    }
    
    private:
    *Node<T> root;
    *Node<T> TNULL;
    allocator alloc;
};