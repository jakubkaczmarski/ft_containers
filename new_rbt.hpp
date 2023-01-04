
#ifndef NEW_RBT_HPP
#define NEW_RBT_HPP
#include "tools.hpp"
#include <memory>
#include <iostream>
#include <functional>
#include "rbt_iter.hpp"
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
            Node()
            {
                // this->data = alloc.allocate(1);
                // alloc.construct(this->data, val);
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
                alloc.destroy(this->data);
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
            size_ = 0;
            create_ends();
            root_ = end_;

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

        void create_ends()
        {
            end_ = node_alloc_.allocate(1);
            end_->data = end_->alloc.allocate(1);
            end_->alloc.construct(end_->data);
            end_->color = BLACK;
            end_->parent = NULL;
            end_->left = NULL;
            end_->right = NULL;
            
            rend_ = node_alloc_.allocate(1);
            rend_->data = end_->alloc.allocate(1);
            rend_->alloc.construct(end_->data);
            rend_->color = BLACK;
            rend_->parent = NULL;
            rend_->left = NULL;
            rend_->right = NULL;
        }

        node *maxValue_node(node *ptr)
        {
            node * tmp;
            tmp = ptr;

            if(!root_)
            {
                return end_;
            }
            while(tmp->right)
            {
                tmp = tmp->right;
            }
            return tmp;
        }

        node *minValue_node(node *ptr)
        {
            node *tmp = ptr;
            if(!root_)
                return end_;
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

        node *getEnd() const
        {
            return end_;
        }

        node *getRend() const
        {
            return rend_;
        }

        node *getRoot() const
        {
            return root_;
        }

        node *getAlloc() const
        {
            return alloc_;
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
            if(compare(ptr->data->first, root->data->first))
            {
                root->left = internal_insert(root->left, ptr);
                root->left->parent = root;
            }else if(compare(root_->data->first, ptr->data->first))
            {
                root->right = internal_insert(root->right, ptr);
                root->right->parent = root;
            }

            return root;
        }

        node *find_node(Key val) const
        {
            node * current = root_;
            if(current == end_)
                return end_;
            while(current)
            {
                if(val == current->data->first)
                {
                    return current;
                }else if(compare(val, current->data->first))
                {
                    if(current->left)
                        current = current->left;
                    else
                        return end_;
                }else{
                    if(current->right)
                        current = current->right;
                    else
                        return end_;
                }
            }
            return end_;
        }

        node *find_node(value_type val) const
        {
            node * current = root_;
            if(current == end_)
                return end_;
            while(current)
            {
                if(val.first == current->data->first)
                {
                    return current;
                }else if(compare(val.first, current->data->first))
                {
                    if(current->left)
                        current = current->left;
                    else
                        return end_;
                }else{
                    if(current->right)
                        current = current->right;
                    else
                        return end_;
                }
            }
            return end_;
        }

        void    insert_helper(node *ptr)
        {
            node *current = root_;
            while(current)
            {
                if(compare(ptr->data->first, current->data->first))
                {
                    if(current->left)
                    {
                        current = current->left;
                    }else{
                        current->left = ptr;
                        ptr->parent = current;
                        return ; 
                    }
                }else
                {
                    if(current->right)
                    {
                        current = current->right;
                    }else{
                        current->right = ptr;
                        ptr->parent = current;
                        return ;
                    }
                }
            }
        }
        void change_color(node *ptr)
        {
            if(!ptr)
            {
                return ;
            }
            ptr->color = !ptr->color;
        }
        node * insert(value_type &val)
        {
            node *tmp = find_node(val);
            if(tmp != end_)
                return tmp;
            size_++;
            node *new_node = node_alloc_.allocate(1);
            node *ptr = new_node;
            new_node->data = alloc_.allocate(1);
            alloc_.construct(new_node->data, val);
            new_node->parent = NULL;
            new_node->left = NULL;
            new_node->right = NULL;
            if(root_ == end_)
            {
                new_node->color = BLACK;
                new_node->parent = NULL;
                root_ = new_node;
                end_->parent = root_;
                rend_->parent = root_;
                return new_node;
            }
            new_node->color = RED;

            insert_helper(new_node);

            while(new_node->parent && new_node->parent->color == RED)
            {
                if(new_node->parent->parent->left && new_node->parent->parent->right && new_node->parent->parent->left->color == RED
                && new_node->parent->parent->right->color == RED)
                {
                    if(new_node->parent->parent != root_)
                    {
                        change_color(new_node->parent->parent);
                    }
                    change_color(new_node->parent->parent->right);
                    change_color(new_node->parent->parent->left);
                    new_node = new_node->parent->parent;
                }else{
                    if(new_node->parent == new_node->parent->parent->right)
                    {
                        if(new_node == new_node->parent->left)
                        {
                            new_node = new_node->parent;
                            right_rotate(new_node);
                        }
                        left_rotate(new_node->parent->parent);
                        change_color(new_node->parent);
                        change_color(new_node->parent->left);
                    }else
                    {
                        if(new_node == new_node->parent->right)
                        {
                            new_node = new_node->parent;
                            left_rotate(new_node);
                        }
                        right_rotate(new_node->parent->parent);
                        change_color(new_node->parent);
                        change_color(new_node->parent->right);
                    }
                }
            }
            end_->parent = maxValue_node(root_);
            rend_->parent = minValue_node(root_);
            return ptr;
        }

        //Deleting 
        node *internal_delete(node *root, value_type &data)
        {
            if(root == NULL)
                return root;
            if(compare(data.first, root->data->first))
            {
                return internal_delete(root->left, data);
            }
            if(compare(root->data->first ,data.first))
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
                    node_alloc_.destroy(ptr);
                    node_alloc_.deallocate(ptr, 1);
                }else{
                    ptr->parent->right = child;
                    if(child != nullptr)
                    {
                        child->parent = ptr->parent;
                    }
                    set_color(child, BLACK);

                    node_alloc_.destroy(ptr);
                    node_alloc_.deallocate(ptr, 1);
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
                
                node_alloc_.destroy(ptr);
                node_alloc_.deallocate(ptr, 1);
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

        rbt_iterator<node, new_RBT> begin()
        {
            node *tmp = root_;
            while(tmp != NULL && tmp->left != NULL)
            {
                tmp = tmp->left;
            }
            // return rbt_iterator<node, new_RBT>(tmp,)
        }

        private:
        node *root_;
        node *end_;
        node *rend_;
        node *nil_;
        int size_;
        std::allocator<Node<value_type> > node_alloc_;
        std::allocator<value_type> alloc_;
        Compare						compare;
    };
    
}


#endif



        // void fix_insert(node *ptr)
        // {
        //     node *parent = NULL;
        //     node *grandparent = NULL;

        //     while(ptr != root_ && getColor(ptr) == RED && getColor(ptr->parent) == RED)
        //     {
        //         parent = ptr->parent;
        //         grandparent = parent->parent;

        //         if(parent == grandparent->left)
        //         {
        //             node *uncle = grandparent->right;
        //             if(getColor(uncle) == RED)
        //             {
        //                 set_color(uncle, BLACK);
        //                 set_color(parent, BLACK);
        //                 set_color(grandparent, RED);
        //                 ptr = grandparent;
        //             }else
        //             {
        //                 if(ptr == parent->right)
        //                 {
        //                     left_rotate(parent);
        //                     ptr = parent;
        //                     parent = ptr->parent;
        //                 }
        //                 right_rotate(grandparent);
        //                 swap(parent->color, grandparent->color);
        //                 ptr = parent;
        //             }
        //         }else
        //         {
        //             node *uncle = grandparent->left;
        //             if(getColor(uncle) == RED)
        //             {
        //                 set_color(uncle, BLACK);
        //                 set_color(parent, BLACK);
        //                 set_color(grandparent, RED);
        //                 ptr = grandparent;
        //             }else{
        //                 if(ptr == parent->left)
        //                 {
        //                     right_rotate(parent);
        //                     ptr = parent;
        //                     parent = ptr->parent;
        //                 }
        //                 left_rotate(grandparent);
        //                 swap(parent->color, grandparent->color);
        //                 ptr = parent;
        //             }
        //         }
        //     }
        //     set_color(root_, BLACK);
        // }