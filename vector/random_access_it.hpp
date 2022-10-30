#ifndef RANDOM_ACESS_ITERATOR_HPP
#define RANDOM_ACESS_ITERATOR_HPP

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

//Class T tags

class constant_random_access_iterator;

template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
struct iterator
{
    typedef T   value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference   reference;
    typedef Category    iterator_category;
};
template<typename T>
class random_access_iterator : public iterator<random_access_iterator_tag, T>
{
    public:
        typedef typename ft::iterator<random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::iterator<random_access_iterator_tag, T>::pointer pointer;
        typedef typename ft::iterator<random_access_iterator_tag, T>::reference reference;
        typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;

        random_access_iterator() : ptr_(0){};
        random_access_iterator(random_access_iterator const &rhs) : ptr_(rhs.base()){}
        random_access_iterator(pointer p) : ptr_(p){};
        pointer base() const
        {
            return (ptr_);
        }
        reference operator *()
        {
            return *(ptr_);
        }
        reference operator =(random_access_iterator<T> const &rhs)
        {
            ptr_ = rhs.base();
            return *(this);
        }
        reference operator ++()
        {
            ptr_++;
            return *(this);
        }
        reference operator ++(int)
        {
            random_access_iterator tmp(ptr_);
            ptr_++;
            return tmp;
        }
        reference operator --()
        {
            ptr_--;
            return *(this);
        }
        reference operator --(int)
        {
            random_access_iterator tmp (ptr_);
            ptr_++;
            return (tmp);
        }
        reference operator +(difference_type num) const
        {
            return (ptr_ + num);
        }
        reference operator -(difference_type num) const
        {
            return (ptr_ - num);
        }
        bool operator <(random_access_iterator<T> rhs) const
        {
            return (ptr_ < rhs.base());
        }
        // bool operator <(constant_random_access_iterator<const T> rhs) const
        // {
        //     return (ptr_ < rhs.base());
        // }
        bool operator >(random_access_iterator<const T> rhs) const
        {
            return (ptr_ > rhs.base());
        }
        // bool operator >(constant_random_access_iterator<const T> rhs) const
        // {
        //     return (ptr_ > rhs.base());
        // }
        bool operator <=(random_access_iterator<T> rhs)
        {
            return (ptr_ <= rhs.base());
        }
        // bool operator <=(constant_random_access_iterator<const T> rhs)
        // {
        //     return (ptr_ <= rhs.base());
        // }
        bool operator >=(random_access_iterator<T> rhs)
        {
            return (ptr_ >= rhs.base());
        }
        // bool operator >=(constant_random_access_iterator<const T> rhs)
        // {
        //     return (ptr_ >= rhs.base());
        // }
        bool operator ==(random_access_iterator<T> rhs)
        {
            return (ptr_ == rhs.base());
        }
        // bool operator ==(constant_random_access_iterator<const T> rhs)
        // {
        //     return (ptr_ == rhs.base());
        // }
        bool operator !=(random_access_iterator<T> rhs)
        {
            return (ptr_ != rhs.base());
        }
        // bool operator !=(constant_random_access_iterator<const T> rhs)
        // {
        //     return (ptr_ != rhs.base());
        // }
        reference operator +=(difference_type num) const
        {
            return (ptr_ += num);
        }
        reference operator -=(difference_type num) const
        {
            return (ptr_ -= num);
        }
        pointer operator->()const
        {
            return (ptr_);
        }
        reference operator[](difference_type n) const
        {
            return *(ptr_ + n);
        }
    private:
        pointer ptr_;
};

class constant_random_access_iterator
{
    
}
}


#endif