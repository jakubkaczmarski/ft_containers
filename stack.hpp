#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
    template<typename T, typename Container = ft::vector<T> >
    class stack
    {
        public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;
        typedef typename container_type::reference reference;
        typedef typename container_type::const_reference const_reference;
        explicit stack(const container_type &cont = container_type())
        : con_(cont)
        {

        }
        stack &operator= (const stack &ot)
        {
            con_ = ot.con_;
            return (*this);
        }

        ~stack(){}

        bool empty() const
        {
            return !(this->con_.size());
        }

        size_type size() const
        {
            return (this->con_.size());
        }

        value_type &top()
        {
            return this->con_.back();
        }

        const_reference top() const
        {
            return (this->con_.back());
        }

        void push(const value_type &val)
        {
            con_.push_back(val);
        }

        void pop()
        {
            con_.pop_back();
        }
        template <typename x, typename y>
        friend bool operator ==(const stack<x,y> &lhs, const stack<x,y> &rhs);
         template <typename x, typename y>
        friend bool operator <(const stack<x,y> &lhs, const stack<x,y> &rhs);

        protected:
        container_type con_;
    };

    template<typename T, typename Container>
    bool operator== (const stack<T, Container> &lhs, const stack<T, Container>& rhs)
    {
        return (lhs.con_ == rhs.con_);
    }

    template<typename T, typename Container>
    bool operator< (const stack<T, Container> &lhs, const stack<T, Container>& rhs)
    {
        return (lhs.con_ < rhs.con_);
    }

    template<typename T, typename Container>
    bool operator!= (const stack<T, Container> &lhs, const stack<T, Container>& rhs)
    {
        return (!(lhs == rhs));
    }

    template<typename T, typename Container>
    bool operator<= (const stack<T, Container> &lhs, const stack<T, Container>& rhs)
    {
        return (!(rhs < lhs));
    }

    template<typename T, typename Container>
    bool operator>(const stack<T, Container> &lhs, const stack<T, Container>& rhs)
    {
        return (rhs < lhs);
    }

    template<typename T, typename Container>
    bool operator>= (const stack<T, Container> &lhs, const stack<T, Container>& rhs)
    {
        return (!(lhs < rhs));
    }
}


#endif