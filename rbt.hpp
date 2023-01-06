// #include "tools.hpp"
// #include "rbt_iter.hpp"
// #include <memory>
// #include <iostream>
// #include <functional>
// #define BLACK true
// #define RED false

// #define left 0
// #define right 1

// //Parent pointer has to be added
// //


// namespace ft
// {
//     template <typename Key, typename Value,
//         typename allocator = std::allocator<ft::pair<Key, Value> >, typename Compare = std::less<Key> >
//     class RBT
//     {         
//         public:
//         typedef allocator  allocator_type;
//         typedef ft::pair<Key, Value> value_type;
      

//         template <typename Data>
//         struct Node
//         {
//             Node(Data &data, int color)
//             {
//                 this->color = color;
//                 this->child[left] = NULL;
//                 this->child[right] = NULL;
//                 this->parent = NULL;
//             }

//             std::allocator<Data> internal_alloc_;
//             Data *data;
//             int color;
//             Node *parent;
//             Node *child[2];
//         };
//         typedef Node<value_type>        node;
//         typedef Node<value_type>*       node_ptr;
//         // typedef rbt_iterator<value_type>    iterator;
//         // typedef const_rbt_iterator<value_type>    const_iterator;
//         RBT()
//         {
//             this->root_ = NULL;
//         }
//         int    red(Node<value_type> *node)
//         {
//             if(!node)
//             {
//                 return 0;
//             }else if(node->color == RED)
//             {
//                 return 1;
//             }else{
//                 return 0;
//             }
//         }
//         Node<value_type> *rotate(Node<value_type> *node, bool direction)
//         {
//             Node<value_type> *tmp = node->child[!direction];
//             node->child[!direction] = tmp->child[direction];
//             tmp->child[direction] = node;

//             tmp->color = node->color;
//             node->color = RED;

//             return tmp;
//         }

//         Node<value_type> *doubleRotate(Node<value_type> *node, bool direction)
//         {
//             node->child[!direction] = rotate(node->child[!direction], !direction);
            
//             return rotate(node, direction);
//         }

//         void insert(value_type &data)
//         {
//             this->root_ = this->internal_insert(root_, data);

//             this->root_->color = BLACK;
//         }
        

//         Node<value_type> *internal_insert(Node<value_type> *node, value_type &data, Node<value_type> *parent)
//         {
//             bool direction;
            
//             if(node == NULL)
//             {
//                 Node<value_type> *val;
//                 val = node_alloc_.allocate(1);
//                 val->data = val->internal_alloc_.allocate(1);
//                 val->internal_alloc_.construct(val->data, data);

//                 return val;
//             }
//             //Left 0, Right 1
            
//             direction = !compare(data.first, node->data->first);
            
//             node->child[direction] = internal_insert(node->child[direction], data, node);
            
//             return this->fix_insert(node, direction);;
//         }
        
//         void colorFlip(Node<value_type> *node)
//         {
//             node->color = !node->color;
//             node->child[left]->color = !node->child[left]->color;
//             node->child[right]->color = !node->child[right]->color;
//         }

//         Node<value_type> *fix_insert(Node<value_type> *node, bool direction)
//         {
    
//             if(red(node->child[direction]))
//             {
//                 //Both children are red only one child has 2 reds in a row
//                 if(red(node->child[!direction]))
//                 {
//                     if(red(node->child[direction]->child[direction])
//                     || red(node->child[direction]->child[!direction]))
//                     {
//                         this->colorFlip(node);
//                     }
//                 }
//                 else
//                 {
//                     //Both children are red
//                     if(red(node->child[direction]->child[direction]))
//                     {
//                         node = rotate(node, !direction);

//                     }else if(red(node->child[direction]->child[!direction]))
//                     {
//                         //Any one child has 2 reds in a row
                  
//                         node = doubleRotate(node, !direction);
   
//                     }
//                 }
//             }
//             return node;
//         }

        

//         Node<value_type> *delete_fix(Node<value_type> *node, bool direction, bool &result)
//         {
//             Node<value_type> *parent = node;
//             Node<value_type> *sibling = node->child[!direction];

//             if(red(sibling))
//             {
//                 node = rotate(node, direction);
//                 sibling = parent->child[!direction];
//             }

//             if(sibling)
//             {
//                 if(!red(sibling->child[left]) && !red(sibling->child[right]))
//                 {
//                     if(red(parent))
//                         result = true;

//                     parent->color = BLACK;
//                     sibling->color = RED;
//                 }else{
//                     int init_color = parent->color;
//                     bool isRedSibling = !(node==parent);

//                     if(red(sibling->child[!direction]))
//                     {
//                         parent = rotate(parent, direction);
//                     }else{
//                         parent = doubleRotate(parent, direction);
//                     }

//                     parent->color = init_color;
//                     parent->child[left]->color = BLACK;
//                     parent->child[right]->color = BLACK;
                    
//                     if(isRedSibling)
//                     {
//                         node->child[direction] = parent;
//                     }else
//                     {
//                         node = parent;
//                     }

//                     result = true;
//                 }
//             }
//             return node;
//         }

//         void print_tree()
//         {
//             this->printTree_internal(root_);

//         }
//         // maximum value in the left subtree
//         void printTree_internal(Node<value_type> *node)
//         {
//             if(node != NULL)
//             {
//                 printTree_internal(node->child[left]);
//                 std::cout << node->data->first << "\t" << node->data->second << std::endl;
//                 std::cout << "Color : " << node->color << std::endl;
//                 printTree_internal(node->child[right]);
//             }
//         }

//         Node<value_type> *getMax(Node<value_type> *node)
//         {
//             if(node->child[left])
//             {
//                 getMax(node->child[left]);
//             }
//             return node;
//         }

//         value_type search(value_type key)
//         {
//             Node<value_type> *tmp = root_;
//             if(!tmp)
//             {
//                 return 0;
//             }
//             while(tmp != NULL && tmp->data->first != key)
//             {
//                 if(key < tmp->data->first)
//                 {
//                     tmp = tmp->child[left];
//                 }else{
//                     tmp = tmp->child[right];
//                 }
//             }
//             return root_->data;

//         }

//         void delete_(value_type &data)
//         {
//             bool result = false;
            
//             if(!root_)
//             {
//                 result = true;
//                 return ;
//             }
//             if(root_->child[left] == NULL && root_->child[right] == NULL && (root_->data->first == data.first))
//             {
//                 root_->internal_alloc_.deallocate(root_->data, 1);
//                 node_alloc_.deallocate(root_, 1);
//                 root_ = NULL;
//                 return ;
//             }
//             root_ = internal_delete(root_ ,data, result);
//             if(root_ != NULL)
//             {
//                 root_->color = BLACK;
//             }
//         }

//         Node<value_type> *internal_delete(Node<value_type> *node, value_type &data, bool &result)
//         {
//             if(!node)
//             {
//                 result = true;
//                 return NULL;
//             }

//             if(node->data->first == data.first)
//             {
//                 if(node->child[left] == NULL || node->child[right] == NULL)
//                 {

//                     Node<value_type> *tmp = NULL;
//                     if(node->child[left])
//                     {
//                         tmp = node->child[left];
//                     }
//                     if(node->child[right])
//                     {
//                         tmp = node->child[right];
//                     }

                   
//                     if(red(node))
//                     {
//                         node->internal_alloc_.deallocate(node->data, 1);
//                         node_alloc_.deallocate(node, 1);
//                         result = true;

//                     }else if(red(tmp))
//                     {
//                         std::cout << node->data->second << " Hallo karthus " << std::endl;
//                         tmp->color = BLACK;
//                         node->internal_alloc_.deallocate(node->data, 1);
//                         node_alloc_.deallocate(node, 1);
//                         // node_alloc_.destroy(node);
//                         result = true;
//                     }
//                     return tmp;
//                 }
//             else{
//                 Node<value_type> *tmp = getMax(node->child[left]);
//                 alloc_.deallocate(node->data, 1);
//                 node->data = tmp->data;
//                 data = *tmp->data;
//                 free(tmp);
//             }
//             }
//             bool direction = data.first > node->data->first;
//             node->child[direction] = internal_delete(node->child[direction], data, result);

//             if(result == true)
//             {
//                 return node;
//             }else{
//                 return delete_fix(node, direction, result);
//             }
//         }
//         void _printHelper(const std::string& prefix, const node* n, bool isLeft) const
// 		{
// 			if (n != NULL)
// 			{
// 				std::cout << prefix;

// 				std::cout << (isLeft ? "├──" : "└──" );

// 				// print the value of the node
// 				std::cout << n->data->first << std::endl;

// 				// enter the next tree level - left and right branch
// 				_printHelper(prefix + (isLeft ? "│   " : "    "), n->child[left], true);
// 				_printHelper(prefix + (isLeft ? "│   " : "    "), n->child[right], false);
// 			}
// 		}

//         void print() const
// 		{
// 			_printHelper("", this->root_, false);
// 		}   
//         private:
//             struct Node<value_type> *root_;
//             allocator_type alloc_;
//             std::allocator<Node<value_type> > node_alloc_;
//             Compare						compare;
//     };
// }



./map_tests/compare class.cpp:76:40:
 error: no viable conversion from
  'rbt_iterator
  <ft::new_RBT<ft::pair<const int, int>,std::__1::plus<int>, std::__1::allocator<ft::pair<const int, int> > >::Node<ft::pair<const int, int> >, new_RBT<[...], std::__1::plus<int>, [...]>>' to 
'rbt_iterator<typename tree_type::node, new_RBT<[...], ft::map<int, int, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > >::key_compare, [...]>>'
    for (typename _map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
                                       ^    ~~~~