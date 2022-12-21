#include "tools.hpp"
#include "rbt_iter.hpp"
#include <memory>
#include <iostream>

#define BLACK true
#define RED false

#define left 0
#define right 1

namespace ft
{
    template <typename Key, typename Value,
        typename allocator = std::allocator<ft::pair<Key, Value> >, typename Compare = std::less<Key> >
    class RBT
    {
        typedef allocator  allocator_type;
        typedef ft::pair<Key, Value> value_type;

        public:

        template <typename Data, typename allocator_type>
        struct Node
        {
            Node()
            {

            }

            void init(Data &data, int color, allocator_type &alloc_)
            {
                this->color = color;
                this->child[left] = NULL;
                this->child[right] = NULL;
                printf("Constructor ran\n");
            }

            Data *data;
            int color;  
            Node *child[2];
        };
        RBT()
        {
            this->root_ = NULL;
        }
        int    red(Node<value_type, allocator_type> *node)
        {

            if(!node)
            {
                std::cout << "check " << std::endl;
                return 0;
            }else if(node->color == RED)
            {
                return 1;
            }else{
                return 0;
            }
        }
        Node<value_type, allocator_type> *rotate(Node<value_type, allocator_type> *node, bool direction)
        {
            Node<value_type, allocator_type> *tmp = node->child[!direction];
            node->child[!direction] = tmp->child[direction];
            tmp->child[direction] = node;

            tmp->color = node->color;
            node->color = RED;

            return tmp;
        }

        Node<value_type, allocator_type> *doubleRotate(Node<value_type, allocator_type> *node, bool direction)
        {
            node->child[!direction] = rotate(node->child[!direction], !direction);
            
            return rotate(node, direction);
        }

        void insert(value_type &data)
        {
            this->root_ = this->internal_insert(root_, data);
        
            this->root_->color = BLACK;
        }
        

        Node<value_type, allocator_type> *internal_insert(Node<value_type, allocator_type> *node, value_type &data)
        {
            bool direction;
            
            if(node == NULL)
            {
                Node<value_type, allocator_type> *val;
                Node<value_type, allocator_type> val1;
                val = node_alloc_.allocate(1);
                std::cout << "Zium12 " << std::endl;
                val1.init(data,RED, alloc_ );
                val1.data = alloc_.allocate(1);
                alloc_.construct(val1.data, data);
                node_alloc_.construct(val, val1);
                return val;
            }
            //Left 0, Right 1
            
            direction = data.first > node->data->first;
            
            node->child[direction] = internal_insert(node->child[direction], data);
            
            return this->fix_insert(node, direction);;
        }
        
        void colorFlip(Node<value_type, allocator_type> *node)
        {
            node->color = !node->color;
            node->child[left]->color = !node->child[left]->color;
            node->child[right]->color = !node->child[right]->color;
        }

        Node<value_type, allocator_type> *fix_insert(Node<value_type, allocator_type> *node, bool direction)
        {
    
            if(red(node->child[direction]))
            {
                //Both children are red only one child has 2 reds in a row
                if(red(node->child[!direction]))
                {
                    if(red(node->child[direction]->child[direction])
                    || red(node->child[direction]->child[!direction]))
                    {
                        this->colorFlip(node);
                    }
                }
                else
                {
                    //Both children are red
                    if(red(node->child[direction]->child[direction]))
                    {
                        node = rotate(node, !direction);

                    }else if(red(node->child[direction]->child[!direction]))
                    {
                        //Any one child has 2 reds in a row
                  
                        node = doubleRotate(node, !direction);
   
                    }
                }
            }
            return node;
        }

        

        Node<value_type, allocator_type> *delete_fix(Node<value_type, allocator_type> *node, bool direction, bool &result)
        {
            Node<value_type, allocator_type> *parent = node;
            Node<value_type, allocator_type> *sibling = node->child[!direction];

            if(red(sibling))
            {
                node = rotate(node, direction);
                sibling = parent->child[!direction];
            }

            if(sibling)
            {
                if(!red(sibling->child[left]) && !red(sibling->child[right]))
                {
                    if(red(parent))
                        result = true;

                    parent->color = BLACK;
                    sibling->color = RED;
                }else{
                    int init_color = parent->color;
                    bool isRedSibling = !(node==parent);

                    if(red(sibling->child[!direction]))
                    {
                        parent = rotate(parent, direction);
                    }else{
                        parent = doubleRotate(parent, direction);
                    }

                    parent->color = init_color;
                    parent->child[left]->color = BLACK;
                    parent->child[right]->color = BLACK;
                    
                    if(isRedSibling)
                    {
                        node->child[direction] = parent;
                    }else
                    {
                        node = parent;
                    }

                    result = true;
                }
            }
            return node;
        }
        void delete_(value_type &data)
        {
            bool result = false;
            // if(search(data))
            root_ = internal_delete(root_ ,data, result);
            if(root_ != NULL)
            {
                root_->color = BLACK;
            }
        }
        void print_tree()
        {
            this->printTree_internal(root_);

        }
        // maximum value in the left subtree
        void printTree_internal(Node<value_type, allocator_type> *node)
        {
            if(node != NULL)
            {
                printTree_internal(node->child[left]);
                std::cout << node->data->first << "\t" << node->data->second << std::endl;
                std::cout << "Color : " << node->color << std::endl;
                printTree_internal(node->child[right]);
            }
        }

        Node<value_type, allocator_type> *getMax(Node<value_type, allocator_type> *node)
        {
            if(node->child[left])
            {
                getMax(node->child[left]);
            }
            return node;
        }

        value_type search(value_type key)
        {
            Node<value_type, allocator_type> *tmp = root_;
            if(!tmp)
            {
                return 0;
            }
            while(tmp != NULL && tmp->data->first != key)
            {
                if(key < tmp->data->first)
                {
                    tmp = tmp->child[left];
                }else{
                    tmp = tmp->child[right];
                }
            }
            return root_->data;

        }

        Node<value_type, allocator_type> *internal_delete(Node<value_type, allocator_type> *node, value_type &data, bool &result)
        {
            if(!node)
            {
                result = true;
                return NULL;
            }

            if(node->data->first == data.first)
            {
                if(node->child[left] == NULL || node->child[right] == NULL)
                {
                    Node<value_type, allocator_type> *tmp = NULL;
                    if(node->child[left])
                    {
                        std::cout << "If delete " << std::endl;
                        tmp = node->child[left];
                    }
                    if(node->child[right])
                    {
                        std::cout << "If delete " << std::endl;
                        tmp = node->child[right];
                    }
                    std::cout << "Inside delete val\t" << node->data->first << "Color ";
                    std::cout << node->color << std::endl;
                    if(red(node))
                    {
                        alloc_.deallocate(node->data, 1);
                        node_alloc_.deallocate(node, 1);
                        std::cout << "Deallocate 1" << std::endl;
                        // node_alloc_.destroy(node);
                        result = true;
                    }else if(red(tmp))
                    {
                        std::cout << "Deallocate 2\n" << tmp->color << std::endl;
                        tmp->color = BLACK;
                        alloc_.deallocate(node->data, 1);
                        node_alloc_.deallocate(node, 1);
                        // node_alloc_.destroy(node);
                        result = true;
                    }else{
                        alloc_.deallocate(node->data, 1);
                        node_alloc_.deallocate(node, 1);
                    }
                    
                    std::cout << "Delete ran" << std::endl;
                    return tmp;
                }
            else{
                Node<value_type, allocator_type> *tmp = getMax(node->child[left]);
                alloc_.deallocate(node->data, 1);
                node->data = tmp->data;
                data = *tmp->data;
            }
            }
            bool direction = data.first > node->data->first;
            node->child[direction] = internal_delete(node->child[direction], data, result);

            if(result == true)
            {
                std::cout << "Siemanko" << std::endl;
                return node;
            }else{
                return delete_fix(node, direction, result);
            }
        }

        private:
            struct Node<value_type, allocator_type> *root_;
            allocator_type alloc_;
            std::allocator<Node<value_type, allocator_type> > node_alloc_;
    };
}
            // struct Node<value_Type 
        //     // struct node;
        //     template<typename T>
        //     struct node
        //     {
        //         T * data;
        //         node *    left;
        //         node *    right;
        //         node *    parent;
        //         bool    color;
        //     };

        //     typedef Key key_type;
        //     typedef Value value_type;
        //     typedef ft::pair<const Key, Value> pair_type;
        //     typedef Alloc allocator_type;
        //     typedef typename allocator_type::reference reference;
        //     typedef typename allocator_type::const_reference const_reference;
        //     typedef typename allocator_type::pointer pointer;
        //     typedef typename allocator_type::const_pointer const_pointer;
        //     typedef ptrdiff_t difference_type;
        //     typedef size_t size_type;
        //     // typedef node<T> * iter;
        //     // typedef const node * const_iter;
        //     typedef Compare key_compare;

       

        //     RBT(const key_compare &compare = key_compare(), const allocator_type &alloc = allocator_type())
    // };
// }
