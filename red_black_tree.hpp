#include <iostream>
#include <memory>

enum color{
    red,
    black,
};

template<typename T, typename data>
struct Node
{
    T       key;
    // data    data;
    Node *parent;
    Node *right;
    Node *left;
    int color;
};

template <typename T, typename data>
class RBT
{
    public:
    typedef struct Node<T, data> t_node;
    t_node * get_root()
    {
        return root;
    }
    RBT()
    {
        nullnode = new t_node;
        nullnode->color = 0;
        nullnode->left = nullptr;
        nullnode->right = nullptr;
        root = nullnode;
    }
    
    t_node * search_key(t_node *node, T key)
    {
        if(key == node->key || node == nullnode)
        {
            return node;
        }
        if(key < node->key)
        {
            return search_key(node->left, key);
        }
        return search_key(node->right, key);
    }

    t_node *search(T key)
    {
        return search_key(root, key);
    }
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
                    std::cout << "Rot 1" << std::endl ;
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
                std::cout << "Rot 2" << std::endl ;
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
            }
                if(ptr == root)
                {
                    break;
                }
        }
        root->color = 0;

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


    void    insert(T key)
    {
        t_node *ptr = new t_node;
        ptr->parent = nullptr;
        ptr->key = key;
        ptr->left = nullnode;
        ptr->right = nullnode;
        ptr->color = 1;
        t_node * y = nullptr;
        t_node *x = this->root;

        while(x != nullnode)
        {
            y = x;
            if(ptr->key < ptr->key)
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
        }else if(ptr->key < y ->key)
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
        std::cout << "Zium " << std::endl;
        sort_insert(ptr);
        std::cout << "Brum" << std::endl;
    } 
    void print_tree()
    {
        this->print_tree_help(root, "", true);
    }
    private:
    t_node *root;
    t_node *nullnode;

    void print_tree_help(t_node *root, std::string del, bool last)
    {
        if(root != nullnode)
        {
            std::cout << del;
            if(last)
            {
                std::cout << "R----";
                del += "    ";
            }else{
                std::cout << "L----";
                del += "|   ";
            }
        std::string sCol = root->color ? "RED" : "BLACK";
        std::cout << root->key << "(" << sCol << ")" << std::endl;
        print_tree_help(root->left, del, false);
        // std::cout << "Zium22";
        print_tree_help(root->right, del, true);
        }
    }
};

