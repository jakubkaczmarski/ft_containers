/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:26:17 by jkaczmar          #+#    #+#             */
/*   Updated: 2023/01/03 23:51:30 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "tools.hpp"

namespace ft
{

    template<typename T>
    class const_random_access_iterator;
    
    template<typename T>
    class random_access_iterator : public ft::iterator<random_access_iterator_tag, T>
    {
        public:
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
        
        random_access_iterator() : iter_(nullptr) {}

        random_access_iterator(const random_access_iterator &cp) : iter_(cp.iter_){}

        random_access_iterator(pointer element) : iter_(element) {}

        virtual ~random_access_iterator(void) {}

        random_access_iterator &operator=(const random_access_iterator &val)
        {
            iter_ = val.iter_;
            return (*this);
        }
        
        pointer base()
        {
            return iter_;
        }
        
        reference operator*(void) const
        {
            return (*(this->iter_));
        }

        pointer operator->(void)
        {
            return(&(this->operator*()));
        }

        random_access_iterator operator++(int)
        {
            random_access_iterator tmp = *this;
            this->iter_++;
            return (tmp);
        }

        random_access_iterator &operator++(void)
        {
            iter_++;
            return *this;
        }

        random_access_iterator operator--(int)
        {
            random_access_iterator tmp = *this;
            this->iter_--;
            return (tmp);
        }

        random_access_iterator &operator--(void)
        {
            this->iter_--;
            return (*this);
        }
        
        random_access_iterator operator+(difference_type n) const
        {
            return iter_ + n;
        }

        random_access_iterator operator-(difference_type n) const
        {
            return iter_ - n;
        }

        random_access_iterator &operator+=(difference_type n)
        {
            iter_ += n;
            return (*this);
        }
        random_access_iterator &operator-=(difference_type n)
        {
            iter_ -= n;
            return (*this);
        }

        reference operator[](difference_type n)
        {
            return (*(iter_ + n));
        }
        
        //Logical operators
        
        bool operator==(const random_access_iterator<T> &rhs)
        {
            return (this->base() == rhs.base());
        }

        bool operator==(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() == rhs.base());
        }
        
        bool operator!=(const random_access_iterator<T> &rhs)
        {
            return (this->base() != rhs.base());
        }

        bool operator!=(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() != rhs.base());
        }
        
        bool operator>(const random_access_iterator<T> &rhs)
        {
            return (this->base() > rhs.base());
        }

        bool operator>(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() > rhs.base());
        }
        bool operator>=(const random_access_iterator<T> &rhs)
        {
            return (this->base() >= rhs.base());
        }

        bool operator>=(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() >= rhs.base());
        }

        bool operator<(const random_access_iterator<T> &rhs)
        {
            return (this->base() < rhs.base());
        }

        bool operator<(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() < rhs.base());
        }
        
        bool operator<=(const random_access_iterator<T> &rhs)
        {
            return (this->base() <= rhs.base());
        }

        bool operator<=(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() <= rhs.base());
        }
        private:
        pointer iter_;
    };

    template<typename T>
    class const_random_access_iterator : public ft::iterator<random_access_iterator_tag, T>
    {
        public:
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;

        const_random_access_iterator() : iter_(nullptr) {}

        const_random_access_iterator(const const_random_access_iterator &cp) : iter_(cp.iter_){}

        const_random_access_iterator(pointer element) : iter_(element) {}

        virtual ~const_random_access_iterator(void) {}

        const_random_access_iterator &operator=(const const_random_access_iterator &val)
        {
            iter_ = val.iter_;
            return (*this);
        }
        
        pointer base()
        {
            return iter_;
        }
        
        reference operator*(void) const
        {
            return (*(this->iter_));
        }

        pointer operator->(void)
        {
            return(&(this->operator*()));
        }

        const_random_access_iterator operator++(int)
        {
            const_random_access_iterator tmp = *this;
            this->iter_++;
            return (tmp);
        }

        const_random_access_iterator &operator++(void)
        {
            iter_++;
            return *this;
        }

        const_random_access_iterator operator--(int)
        {
            const_random_access_iterator tmp = *this;
            this->iter_--;
            return (tmp);
        }

        const_random_access_iterator &operator--(void)
        {
            this->iter_--;
            return (*this);
        }
        
        const_random_access_iterator operator+(difference_type n) const
        {
            return iter_ + n;
        }

        const_random_access_iterator operator-(difference_type n) const
        {
            return iter_ - n;
        }

        const_random_access_iterator &operator+=(difference_type n)
        {
            iter_ += n;
            return (*this);
        }
        const_random_access_iterator &operator-=(difference_type n)
        {
            iter_ -= n;
            return (*this);
        }

        reference operator[](difference_type n)
        {
            return (*(iter_ + n));
        }
        
        //Logical operators
        
        bool operator==(const random_access_iterator<T> &rhs)
        {
            return (this->base() == rhs.base());
        }

        bool operator==(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() == rhs.base());
        }
        
        bool operator!=(const random_access_iterator<T> &rhs)
        {
            return (this->base() != rhs.base());
        }

        bool operator!=(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() != rhs.base());
        }
        
        bool operator>(const random_access_iterator<T> &rhs)
        {
            return (this->base() > rhs.base());
        }

        bool operator>(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() > rhs.base());
        }
        bool operator>=(const random_access_iterator<T> &rhs)
        {
            return (this->base() >= rhs.base());
        }

        bool operator>=(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() >= rhs.base());
        }

        bool operator<(const random_access_iterator<T> &rhs)
        {
            return (this->base() < rhs.base());
        }

        bool operator<(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() < rhs.base());
        }
        
        bool operator<=(const random_access_iterator<T> &rhs)
        {
            return (this->base() <= rhs.base());
        }

        bool operator<=(const const_random_access_iterator<const T> &rhs)
        {
            return (this->base() <= rhs.base());
        }
        private:
        value_type iter_;
    };

    template<typename T>
    random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, random_access_iterator<T> &it)
    {
        return (&((*it) + n));
    }

    template<typename T>
    random_access_iterator<T> operator+(typename const_random_access_iterator<T>::difference_type n, const_random_access_iterator<T> &it)
    {
        return (&(*it) + n);
    }

    template<typename T>
    typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
    {
        return (lhs.base() - rhs.base());
    }

    template<typename T>
    typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &lhs, const const_random_access_iterator<const T> &rhs)
    {
        return (lhs.base() - rhs.base());
    }
    
    template<typename T>
    typename random_access_iterator<T>::difference_type operator-(const const_random_access_iterator<const T> &lhs, const random_access_iterator<T> &rhs)
    {
        return (lhs.base() - rhs.base());
    }
    
    template<typename T>
    typename random_access_iterator<T>::difference_type operator-(const const_random_access_iterator<const T> &lhs, const const_random_access_iterator<const T> &rhs)
    {
        return (lhs.base() - rhs.base());
    }
    
}


#endif
