/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:27:09 by jkaczmar          #+#    #+#             */
/*   Updated: 2023/01/04 19:12:24 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <stddef.h>

namespace ft
{
    template <typename Category, typename T,
        typename Distance = ptrdiff_t, 
        typename Pointer = T*, typename Reference = T&>
    class iterator
    {
        public:
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : input_iterator_tag {};
    struct bidirectional_iterator_tag : forward_iterator_tag {};
    struct random_access_iterator_tag : bidirectional_iterator_tag {};

    template<typename Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template<typename T>
    struct iterator_traits<T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template<typename T>
    struct iterator_traits<const T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        typedef random_access_iterator_tag iterator_category;
    };


    //ft::pair
    
    template<typename t_1, typename t_2>
    class pair
    {
        public:
        typedef t_1 type_one;
        typedef t_2 type_two;
        
        pair() : first(), second(){}
        pair(const type_one &x, const type_two &y) : first(x), second(y){};
        template<typename x, typename y>
        pair(const pair<x, y> &ot) : first(ot.first), second(ot.second){}
        template<typename x, typename y>
        pair operator=(pair<const x, y> &cp) 
        {
            this->first = cp.first;
            this->second = cp.second;
        }
        ~pair(void){}
        type_one first;
        type_two second;
        private:
        
    };

    template<typename t_1, typename t_2>
    bool operator==(const pair<t_1, t_2> &lhs, const pair<t_1, t_2> &rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template<typename t_1, typename t_2>
    bool operator !=(const pair<t_1, t_2> &lhs, const pair<t_1, t_2> &rhs)
    {
        return (lhs != rhs);
    }

    template<typename t_1, typename t_2>
    bool operator <(const pair<t_1, t_2> &lhs, const pair<t_1, t_2> &rhs)
    {
        return (lhs.first < rhs.first || lhs.second < rhs.second);
    }

    template<typename t_1, typename t_2>
    bool operator <=(const pair<t_1, t_2> &lhs, const pair<t_1, t_2> &rhs)
    {
        return (!(lhs < rhs));
    }

    template<typename t_1, typename t_2>
    bool operator >(const pair<t_1, t_2> &lhs, const pair<t_1, t_2> &rhs)
    {
        return (lhs < rhs);
    }

    template<typename t_1, typename t_2>
    bool operator >=(const pair<t_1, t_2> &lhs, const pair<t_1, t_2> &rhs)
    {
        return (!(lhs < rhs));
    }

    template<typename t_1, typename t_2>
    pair<t_1, t_2> make_pair(t_1 x, t_2 y)
    {
        return pair<t_1, t_2>(x,y);
    }

    //Enable if 

    template <bool, typename T = void>
    struct enable_if {};

    template <typename T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    //Is integral
    
    template<typename T, T x>
    struct integral_constant
    {
        static const T value = x;
        typedef T value_type;
        typedef integral_constant<T, x> type;
    };

    typedef integral_constant<bool, false> false_type;
    typedef integral_constant<bool, false> true_type;

    template <typename T> struct is_integral : false_type{};
    
    template <> struct is_integral<bool> : true_type {};
    template <> struct is_integral<char> : true_type {};
    template <> struct is_integral<char16_t> : true_type {};
    template <> struct is_integral<char32_t> : true_type {};
    template <> struct is_integral<wchar_t> : true_type {};
    template <> struct is_integral<signed char > : true_type {};
    template <> struct is_integral<short int> : true_type {};
    template <> struct is_integral<int> : true_type {};
    template <> struct is_integral<long> : true_type {};
    template <> struct is_integral<long long> : true_type {};
    template <> struct is_integral<unsigned char> : true_type {};
    template <> struct is_integral<unsigned short int> : true_type {};
    template <> struct is_integral<unsigned int> : true_type {};
    template <> struct is_integral<unsigned long> : true_type {};
    template <> struct is_integral<unsigned long long> : true_type {};

//Reverse Iterator 

template<typename It>
class reverse_iterator
{
    public:
        typedef It iterator_type;
        typedef typename ft::iterator_traits<It>::value_type value_type;
        typedef typename ft::iterator_traits<It>::difference_type difference_type ;
        typedef typename ft::iterator_traits<It>::pointer pointer;
        typedef typename ft::iterator_traits<It>::reference reference;
        typedef typename ft::iterator_traits<It>::iterator_category iterator_category;

        reverse_iterator(void) : iter_(){}
        explicit reverse_iterator(iterator_type it) : iter_(it){};
        template<typename Iter>
        reverse_iterator(const reverse_iterator<Iter> &cp) : iter_(cp.base()){}
        virtual ~reverse_iterator(void) {};

        reverse_iterator base(void) const{
            return iter_;
        }

        reverse_iterator &operator=(const reverse_iterator &rhs)
        {
            iter_ = rhs.iter_l;
            return (*this);
        }

        reference operator*(void) const
        {
            iterator_type tmp = this->iter_;
            iter_--;
            return (*tmp);
        }

        reference operator*(void)
        {
            iterator_type tmp = this->iter_;
            iter_--;
            return (*tmp);
        }

        reverse_iterator operator+(difference_type n) const
        {
            return (reverse_iterator(this->iter_ - n));
        }
        
        reverse_iterator &operator++(void)
        {
            this->iter_--;
            return (*this);
        }
        reverse_iterator &operator++(int)
        {
            reverse_iterator tmp = *this;
            (iter_)--;
            return tmp;
        }

        reverse_iterator &operator+=(difference_type n)
        {
            *this = *this - n;
            return (*this);
        }

        reverse_iterator operator-(difference_type n) const
        {
            return (reverse_iterator(this->iter_ + n));
        }
        
        reverse_iterator &operator--(void)
        {
            this->iter_++;
            return (*this);
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = (*this);
            --(*this);
            return (tmp);
        }
        pointer operator->(void) const
        {
            return (&(operator*()));
        }
        reference operator[](difference_type n) const
        {
            return (this->base()[-n - 1]);
        }
    private:
     iterator_type iter_;
};

//Iterator comparisions 

template<typename Iterator>
bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
{
    return (lhs.base() == rhs.base());
}

template<typename Iterator, typename Iterator2>
bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
{
    return (lhs.base() == rhs.base());
}

template<typename Iterator>
bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
{
    return (lhs.base() != rhs.base());
}

template<typename Iterator, typename Iterator2>
bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
{
    return (lhs.base() != rhs.base());
}

template<typename Iterator>
bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
{
    return (lhs.base() > rhs.base());
}

template<typename Iterator, typename Iterator2>
bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
{
    return (lhs.base() > rhs.base());
}

template<typename Iterator>
bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
{
    return (lhs.base() >= rhs.base());
}

template<typename Iterator, typename Iterator2>
bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
{
    return (lhs.base() >= rhs.base());
}

template<typename Iterator>
bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
{
    return (lhs.base() < rhs.base());
}

template<typename Iterator, typename Iterator2>
bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
{
    return (lhs.base() < rhs.base());
}

template<typename Iterator>
bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
{
    return (lhs.base() <= rhs.base());
}

template<typename Iterator, typename Iterator2>
bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
{
    return (lhs.base() <= rhs.base());
}

template<typename Iterator>
reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rhs)
{
    return (rhs + n);
}

template<typename Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
{
    return (rhs.base() - lhs.base());
}

//Distance function 
template<class InputIterator>
typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator second)
{
    typename ft::iterator_traits<InputIterator>::difference_type n = 0;
    while(first != second)
    {
        first++;
        n++;
    }
    return n;
}

//Lexinographical compare
template<typename InputIterator, typename InputIterator2, typename Compare>
bool lexicographical_compare(InputIterator x, InputIterator x1, InputIterator2 y, InputIterator2 y1, Compare comp)
{
    while(x != y)
    {
        if(x1 == y1 || comp(*x1, *x))
        {
            return false;
        }else if(comp(*x, *x1))
            return true;
        x++;
        x1++;
    }
    return x1 != y1;
}

template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	while (first1!=last1) {
	if (!(*first1 == *first2))
		return false;
	++first1;
	++first2;
	}
	return true;
}
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	while (first1!=last1) {
	if (!pred(*first1,*first2))
		return false;
	++first1; ++first2;
	}
	return true;
}
}
#endif