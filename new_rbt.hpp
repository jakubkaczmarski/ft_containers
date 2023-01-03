
#include "tools.hpp"
#include <memory>
#include <iostream>
#include <functional>

#define BLACK 0
#define RED 1
#define DOUBLE_BLACK 2
namespace ft
{
    template<typename Key, typename Value, typename allocator = std::allocator<ft::pair<Key, Value> >, typename Compare = std::less<Key> >
    class new_RBT
    {
        public:
        typedef allocator allocator_type;
        typedef ft::pair<Key, Value> value_type;
        
        template<typename Data>
        struct Node
        {
            Node(Data val)
            {
                this->data = alloc.allocate(1);
                alloc.construct(this->data, val);
               parent = NULL;
                left = NULL;
                right = NULL;
            }
            void construct()
            {
                parent = NULL;
                left = NULL;
                right = NULL;
                data = NULL;
            }
            ~Node()
            {
                alloc.deallocate(this->data, 1);
            }
            Node<Data> *parent;
            Node<Data> *left;
            Node<Data> *right;
            std::allocator<Data> alloc;
            int    color;
            Data    *data;
        };

        typedef Node<value_type> node;
        new_RBT()
        {
            // nil_ = node_alloc.allocate(1);
            // node_alloc.construct(nil_,s);
            // nil_->construct();
            root_ = NULL;
        }
        void swap(int &color1, int &color2)
        {
            int tmp = color1;
            color1 = color2;
            color2 = tmp;
        }
        ~new_RBT()
        {
        }

        void left_rotate(node *ptr)
        {
            node *right_child = ptr->right;
            ptr->right = right_child->left;

            if(ptr->right != NULL)
            {
                ptr->right->parent = ptr;
            }

            right_child->parent = ptr->parent;

            if(ptr->parent == NULL)
            {
                root_ = right_child;
            }else if(ptr == ptr->parent->left)
            {
                ptr->parent->right = right_child;
            }else{
                ptr->parent->right = right_child;
            }
            
            right_child->left = ptr;
            ptr->parent = right_child;
        }
    
        void right_rotate(node *ptr)
        {
            node *left_child = ptr->left;
            ptr->left = left_child->right;

            if(ptr->left != NULL)
            {
                ptr->left->parent = ptr;
            }

            left_child->parent = ptr->parent;

            if(ptr->parent == NULL)
            {
                root_ = left_child;
            }else if(ptr == ptr->parent->left)
            {
                ptr->parent->left = left_child;
            }else
            {
                ptr->parent->right = left_child;
            }

            left_child->right = ptr;
            ptr->parent = left_child;
        }

        node *minValue_node(node *ptr)
        {
            node *tmp = ptr;
            while(tmp->left != NULL)
            {
                tmp = tmp->left;
            }
            return tmp;
        }
        int getColor(node *ptr)
        {
            if(ptr == NULL)
            {
                return BLACK;
            }else{
                return ptr->color;
            }
        }

        void set_color(node *ptr, int color)
        {
            if(ptr == NULL)
            {
                return ;
            }else{
                ptr->color = color;
            }
        }

        node *internal_insert(node *root, node *ptr)
        {
            if(root == NULL)
                return ptr;
            //Change to compare here
            if(ptr->data->first < root->data->first)
            {
                root->left = internal_insert(root->left, ptr);
                root->left->parent = root;
            }else if(ptr->data->first > root_->data->first)
            {
                root->right = internal_insert(root->right, ptr);
                root->right->parent = root;
            }

            return root;
        }

        void insert(value_type &val)
        {
            //Allocate for node 
            std::cout << "Zium" << std::endl;
            node * ptr = new Node<value_type> (val);
            std::cout << "Zium" << std::endl;
            root_ = internal_insert(root_, ptr);
            fix_insert(ptr);
        }

        void fix_insert(node *ptr)
        {
            node *parent = NULL;
            node *grandparent = NULL;

            while(ptr != root_ && getColor(ptr) == RED && getColor(ptr->parent) == RED)
            {
                parent = ptr->parent;
                grandparent = parent->parent;

                if(parent == grandparent->left)
                {
                    node *uncle = grandparent->right;
                    if(getColor(uncle) == RED)
                    {
                        set_color(uncle, BLACK);
                        set_color(parent, BLACK);
                        set_color(grandparent, RED);
                        ptr = grandparent;
                    }else
                    {
                        if(ptr == parent->right)
                        {
                            left_rotate(parent);
                            ptr = parent;
                            parent = ptr->parent;
                        }
                        right_rotate(grandparent);
                        swap(parent->color, grandparent->color);
                        ptr = parent;
                    }
                }else
                {
                    node *uncle = grandparent->left;
                    if(getColor(uncle) == RED)
                    {
                        set_color(uncle, BLACK);
                        set_color(parent, BLACK);
                        set_color(grandparent, RED);
                        ptr = grandparent;
                    }else{
                        if(ptr == parent->left)
                        {
                            right_rotate(parent);
                            ptr = parent;
                            parent = ptr->parent;
                        }
                        left_rotate(grandparent);
                        swap(parent->color, grandparent->color);
                        ptr = parent;
                    }
                }
            }
            set_color(root_, BLACK);
        }




        //Deleting 
        node *internal_delete(node *root, value_type &data)
        {
            if(root == NULL)
                return root;
            if(data.first < root->data->first)
            {
                return internal_delete(root->left, data);
            }
            if(data.first > root->data->first)
            {
                return internal_delete(root->right, data);
            }
            if(root->left == NULL || root->right == NULL)
                return root;
            
            node *tmp = minValue_node(root->right);
            //Need to free here

            root->data = tmp->data;

            return internal_delete(root->right, *tmp->data);
        }

        void fix_delete(node *ptr)
        {
            if(ptr == NULL)
            {
                return ;
            }
            if(ptr == root_)
            {
                root_ = NULL;
                return ;
            }
            
            if(getColor(ptr) == RED || getColor(ptr->left) == RED || getColor(ptr->right) == RED)
            {
                
                node *child;
                if(ptr->left != NULL)
                {
                    child = ptr->left;
                }else{
                    child = ptr->right;
                }

                if(ptr == ptr->parent->left)
                {
                    ptr->parent->left = child;
                    if(child != NULL)
                    {
                        child->parent = ptr->parent;
                    }
                    set_color(child, BLACK);
                    //freeing
                    delete ptr;
                }else{
                    ptr->parent->right = child;
                    if(child != nullptr)
                    {
                        child->parent = ptr->parent;
                    }
                    set_color(child, BLACK);
                    
                    delete ptr;
                }
            }else
            {
                
                node *sibling = NULL;
                node *parent = NULL;
                node *tmp = ptr;

                set_color(tmp, DOUBLE_BLACK);
                while(tmp != root_ && getColor(tmp) == DOUBLE_BLACK)
                {
                    
                    std::cout << "Siemanko 3 " << std::endl;
                    parent = tmp->parent;
                    if(tmp == parent->left)
                    {
                        sibling = parent->right;
                        if(getColor(sibling) == RED)
                        {
                            set_color(sibling, BLACK);
                            set_color(parent, RED);
                            left_rotate(parent);
                        }else
                        {
                            if(getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK)
                            {
                                set_color(sibling, RED);
                                if(getColor(parent) == RED)
                                {
                                    set_color(parent, BLACK);
                                }else
                                {
                                    set_color(parent, DOUBLE_BLACK);
                                }
                                tmp = parent;
                            }else
                            {
                                if(getColor(sibling->right) == BLACK)
                                {
                                    set_color(sibling->left, BLACK);
                                    set_color(sibling, RED);
                                    right_rotate(sibling);
                                    sibling = parent->right;
                                }
                                set_color(sibling, parent->color);
                                set_color(parent, BLACK);
                                set_color(sibling->right, BLACK);
                                left_rotate(parent);
                                break;
                            }
                        }
                    }else
                    {
                        sibling = parent->left;
                        if(getColor(sibling) == RED)
                        {
                            set_color(sibling, BLACK);
                            set_color(parent, RED);
                            right_rotate(parent);
                        }else
                        {
                            if(getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK)
                            {
                                set_color(sibling, RED);
                                if(getColor(parent) == RED)
                                    set_color(parent, BLACK);
                                else
                                    set_color(parent, DOUBLE_BLACK);
                                tmp = parent;
                            }else{
                                if(getColor(sibling->left) == BLACK)
                                {
                                    set_color(sibling->right, BLACK);
                                    set_color(sibling, RED);
                                    left_rotate(sibling);
                                    sibling = parent->left;
                                }
                                set_color(sibling, parent->color);
                                set_color(parent, BLACK);
                                set_color(sibling->left, BLACK);
                                right_rotate(parent);
                                break;
                            }
                        }
                    }
                }
                
                if(ptr == ptr->parent->left)
                {
                    ptr->parent->left = NULL;
                }else{
                    ptr->parent->right = NULL;
                }
                
                delete ptr;
                set_color(root_, BLACK);
            }

            
        }
        void 
        delete_val(value_type &data)
        {
            node *ptr = internal_delete(root_, data);
            fix_delete(ptr);
        }



        void print_tree()
        {
            this->printTree_internal(root_);

        }
        // maximum value in the left subtree
        void printTree_internal(Node<value_type> *node)
        {
            if(node != NULL)
            {
                printTree_internal(node->left);
                std::cout << node->data->first << "\t" << node->data->second << std::endl;
                std::cout << "Color : " << node->color << std::endl;
                printTree_internal(node->right);
            }
        }


        private:
        node *root_;
        node *nil_;
        std::allocator<node> node_alloc;
    };
    
}