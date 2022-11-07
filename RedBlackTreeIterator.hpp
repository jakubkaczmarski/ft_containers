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

template<typename T, typename tree>
class RedBlackTreeIterator : public iterator<biderectional_iterator_tag, T>
{
    public:
    typedef typename Tree::value_type value_type;
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
    RedBlackTreeIterator(const RedBlackTreeIterator<T, oTree> &rhs) : current_(rhs.base()), end(rhs.getEnd()), rend(rhs.getrend()) {}
    T *base()
    {
        return current_;
    }
    T *end()
    {
        return end_;
    }
    T *rend()
    {
        return rend_;
    }
    private:
    T *current_;
    T *end_;
    T *rend_;

};


//Class T tags
#endif