
#ifndef NEW_RBT_HPP
#define NEW_RBT_HPP
#include "tools.hpp"
#include <memory>
#include <iostream>
#include <functional>
#include "rbt_iter.hpp"
#define BLACK 0
#define RED 1

template<typename Data>
struct Node
{
    Node()
    {
    }

    ~Node()
    {
    }
    Node<Data> *parent;
    Node<Data> *left;
    Node<Data> *right;
    bool    color;
    Data    *data;
};


namespace ft
{
    template<typename T, typename Compare, typename allocator = std::allocator<T>  >
    class new_RBT
    {
        public:
        typedef allocator allocator_type;
        typedef T value_type;
        typedef Compare key_compare;
        typedef new_RBT<T, key_compare, allocator_type> tree_type; 
        typedef Node<value_type> node;
        typedef typename ft::rbt_iterator<node , tree_type> iterator;
	    typedef typename ft::const_rbt_iterator<node , tree_type> const_iterator;

     
        new_RBT(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        {
            compare = comp;
            alloc_ = alloc;
            size_ = 0;
            create_ends();
            root_ = end_;

        }
        new_RBT &operator= (const new_RBT &rhs)
        {
            this->clear();
            compare = rhs.getCompare();
            this->alloc_ = rhs.alloc_;
            this->size_ = rhs.size_;
            if(rhs.getRoot() != rhs.getEnd())
            {
                this->root_ = this->node_alloc_.allocate(1);
                this->root_->parent = NULL;
                this->root_->left = NULL;
                this->root_->right = NULL;
                this->root_->color = BLACK;
                this->root_->data = alloc_.allocate(1);
                this->alloc_.construct(root_->data, *(rhs.getRoot()->data));
                this->copy_stuff(this->root_, rhs.getRoot());
            }
            end_->parent = this->maxValue_node(this->root_);
            rend_->parent = this->minValue_node(this->root_);
            return *this;
        }

        void copy_stuff(node *ptr, node *rhs)
        {
            if(rhs->left)
            {
                ptr->left = node_alloc_.allocate(1);
                ptr->left->parent = ptr;
                ptr->left->left = NULL;
                ptr->left->right = NULL;
                ptr->left->color = rhs->left->color;
                ptr->left->data = this->alloc_.allocate(1);
                this->alloc_.construct(ptr->left->data, *(rhs->left->data));
                copy_stuff(ptr->left, rhs->left);

            }
            if(rhs->right)
            {
                ptr->right = node_alloc_.allocate(1);
                ptr->right->parent = ptr;
                ptr->right->left = NULL;
                ptr->right->right = NULL;
                ptr->right->color = rhs->right->color;
                ptr->right->data = this->alloc_.allocate(1);
                this->alloc_.construct(ptr->right->data, *(rhs->right->data));
                copy_stuff(ptr->right, rhs->right);
            }
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

            if(right_child->left)
            {
                right_child->left->parent = ptr;
            }

            right_child->parent = ptr->parent;

            if(ptr->parent == NULL)
            {
                root_ = right_child;
            }else if(ptr == ptr->parent->left)
            {
                ptr->parent->left = right_child;
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

            if(left_child->right != NULL)
            {
                left_child->right->parent = ptr;
            }

            left_child->parent = ptr->parent;

            if(ptr->parent == NULL)
            {
                root_ = left_child;
            }else if(ptr == ptr->parent->right)
            {
                ptr->parent->right = left_child;
            }else
            {
                ptr->parent->left = left_child;
            }

            left_child->right = ptr;
            ptr->parent = left_child;
        }

        void create_ends()
        {
            end_ = node_alloc_.allocate(1);
            end_->data = alloc_.allocate(1);
            alloc_.construct(end_->data);
            end_->color = BLACK;
            end_->parent = NULL;
            end_->left = NULL;
            end_->right = NULL;
            rend_ = node_alloc_.allocate(1);
            rend_->data = alloc_.allocate(1);
            alloc_.construct(rend_->data);
            rend_->color = BLACK;
            rend_->parent = NULL;
            rend_->left = NULL;
            rend_->right = NULL;
        }

        node *maxValue_node(node *ptr) const
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

        node *minValue_node(node *ptr) const
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
        Compare getCompare() const
        {
            return compare;
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
        template<typename Key>
        node *find_node(Key val) const
        {
           node * current = this->root_;
            if (current == this->end_)
                return (this->end_);
            while (current)
            {
                if (val == current->data->first)
                    return (current);
                else if (this->compare(val , current->data->first))
                {
                    if (current->left)
                        current = current->left;
                    else
                        return (this->end_);
                }
                else
                {
                    if (current->right)
                        current = current->right;
                    else
                        return (this->end_);
                }
            }
            return (this->end_);
        }
        
        node *find_node(value_type val) const
        {
            node * current = this->root_;
            if (current == this->end_)
                return (this->end_);
            while (current)
            {
                if (val.first == current->data->first)
                    return (current);
                else if (this->compare(val.first, current->data->first))
                {
                    if (current->left)
                        current = current->left;
                    else
                        return (this->end_);
                }
                else
                {
                    if (current->right)
                        current = current->right;
                    else
                        return (this->end_);
                }
            }
            return (this->end_);
        }

        void    insert_helper(node *ptr)
        {
            node * current = this->root_;
            while (current)
            {
                if (this->compare(ptr->data->first, current->data->first))
                {
                    if (current->left)
                    {
                        current = current->left;
                    }
                    else
                    {
                        current->left = ptr;
                        ptr->parent = current;
                        return ;
                    }
                }
                else
                {
                    if (current->right)
                    {
                        current = current->right;
                    }
                    else
                    {
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
        size_t max_size() const
        {
            return alloc_.max_size();
        }
        size_t size() const
        {
            return size_;
        }
        node * insert(value_type val)
        {
           node * temp = find_node(val);
            if (temp != this->end_)
                return (temp);
            this->size_++;
            node * newnode = this->node_alloc_.allocate(1);
            node * org = newnode;
            newnode->data = this->alloc_.allocate(1);
            this->alloc_.construct(newnode->data, val);
            newnode->parent = NULL;
            newnode->left = NULL;
            newnode->right = NULL;
            if (this->root_ == this->end_)	//Case 1: Tree is empty - insert at root and make black
            {
                newnode->color = BLACK;
                newnode->parent = NULL;
                this->root_ = newnode;
                this->end_->parent = this->root_;
                this->rend_->parent = this->root_;
                
                return (newnode);
            }
            newnode->color = RED;
            insert_helper(newnode);
            
            //Case 2: Parent is black - nothing to be done
            // std::cout << newnode->color << std::endl;
            // if(newnode->parent && newnode->parent->color == RED) 
            //     std::cout << "Other ones " << newnode->parent->color << std::endl;
            // else{
            //     std::cout << "Black ones " << newnode->parent->color << std::endl;
            // }
            while (newnode->parent && newnode->parent->color == RED )		//Case 3: Parent is red
            {
                if (newnode->parent->parent->left && newnode->parent->parent->right && newnode->parent->parent->left->color == RED 
			        && newnode->parent->parent->right->color == RED)
                {
                    
                    if (newnode->parent->parent != this->root_)
                        change_color(newnode->parent->parent);
                    
                    change_color(newnode->parent->parent->right);
                    change_color(newnode->parent->parent->left);
                    newnode = newnode->parent->parent;
                }
                else	//Case 3.2: Parent is red and Uncle is black or NULL 
                {
                    
                    if (newnode->parent == newnode->parent->parent->right)	//Parent is right child of Grandparent
                    {
                        if (newnode == newnode->parent->left) //Case 3.2.2: Parent is right child of Grandparent and newnode is left child of Parent - right rotate to get to Case 3.2.1
                        {
                            newnode = newnode->parent;
                            right_rotate(newnode);
                        }
                        //Case 3.2.1: Parent is right child of Grandparent and newnode is right child of Parent - left rotation at Grandparent, change (new) Sibling to red and Parent to Black
                        left_rotate(newnode->parent->parent);
                        change_color(newnode->parent);
                        change_color(newnode->parent->left);
                    }
                    else
                    {
                        if (newnode == newnode->parent->right) //Case 3.2.4: Mirrored version of 3.2.2
                        {
                            newnode = newnode->parent;	
                            left_rotate(newnode);
                        }
                        right_rotate(newnode->parent->parent);
                        change_color(newnode->parent);
                        change_color(newnode->parent->right);
                    }
                    
                    // std::cout << "Kurwa 3"<< std::endl; 
                    // std::cout << newnode->data->first << std::endl;
                }
                // std::cout << "Chuj 2" << std::endl;
                // std::cout << newnode->data->first << std::endl;
           
            }
    
            this->end_->parent = this->maxValue_node(this->root_);
         
            this->rend_->parent = this->minValue_node(this->root_);
            // print_tree();
            return (org);
        }

        //Deleting 
        // node *internal_delete(node *root, value_type &data)
        // {
         
            // return internal_delete(root->right, *tmp->data);
        // }
        bool isBlack(node *ptr)
        {            
            return (!ptr || ptr->color == BLACK);
        }
        void fix_delete(node *ptr)
        {
            if (ptr == this->root_)
            {
                ptr->color = BLACK;	
                return ;
            }
            node * sibling = ptr->parent->left;
            if (sibling == ptr)
                sibling = ptr->parent->right;
            if (sibling->color == RED)
            {
                sibling->color = BLACK;
                ptr->parent->color = RED;
                if (ptr == ptr->parent->left)
                    left_rotate(ptr->parent);
                else
                    right_rotate(ptr->parent);
                sibling = ptr->parent->left;
                if (sibling == ptr)
                    sibling = ptr->parent->right;
            }
            if (isBlack(sibling->left) && isBlack(sibling->right))
            {
                sibling->color = RED;
                if (ptr->parent->color == RED)
                    ptr->parent->color = BLACK;
                else
                    fix_delete(ptr->parent);
            }
            else
            {
                bool isLeft = (ptr == ptr->parent->left);
                if (isLeft && isBlack(sibling->right))
                {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    right_rotate(sibling);
                    sibling = ptr->parent->right;
                }
                else if (!isLeft && isBlack(sibling->left))
                {
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    left_rotate(sibling);
                    sibling = ptr->parent->left;
                }
                sibling->color = ptr->parent->color;
                ptr->parent->color = BLACK;
                if (isLeft)
                {
                    sibling->right->color = BLACK;
                    left_rotate(ptr->parent);
                }
                else
                {
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
        template<typename Key>
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
            if (!this->root_->left && !this->root_->right && this->root_ != this->end_)
            {
                delete_node(this->root_);
                this->root_ = this->end_;
                this->size_--;
                return ;
            }
            this->size_--;
            node * movedupnode;
            bool deletednodecolour;
            if (!ptr->left || !ptr->right)
            {
                deletednodecolour = ptr->color;
                movedupnode = delete_node_with_zero_children(ptr);
            }
            else
            {
                node * successor = this->next(ptr);
                this->alloc_.destroy(ptr->data);
                this->alloc_.construct(ptr->data, *(successor->data));
                deletednodecolour = successor->color;
                movedupnode = delete_node_with_zero_children(successor);
            }
            if (deletednodecolour == BLACK)
            {
                fix_delete(movedupnode);
            }
            if (movedupnode && !movedupnode->data)
            {
                if (movedupnode == movedupnode->parent->left)
                    movedupnode->parent->left = NULL;
                else if (movedupnode == movedupnode->parent->right)
                    movedupnode->parent->right = NULL;
                this->node_alloc_.deallocate(movedupnode, 1);
            }

        }

        void print_tree()
        {
            this->printTree_internal("", root_, false);

        }
        // maximum value in the left subtree
        void printTree_internal(const std::string& prefix, Node<value_type> *ptr, bool isLeft)
        {
            if( ptr != NULL )
            {
                std::cout << prefix;

                std::cout << (isLeft ? "├──" : "└──" );

                // print the value of the node
                std::cout << ptr->data->first << std::endl;

                // enter the next tree level - left and right branch
                printTree_internal( prefix + (isLeft ? "│   " : "    "), ptr->left, true);
                printTree_internal( prefix + (isLeft ? "│   " : "    "), ptr->right, false);
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
            allocator_type tmp_alloc = alloc_;
            std::allocator<Node<value_type> > tmp_node_alloc = node_alloc_;
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
            other.size_ = tsize;
        }
        private:
        node *root_;
        node *end_;
        node *rend_;
        node *nil_;
        size_t size_;
        std::allocator<Node<value_type> > node_alloc_;
        allocator_type alloc_;
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