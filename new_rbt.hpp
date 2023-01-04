
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
    template<typename Key, typename Value, typename Compare, typename allocator = std::allocator<ft::pair<Key, Value> >  >
    class new_RBT
    {
        public:
        typedef allocator allocator_type;
        typedef ft::pair<Key, Value> value_type;
        typedef Compare key_compare;
        typedef new_RBT<value_type, key_compare, allocator_type> tree_type; 
        
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
                // alloc.destroy(this->data);
                // alloc.deallocate(this->data, 1);
            }
            Node<Data> *parent;
            Node<Data> *left;
            Node<Data> *right;
            std::allocator<Data> alloc;
            int    color;
            Data    *data;
        };

        typedef Node<value_type> node;
        typedef typename ft::rbt_iterator<Node<value_type>, tree_type> iterator;
	    typedef typename ft::const_rbt_iterator<Node<value_type>, tree_type> const_iterator;
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
        // node *internal_delete(node *root, value_type &data)
        // {
         
            // return internal_delete(root->right, *tmp->data);
        // }
        bool isBlack(node *ptr)
        {
            if(ptr && ptr->color == BLACK)
                return true;
            
            return false;
        }
        void fix_delete(node *ptr)
        {
            if(ptr == root_)
            {
                ptr->color = BLACK;
                return ;
            }

            node *sibling = ptr->parent->left;

            if(sibling == ptr)
                sibling = ptr->parent->right;
            if(sibling->color == RED)
            {
                sibling->color = BLACK;
                ptr->parent->color = RED;
                if(ptr == ptr->parent->left)
                {
                    left_rotate(ptr->parent);
                }else
                {
                    right_rotate(ptr->parent);
                }
                sibling = ptr->parent->left;
                if(sibling == ptr)
                    sibling = ptr->parent->right;
            }
            if(isBlack(sibling->left) && isBlack(sibling->right))
            {
                sibling->color = RED;
                if(ptr->parent->color == RED)
                    ptr->parent->color = BLACK;
                else
                    fix_delete(ptr->parent);
            }else{
                bool isLeft;
                if(ptr == ptr->parent->left)
                {
                    isLeft = true;
                }else{
                    isLeft = false;
                }

                if(isLeft && isBlack(sibling->right))
                {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    right_rotate(sibling);
                    sibling = ptr->parent->right;
                }else if(!isLeft && isBlack(sibling->left))
                {
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    left_rotate(sibling);
                    sibling = ptr->parent->left;
                }
                sibling->color = ptr->parent->color;
                ptr->parent->color = BLACK;
                if(isLeft)
                {
                    sibling->right->color = BLACK;
                    left_rotate(ptr->parent);
                }else{
                    sibling->left->color = BLACK;
                    right_rotate(ptr->parent);
                }
            }
        }

         node *previous(node *tmp) const
        {
            if(tmp == end_)
            {
                return maxValue_node(root_);
            }
            if(tmp->left)
                return minValue_node(tmp->left);
            
            node *ptr = tmp->parent;
            while(ptr && tmp == ptr->left)
            {
                tmp = ptr;
                ptr = ptr->parent;
            }
            return ptr;
        }

        node *next(node *tmp) const
        {
            if(tmp == maxValue_node(root_))
            {
                return end_;
            }
            if(tmp->right)
                return minValue_node(tmp->right);
            
            node *ptr = tmp->parent;
            while(ptr && tmp == ptr->right)
            {
                tmp = ptr;
                ptr = ptr->parent;
            }
            return ptr;
        }

        node *previous(node *tmp)
        {
            if(tmp == end_)
            {
                return maxValue_node(root_);
            }
            if(tmp->left)
                return minValue_node(tmp->left);
            
            node *ptr = tmp->parent;
            while(ptr && tmp == ptr->left)
            {
                tmp = ptr;
                ptr = ptr->parent;
            }
            return ptr;
        }

        node *next(node *tmp)
        {
            if(tmp == maxValue_node(root_))
            {
                return end_;
            }
            if(tmp->right)
                return minValue_node(tmp->right);
            
            node *ptr = tmp->parent;
            while(ptr && tmp == ptr->right)
            {
                tmp = ptr;
                ptr = ptr->parent;
            }
            return ptr;
        }

        void delete_node(node *ptr)
        {
            if(!ptr)
                return ;
            if(ptr->parent)
            {
                if(ptr == ptr->parent->left)
                    ptr->parent->left = NULL;
                else if(ptr == ptr->parent->right)
                    ptr->parent->right = NULL;
            }
            alloc_.destroy(ptr->data);
            alloc_.deallocate(ptr->data, 1);
            node_alloc_.deallocate(ptr, 1);
        }

        node *delete_only_child(node *ptr)
        {
            node *child;
            if(ptr->left)
                child = ptr->left;
            else if(ptr->right)
                child = ptr->right;
            else
                return NULL;
            ptr->color = child->color;
            alloc_.destroy(ptr->data);
            alloc_.construct(ptr->data, *(child->data));
            delete_node(child);
            return ptr;
        }
        
        node *delete_node_with_zero_children(node *ptr)
        {
            node *tmp;
            if(ptr->left || ptr->right)
            {
                // std::cout << "Zium " << std::endl;
                return delete_only_child(ptr);
            }
            else if(ptr->color)
            {
                delete_node(ptr);
                return NULL;
            }else{
                tmp = node_alloc_.allocate(1);
                tmp->color = BLACK;
                tmp->left = NULL;
                tmp->right = NULL;
                tmp->data = NULL;
                tmp->parent = ptr->parent;
                if(ptr == ptr->parent->left)
                    ptr->parent->left = tmp;
                else
                    ptr->parent->right = tmp;
                delete_node(ptr);

                return tmp;
            }
        }
        void delete_val(iterator pos)
        {
            node *ptr = pos.base();
            if(ptr == end_ || ptr == rend_)
                return ;
            node *tmp;
            tmp = maxValue_node(root_);
            if(ptr == tmp)
            {
                end_->parent = previous(tmp);
            }
            tmp = minValue_node(root_);
            if(ptr == tmp)
                rend_->parent = next(tmp);
            delete_val(ptr);
        }
        size_t delete_val(Key &k)
        {
            node *ptr = find_node(k);
            if(ptr == end_ || ptr == rend_)
                return 0;
            node *tmp;

            tmp = maxValue_node(root_);
            if(ptr == tmp)
                end_->parent = previous(tmp);
            tmp = minValue_node(root_);
            if(ptr == tmp)
                rend_->parent = next(tmp);
            delete_val(ptr);
            return 1;
        }
        void 
        delete_val(value_type &data)
        {
            node *ptr = find_node(data);
            if(ptr == end_ || ptr == rend_)
                return ;
            node *tmp;
            tmp = maxValue_node(root_);
            if(ptr == tmp)
            {
                end_->parent = previous(tmp);
            }
            tmp = minValue_node(root_);
            if(ptr == tmp)
                rend_->parent = next(tmp);
            delete_val(ptr);
        }

        void delete_val(node *ptr)
        {
            if(!root_->left && !root_->right && root_ != end_)
            {
                delete_node(root_);
                root_ = end_;
                size_--;
                return ;
            }

            size_--;

            node *tmp_up_node;
            bool delete_node_color;
            if(!ptr->left || !ptr->right)
            {
                
                delete_node_color = ptr->color;
                tmp_up_node = delete_node_with_zero_children(ptr);
            }else{
                node *next_node = next(ptr);
                alloc_.destroy(ptr->data);
                alloc_.construct(ptr->data, *next_node->data);
                delete_node_color = next_node->color;
                tmp_up_node = delete_node_with_zero_children(next_node);
            }
            if(delete_node_color == BLACK)
            {
                fix_delete(tmp_up_node);
            }
            if(tmp_up_node && !tmp_up_node->data)
            {
                if(tmp_up_node == tmp_up_node->parent->left)
                    tmp_up_node->parent->left = NULL;
                else if(tmp_up_node == tmp_up_node->parent->right)
                    tmp_up_node->parent->right = NULL;
                node_alloc_.deallocate(tmp_up_node, 1);
            }
        }

        void print_tree()
        {
            this->printTree_internal(root_);

        }
        // maximum value in the left subtree
        void printTree_internal(Node<value_type> *ptr)
        {
            if(ptr != NULL && ptr != end_ && ptr != rend_)
            {
                printTree_internal(ptr->left);
                std::cout << ptr->data->first << "\t" << ptr->data->second << std::endl;
                std::cout << "Color : " << ptr->color << std::endl;
                printTree_internal(ptr->right);
            }
        }

        iterator begin()
        {
            return (iterator(minValue_node(root_), end_, rend_));
        }
        
        const_iterator begin() const
        {
            return (const_iterator(minValue_node(root_), end_, rend_));
        }

        iterator end()
        {
            return (iterator(end_, end_, rend_));
        }

        const_iterator end() const
        {
            return (const_iterator(end_, end_, rend_));
        }

        iterator rend()
        {
            return (iterator(rend_, end_, rend_));
        }

        const_iterator rend() const
        {
            return (const_iterator(rend_, end_, rend_));
        }

        void clear()
        {
            internal_clear(root_);
            root_ = end_;
            size_ = 0;
        }
        void internal_clear(node *ptr)
        {
            if(!ptr || ptr == end_)
                return ;
            if(ptr->left)
                internal_clear(ptr->left);
            if(ptr->right)
                internal_clear(ptr->right);
            delete_node(ptr);
        }

        void delete_ends()
        {
            alloc_.destroy(end_->data);
            alloc_.deallocate(end_->data, 1);
            node_alloc_.deallocate(end_, 1);

            alloc_.destroy(rend_->data);
            alloc_.deallocate(rend_->data, 1);
            node_alloc_.deallocate(rend_, 1);
        }
        void swap(new_RBT &other)
        {
            node * tmp_r = root_;
            node * tmp_e = end_;
            node * tmp_rend = rend_;
            node * tmp_alloc = alloc_;
            node * tmp_node_alloc = node_alloc_;
            key_compare tcomp = compare;
            size_t tsize = size_;

            root_ = other.root_;
            end_ = other.end_;
            rend_ = other.rend_;
            alloc_ = other.alloc_;
            compare = other.compare;
            size_ = other.size_;

            other.root_ = tmp_r;
            other.end_ = tmp_e;
            other.rend_ = tmp_rend;
            other.alloc_ = tmp_alloc;
            other.node_alloc_ = tmp_node_alloc;
            other.compare = tcomp;
            other.size = tsize;
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