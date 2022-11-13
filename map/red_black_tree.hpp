#include <memory>
#include "../additional.hpp"

#include <iostream>
//key + Value pair in a content area
//and then compare keys
enum color{
    red,
    black,
};

template<typename T>
struct Node
{
    T*       pair_;
    Node *parent;
    Node *right;
    Node *left;
    int color;
};

template <typename T>
class RBT
{
    public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef struct Node<T> t_node;
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
    t_node *smaller_el(t_node *ptr)
    {
        if(ptr->right != nullnode)
        {
            return min(ptr->right);
        }
        t_node *y = ptr->parent;
        while(y != nullnode && ptr == y->right)
        {
            ptr = y;
            y = y->right;
        }
        return  y;
    }
    t_node *max(t_node *ptr)
    {
        while(ptr->right != nullnode)
        {
            ptr = ptr->right;
        }
        return ptr;
    }
    t_node *prev_el(t_node *ptr)
    {
        if(ptr->left != nullnode)
        {
            return max(ptr->right);
        }
        t_node *y = ptr->parent;
        while(y != nullnode && ptr == y->left)
        {
            ptr = y;
            y = y->right;
        }
        return  y;
    }
    t_node * search_key(t_node *node, T *key)
    {
        if(key->first == node->key.first || node == nullnode)
        {
            return node;
        }
        if(key->first < node->key->first)
        {
            return search_key(node->left, key->first);
        }
        return search_key(node->right, key->first);
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

    void  put_right_side(t_node *u, t_node *v)
    {
        if(u->parent == nullptr)
        {
            root = v;
        }else if(u == u->parent->left)
        {
            u->parent->left = v;
        }else{
            u->parent->right = v;
        }
        v->parent = u->parent;
    }
    t_node *min(t_node *ptr)
    {
        while(ptr->left != nullnode)
        {
            ptr = ptr->left;
        }
        return ptr;
    }
    //balance tree
    void fix_delete(t_node *ptr)
    {
        t_node *s;
        while(ptr != root && ptr->color == 0)
        {
            if(ptr == ptr->parent->left)
            {
                s = ptr->parent->right;
                if(s->color == 1 )
                {
                    s->color = 0;
                    ptr->parent->color = 1;
                    rot_left(ptr->parent);
                    s = ptr->parent->right;
                }
                if(s->left->color == 0 && s->right->color == 0)
                {
                    s->color = 1;
                    ptr = ptr->parent;
                }else
                {
                    if(s->right->color == 0)
                    {
                        s->left->color = 0;
                        s->color = 1;
                        rot_right(s);
                        s = ptr->parent->right;
                    }
                    s->color = ptr->parent->color;
                    ptr->parent->color = 0;
                    s->right->color = 0;
                    rot_left(ptr->parent);
                    ptr = root;
                }
            }else{
                s = ptr->parent->left;
                if(s->color == 1)
                {
                    s->color = 0;
                    ptr->parent->color = 1;
                    rot_right(ptr->parent);
                    s = ptr->parent->left;
                }
                if(s->right->color == 0 && s->right->color == 0)
                {
                    s->color = 1;
                    ptr = ptr->parent;
                }else{
                    if(s->left->color == 0)
                    {
                        s->right->color = 0;
                        s->color = 1;
                        rot_left(s);
                        ptr = root;
                    }
                }
            }
            ptr->color = 0;
        }

    }
    void delete_node_thingy(t_node *ptr , T key)
    {
        t_node *z = nullnode;
        t_node *x;
        t_node *y;
        while(ptr != nullnode)
        {
            if(ptr->key == key)
            {
                z = ptr;
            }
            if(ptr->key <= key)
            {
                ptr = ptr->right;
            }else
            {
                ptr = ptr->left;
            }
        }
        if(z == nullnode)
        {
            std::cout << "Element doens't exist" << std::endl;
            return ;
        }

        y = z;
        int tmp_color = y->color;
        if(z->left == nullnode)
        {
            x = z->right;
            put_right_side(z, z->right);
        }else if(z->right == nullnode)
        {
            x = z->left;
            put_right_side(z, z->left);
        }else{
            y = min(z->right);
            tmp_color = y->color;
            x = y->right;
            if(y->parent == z)
            {
                x->parent = y;
            }else{
                put_right_side(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
                put_right_side(z, y);
                y->left = z->left;
                y->left->parent = y;
                y->color = z->color;
        }
        delete z;
        if(tmp_color == 0)
        {
            fix_delete(x);
        }

    }
    void    delete_element(T key)
    {
        delete_node_thingy(this->root, key);
    }

    void    insert(T key)
    {
        t_node *ptr = new t_node;
        ptr->parent = nullptr;
        std::allocator<value_type> alloc;
        ptr->pair_ = alloc.allocate(1);
        *ptr->pair_ =  key;
        ptr->left = nullnode;
        ptr->right = nullnode;
        ptr->color = 1;
        t_node * y = nullptr;
        t_node *x = this->root;

        while(x != nullnode)
        {
            y = x;
            if(ptr->pair_ < x->pair_)
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
        }else if(ptr->pair_ < y ->pair_)
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
        print_tree_help(root->right, del, true);
        }
    }
};

