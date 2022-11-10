#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <memory>
#include <iterator>

namespace ft
{
//Iterator tags
struct output_iterator_tag {};
struct input_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct biderectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : biderectional_iterator_tag {};
// template<typename T, typename tree>
template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
struct iterator
{
    typedef T   value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference   reference;
    typedef Category    iterator_category;
};
template<typename T, typename tree>
class const_RedBlackTreeIterator;

template<typename T, typename tree>
class RedBlackTreeIterator : public iterator<biderectional_iterator_tag, T>
{
    public:
    typedef typename tree::value_type value_type;
    typedef typename ft::iterator<biderectional_iterator_tag, value_type>::difference_type difference_type;
    typedef typename ft::iterator<biderectional_iterator_tag, value_type>::pointer pointer;
    typedef typename ft::iterator<biderectional_iterator_tag, value_type>::reference reference;
    typedef typename ft::iterator<biderectional_iterator_tag, value_type>::iterator_category iterator_category;

    RedBlackTreeIterator() : current_(0), end_(0),rend_(0) {
        
    }
    RedBlackTreeIterator(T *c, T *e, T* re) : current_(c), end_(e),rend_(re) {

    }
    RedBlackTreeIterator(const RedBlackTreeIterator& rhs) : current_(rhs.current_), end_(rhs.end_),rend_(rhs.rend_) {}
    template<typename oTree>
    RedBlackTreeIterator(const RedBlackTreeIterator<T, oTree> &rhs) : current_(rhs.base()), end_(rhs.getEnd()), rend_(rhs.getRend()) {}
    T *base()
    {
        return current_;
    }
    T *getEnd()
    {
        return end_;
    }
    T *getRend()
    {
        return rend_;
    }
    reference operator *() const
    {
        return (*(this->current_)->content);
    }
    pointer operator->() const
    {
        return (this->current_->content);
    }
RedBlackTreeIterator &operator++()
    {
        T *tmp = this->current_;
        if(tmp == rend_)
        {
            tmp = rend_->parent;
        }else if(tmp->right)
        {
            tmp = tmp->right;
            while(tmp->left)
            {
                tmp = tmp->left;
            }
        }else{
            while(tmp->parent && tmp == tmp->parent->right)
            {
                tmp = tmp->parent;
            }
            if(tmp->parent)
                tmp = tmp->parent;
            else{
                tmp = end_;
            }
        }
        current_ = tmp;
        return (*this);
    }

    RedBlackTreeIterator &operator++(int)
    {
        RedBlackTreeIterator tmp = *this;
        ++(*this);
        return tmp;
    }
    RedBlackTreeIterator &operator--()
    {
        T *tmp = current_;
        if(tmp == end_)
        {
            tmp = tmp->end_->parent;
        }else if(tmp->left)
        {
            tmp = tmp->left;
            while(tmp->right)
            {
                tmp = tmp->right;
            }
        }else{
            while(tmp->parent && tmp == tmp->parent->left)
            {
                tmp = tmp->parent;
            }
            if(tmp->parent)
            {
                tmp = tmp->parent;
            }else{
                tmp = rend_;
            }
        }
        current_ = tmp;
        return (*this);
    }
    RedBlackTreeIterator &operator--(int)
    {
        RedBlackTreeIterator tmp = *this;
        --(*this);
        return tmp;
    }
    bool operator==(RedBlackTreeIterator<T,tree> other_tree)
    {
        return ((this->base) == other_tree.base());
    }
    bool operator==(const_RedBlackTreeIterator<T,tree> other_tree) const
    {
        return ((this->base) == other_tree.base());
    }
    bool operator!=(RedBlackTreeIterator<T,tree> other_tree)
    {
        return ((this->base) != other_tree.base());
    }
    bool operator!=(const_RedBlackTreeIterator<T,tree> other_tree) const
    {
        return ((this->base) == other_tree.base());
    }
    private:
    T *current_;
    T *end_;
    T *rend_;

};

template<typename T, typename tree>
class const_RedBlackTreeIterator
{
        public:
    typedef typename tree::value_type value_type;
    typedef typename ft::iterator<biderectional_iterator_tag, value_type>::difference_type difference_type;
    typedef typename ft::iterator<biderectional_iterator_tag, value_type>::pointer pointer;
    typedef typename ft::iterator<biderectional_iterator_tag, value_type>::reference reference;
    typedef typename ft::iterator<biderectional_iterator_tag, value_type>::iterator_category iterator_category;

    const_RedBlackTreeIterator() : current_(0), end_(0),rend_(0) {
        
    }
    const_RedBlackTreeIterator(T *c, T *e, T* re) : current_(c), end_(e),rend_(re) {

    }
    const_RedBlackTreeIterator(const const_RedBlackTreeIterator& rhs) : current_(rhs.current_), end_(rhs.end_),rend_(rhs.rend_) {}
    template<typename oTree>
    const_RedBlackTreeIterator(const const_RedBlackTreeIterator<T, oTree> &rhs) : current_(rhs.base()), end_(rhs.getEnd()), rend_(rhs.getRend()) {}
    T *base()
    {
        return current_;
    }
    T *getEnd()
    {
        return end_;
    }
    T *getRend()
    {
        return rend_;
    }
    reference operator *() const
    {
        return (*(this->current_)->content);
    }
    pointer operator->() const
    {
        return (this->current_->content);
    }
    const_RedBlackTreeIterator &operator++()
    {
        T *tmp = this->current_;
        if(tmp == rend_)
        {
            tmp = rend_->parent;
        }else if(tmp->right)
        {
            tmp = tmp->right;
            while(tmp->left)
            {
                tmp = tmp->left;
            }
        }else{
            while(tmp->parent && tmp == tmp->parent->right)
            {
                tmp = tmp->parent;
            }
            if(tmp->parent)
                tmp = tmp->parent;
            else{
                tmp = end_;
            }
        }
        current_ = tmp;
        return (*this);
    }

    const_RedBlackTreeIterator &operator++(int)
    {
        const_RedBlackTreeIterator tmp = *this;
        ++(*this);
        return tmp;
    }
    const_RedBlackTreeIterator &operator--()
    {
        T *tmp = current_;
        if(tmp == end_)
        {
            tmp = tmp->end_->parent;
        }else if(tmp->left)
        {
            tmp = tmp->left;
            while(tmp->right)
            {
                tmp = tmp->right;
            }
        }else{
            while(tmp->parent && tmp == tmp->parent->left)
            {
                tmp = tmp->parent;
            }
            if(tmp->parent)
            {
                tmp = tmp->parent;
            }else{
                tmp = rend_;
            }
        }
        current_ = tmp;
        return (*this);
    }
    const_RedBlackTreeIterator &operator--(int)
    {
        const_RedBlackTreeIterator tmp = *this;
        --(*this);
        return tmp;
    }
    bool operator==(RedBlackTreeIterator<T,tree> other_tree)
    {
        return ((this->base) == other_tree.base());
    }
    bool operator==(const_RedBlackTreeIterator<T,tree> other_tree) const
    {
        return ((this->base) == other_tree.base());
    }
    bool operator!=(RedBlackTreeIterator<T,tree> other_tree)
    {
        return ((this->base) != other_tree.base());
    }
    bool operator!=(const_RedBlackTreeIterator<T,tree> other_tree) const
    {
        return ((this->base) == other_tree.base());
    }
    private:
    T *current_;
    T *end_;
    T *rend_;
};
};
//Class T tags
#endif