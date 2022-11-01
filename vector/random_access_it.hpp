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
template<typename T>
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
        random_access_iterator operator =(random_access_iterator<T> const &rhs)
        {
            ptr_ = rhs.base();
            return (*this);
        }
        random_access_iterator operator ++()
        {
            ptr_++;
            return (*this);
        }
        random_access_iterator operator ++(int)
        {
            random_access_iterator tmp(*this);
            ptr_++;
            return (tmp);
        }
        random_access_iterator operator --()
        {
            ptr_--;
            return (*this);
        }
        random_access_iterator operator --(int)
        {
            random_access_iterator tmp (*this);
            ptr_++;
            return (tmp);
        }
        random_access_iterator operator +(difference_type num) const
        {
            return (ptr_ + num);
        }
        random_access_iterator operator -(difference_type num) const
        {
            return (ptr_ - num);
        }
        bool operator <(random_access_iterator<T> rhs) const
        {
            return (ptr_ < rhs.base());
        }
        bool operator <(constant_random_access_iterator<const T> rhs) const
        {
            return (ptr_ < rhs.base());
        }
        bool operator >(random_access_iterator<const T> rhs) const
        {
            return (ptr_ > rhs.base());
        }
        bool operator >(constant_random_access_iterator<const T> rhs) const
        {
            return (ptr_ > rhs.base());
        }
        bool operator <=(random_access_iterator<T> rhs)
        {
            return (ptr_ <= rhs.base());
        }
        bool operator <=(constant_random_access_iterator<const T> rhs)
        {
            return (ptr_ <= rhs.base());
        }
        bool operator >=(random_access_iterator<T> rhs)
        {
            return (ptr_ >= rhs.base());
        }
        bool operator >=(constant_random_access_iterator<const T> rhs)
        {
            return (ptr_ >= rhs.base());
        }
        bool operator ==(random_access_iterator<T> rhs)
        {
            return (ptr_ == rhs.base());
        }
        bool operator ==(constant_random_access_iterator<const T> rhs)
        {
            return (ptr_ == rhs.base());
        }
        bool operator !=(random_access_iterator<T> rhs)
        {
            return (ptr_ != rhs.base());
        }
        bool operator !=(constant_random_access_iterator<const T> rhs)
        {
            return (ptr_ != rhs.base());
        }
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
template<typename T>
class constant_random_access_iterator : public iterator<random_access_iterator_tag, T>
{
    public:
        typedef typename ft::iterator<random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::iterator<random_access_iterator_tag, T>::pointer pointer;
        typedef typename ft::iterator<random_access_iterator_tag, T>::reference reference;
        typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;

        constant_random_access_iterator() : ptr_(0){};
        template <typename P>
        constant_random_access_iterator(const random_access_iterator<P>  &rhs) : ptr_(rhs.base()){}
        constant_random_access_iterator(const constant_random_access_iterator  &rhs) : ptr_(rhs.base()){}
        constant_random_access_iterator(pointer p) : ptr_(p){};
        pointer base() const
        {
            return (ptr_);
        }
        reference operator *()
        {
            return *(ptr_);
        }
        reference operator =(constant_random_access_iterator<T> const &rhs)
        {
            ptr_ = rhs.base();
            return *(this);
        }
        constant_random_access_iterator operator ++()
        {
            ptr_++;
            return *(this);
        }
        constant_random_access_iterator operator ++(int)
        {
            constant_random_access_iterator tmp(*this);
            ptr_++;
            return tmp;
        }
        constant_random_access_iterator operator --()
        {
            ptr_--;
            return *(this);
        }
        constant_random_access_iterator operator --(int)
        {
            constant_random_access_iterator tmp (*this);
            ptr_++;
            return (tmp);
        }
        constant_random_access_iterator operator +(difference_type num) const
        {
            return (ptr_ + num);
        }
        constant_random_access_iterator operator -(difference_type num) const
        {
            return (ptr_ - num);
        }
        bool operator <(constant_random_access_iterator<T> rhs) const
        {
            return (ptr_ < rhs.base());
        }
        bool operator <(constant_random_access_iterator<const T> rhs) const
        {
            return (ptr_ < rhs.base());
        }
        bool operator >(constant_random_access_iterator<T> rhs) const
        {
            return (ptr_ > rhs.base());
        }
        bool operator >(constant_random_access_iterator<const T> rhs) const
        {
            return (ptr_ > rhs.base());
        }
        bool operator <=(constant_random_access_iterator<T> rhs)
        {
            return (ptr_ <= rhs.base());
        }
        bool operator <=(constant_random_access_iterator<const T> rhs)
        {
            return (ptr_ <= rhs.base());
        }
        bool operator >=(constant_random_access_iterator<T> rhs)
        {
            return (ptr_ >= rhs.base());
        }
        bool operator >=(constant_random_access_iterator<const T> rhs)
        {
            return (ptr_ >= rhs.base());
        }
        bool operator ==(constant_random_access_iterator<T> rhs)
        {
            return (ptr_ == rhs.base());
        }
        bool operator ==(constant_random_access_iterator<const T> rhs)
        {
            return (ptr_ == rhs.base());
        }
        bool operator !=(constant_random_access_iterator<T> rhs)
        {
            return (ptr_ != rhs.base());
        }
        bool operator !=(constant_random_access_iterator<const T> rhs)
        {
            return (ptr_ != rhs.base());
        }
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

template<typename T>
random_access_iterator<T> operator+(typename ft::iterator<random_access_iterator_tag, T>::difference_type n, random_access_iterator<T> &it)
{
    return (it.base() + n);
}
template<typename T>
random_access_iterator<T> operator+(typename ft::iterator<random_access_iterator_tag, T>::difference_type n, constant_random_access_iterator<T> &it)
{
    return (it.base() + n);
}
template<typename T>
typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
{
    return (lhs.base() - rhs.base());
}
template<typename T>
typename random_access_iterator<T>::difference_type operator-(const constant_random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
{
    return (lhs.base() - rhs.base());
}
template<typename T>
typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &lhs, const constant_random_access_iterator<T> &rhs)
{
    return (lhs.base() - rhs.base());
}
template<typename T>
typename random_access_iterator<T>::difference_type operator-(const constant_random_access_iterator<T> &lhs, const constant_random_access_iterator<T> &rhs)
{
    return (lhs.base() - rhs.base());
}
}


#endif