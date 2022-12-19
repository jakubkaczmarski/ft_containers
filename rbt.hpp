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
        typename Alloc = std::allocator<ft::pair<const Key, Value> >, typename Compare = std::less<Key> >
    class RBT
    {

        typedef Value value_type;
    
        public:
        RBT()
        : root_(NULL)
        {

        }
        template <typename Data>
        struct Node
        {
            Node(Data data, int color)
            {
                this->data = data;
                this->color = color;
                this->child[left] = new Node<value_type>();
                this->child[right] = new Node<value_type>();
                printf("Constructor ran\n");
            }
            Node()
            {
                this->data = 0;
                this->color = 0;
                this->child[left] = new Node<value_type>(13);
                this->child[right] = new Node<value_type>(12);
            }

            Node(int a)
            {
                this->data = 0;
                this->color = 0;
                this->child[left] = NULL;
                this->child[right] = NULL;
            }
            Data data;
            int color;             
            Node *child[2];
        };


        Node<value_type> *rotate(Node<value_type> *node, bool direction)
        {
            Node<value_type> *tmp = node->child[direction];
            node->child[!direction] = tmp->child[direction];
            tmp->child[direction] = node;

            tmp->color = node->color;
            node->color = RED;

            return tmp;
        }

        Node<value_type> *doubleRotate(Node<value_type> *node, bool direction)
        {
            node->child[!direction] = rotate(node->child[!direction], !direction);
            
            return rotate(node, direction);
        }

        void insert(value_type &data)
        {
            if(root_)
            {
                std::cout << " " << root_->data << std::endl;
            }
            root_ = this->internal_insert(root_, data);
        
            root_->color = BLACK;
        }
        

        Node<value_type> *internal_insert(Node<value_type> *node, value_type &data)
        {
            bool direction;
            
            if(node == NULL)
            {
                return new Node<value_type>(data, RED);
            }
            //Left 0, Right 1
            printf("Direction\n");
            
            direction = data > node->data;
            
            node->child[direction] = internal_insert(node->child[direction], data);
            
            return this->fix_insert(node, direction);;
        }
        
        void colorFlip(Node<value_type> *node)
        {
            node->color = !node->color;
            std::cout << node->child[left]->color << std::endl;
            // std::cout << !node->child[left]->color << std::endl;
            node->child[right]->color = !node->child[right]->color;
        }

        Node<value_type> *fix_insert(Node<value_type> *node, bool direction)
        {
    
            if(node->child[direction]->color == RED)
            {
                //Both children are red only one child has 2 reds in a row
                printf("Hiello\n");
                std::cout << node->child[direction]->color << std::endl;
                std::cout << "Zium " << std::endl;
                std::cout << node->child[direction]->child[direction]->color << std::endl;
                std::cout << "Zium2 " << std::endl;
                if(node->child[direction]->child[direction]->color == RED 
                    || node->child[direction]->child[!direction]->color == RED)
                {
                    printf("Woow\n");
                    this->colorFlip(node);
                }else
                {
                    printf("Woow\n");
                    //Both children are red
                    if(node->child[direction]->child[direction]->color == RED)
                    {
                        
                        node = rotate(node, !direction);

                    }else if(node->child[direction]->child[!direction]->color == RED)
                    {
                        //Any one child has 2 reds in a row
                        node = doubleRotate(node, !direction);
                    }
                }
            }
            return node;
        }


        private:
            struct Node<value_type> *root_;
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
        //     : size_(0), comp_(compare), alloc_(alloc)
        //     {
        //         nil_ = node_alloc_.allocate(1);
        //         nil_->color = BLACK;
        //         nil_->left = nullptr;
        //         nil_->right = nullptr;
        //         root_ = nil_;
        //     }

        //     ~RBT()
        //     {
        //         dealloc();
        //     }

        //     void dealloc()
        //     {
        //         alloc_.deallocate(nil_, 1);
        //     }

        //     size_type size() const
        //     {
        //         return size_;
        //     }

        //     node *insert(const value_type &value)
        //     {
        //         node *tmp = node_alloc_.allocate(1);
        //         tmp->data = alloc_.allocate(1);
        //         alloc_.construct(tmp->data, value);
        //         tmp->parent = nullptr;
        //         tmp->left = nil_;
        //         tmp->right = nil_;
        //         tmp->color = RED;

        //         node *i = nullptr;
        //         node *j = root_;

        //         while(i != nil_)
        //         {
        //             j = i;
        //             if(this->comp_(tmp->data->first, j->data->first))
        //             {
        //                 i = i->left;
        //             }
        //             else if(comp_(i->data->first, tmp->data->first))
        //             {
        //                 i = i->right;
        //             }else{
        //                 return i;
        //             }
        //         }
        //         tmp->parent = j;
        //         if(j == nullptr)
        //             root_ = tmp;
        //         else if(comp_(tmp->data->first, j->data->first))
        //             j->left = tmp;
        //         else 
        //             j->right = tmp;
        //         size_++;

        //         node *x = root_;

        //         while(x->right != nil_)
        //         {
        //             x = x->right;
        //         }
        //         nil_->parent = x;

        //         if(tmp->parent == nullptr)
        //         {
        //             tmp->color = BLACK:
        //             return tmp;
        //         }

        //         if(tmp->parent->parent == nullptr)
        //         {
        //             return tmp;
        //         }

        //         //Fix insert
        //         //Fixinsert(tmp);
        //         return tmp;
        //     }

        // private:
        //     node *root_;
        //     size_type size_;
        //     key_compare comp_;
        //     allocator_type alloc_;
        //     std::allocator<node> node_alloc_;
        //     node *nil_;
    };
}
