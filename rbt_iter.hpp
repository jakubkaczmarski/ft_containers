#ifndef RBT_ITER_HPP
#define RBT_ITER_HPP

#include "tools.hpp"


//Parent needed for making a backwards iterator

namespace ft{
    template<typename T, typename Tree>
    class const_rbt_iterator;
    
    template<typename T, typename Tree>
    class rbt_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:
        typedef typename Tree::value_type value_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type difference_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer pointer;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;

        rbt_iterator() : iter_(0), end_(0), rend_(0) {};

        rbt_iterator(T *p, T *end, T *rend)
        : iter_(p), end_(end), rend_(rend)
        {
        }

        rbt_iterator(const rbt_iterator &rhs)
        : iter_(rhs.iter_), end_(rhs.end_), rend_(rhs.rend_)
        {
        }

        template<typename SecondTree>
        rbt_iterator(const rbt_iterator<T, SecondTree> &rhs) 
        : iter_(rhs.base()), end_(rhs.getEnd()), rend_(rhs.getRend())
        {}

        rbt_iterator &operator=(const rbt_iterator &cp)
        {
            iter_ = cp.iter_;
            end_ = cp.end_;
            rend_ = cp.rend_;
            return *this;
        }

        T *base() const
        {
            return iter_;
        }

        T* getEnd() const
        {
            return end_;
        }

        T *getRend() const
        {
            return rend_;
        }

        reference operator*() const
        {
            return (*(iter_)->data);
        }

        T *operator->() const
        {
            return iter_->data;
        }

        rbt_iterator &operator++()
        {
            T *tmp = iter_;

            if(tmp == rend_)
                tmp = rend_->parent;
            else if(tmp->right)
            {
                tmp = tmp->right;
                while(tmp->left)
                    tmp = tmp->left;
            }else{
                while(tmp->parent && tmp == tmp->parent->right)
                {
                    tmp = tmp->parent;
                }
                if(tmp->parent)
                    tmp = tmp->parent;
                else
                    tmp = end_;
            }
            iter_ = tmp;
            return (*this);
        }

        rbt_iterator operator++(int)
        {
            rbt_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        rbt_iterator &operator--()
        {
            T *tmp = iter_;
            if(tmp == end_)
            {
                tmp = end_->parent;
            }
            else if(tmp->left)
            {
                tmp = tmp->left;
                while(tmp->right)
                    tmp = tmp->right;
            }
            else
            {
                while(tmp->parent && tmp == tmp->parent->left)
                    tmp = tmp->parent;
                if(tmp->parent)
                    tmp = tmp->parent;
                else
                    tmp = rend_;
            }
            iter_ = tmp;
            return (*this);
        }

        rbt_iterator operator--(int)
        {
            rbt_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        bool operator==(rbt_iterator<T, Tree> &rhs)
        {
            return (this->base() == rhs.base());
        }
        bool operator==(const_rbt_iterator<T, Tree> &rhs) const
        {
            return (this->base() == rhs.base());
        }

        bool operator!=(rbt_iterator<T, Tree> &rhs)
        {
            return (this->base() != rhs.base());
        }

        bool operator!=(const_rbt_iterator<T, Tree> &rhs) const
        {
            return (this->base() != rhs.base());
        }

        private:
        pointer iter_;
        pointer end_;
        pointer rend_;
    };

    template<typename T, typename Tree>
    class const_rbt_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:
        typedef const typename Tree::value_type value_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type difference_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer pointer;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;

        const_rbt_iterator() : iter_(0), end_(0), rend_(0) {};

        const_rbt_iterator(T *p, T *end, T *rend)
        : iter_(p), end_(end), rend_(rend)
        {
        }

        const_rbt_iterator(const const_rbt_iterator &rhs)
        : iter_(rhs.iter_), end_(rhs.end_), rend_(rhs.rend_)
        {
        }

        const_rbt_iterator(const rbt_iterator<T, Tree> &rhs)
        {
            *this = rhs;
        }

        template<typename SecondTree>
        const_rbt_iterator(const rbt_iterator<T, SecondTree> &rhs) 
        : iter_(rhs.base()), end_(rhs.getEnd()), rend_(rhs.getRend())
        {}

        template<typename SecondTree>
        const_rbt_iterator(const const_rbt_iterator<T, SecondTree> &rhs) 
        : iter_(rhs.base()), end_(rhs.getEnd()), rend_(rhs.getRend())
        {}
        
        const_rbt_iterator &operator=(const const_rbt_iterator &cp)
        {
            iter_ = cp.iter_;
            end_ = cp.end_;
            rend_ = cp.rend_;
            return *this;
        }

        const_rbt_iterator &operator=(const rbt_iterator<T, Tree> &cp)
        {
            iter_ = cp.base();
            end_ = cp.getEnd();
            rend_ = cp.getRend();
            return *this;
        }

        T *base() const
        {
            return iter_;
        }

        T* getEnd() const
        {
            return end_;
        }

        T *getRend() const
        {
            return rend_;
        }

        const reference operator*() const
        {
            return (*(iter_)->data);
        }

        const T *operator->() const
        {
            return iter_->data;
        }

        const_rbt_iterator &operator++()
        {
            T *tmp = iter_;

            if(tmp == rend_)
                tmp = rend_->parent;
            else if(tmp->right)
            {
                tmp = tmp->right;
                while(tmp->left)
                    tmp = tmp->left;
            }else{
                while(tmp->parent && tmp == tmp->parent->right)
                {
                    tmp = tmp->parent;
                }
                if(tmp->parent)
                    tmp = tmp->parent;
                else
                    tmp = end_;
            }
            iter_ = tmp;
            return (*this);
        }

        const_rbt_iterator operator++(int)
        {
            const_rbt_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        const_rbt_iterator &operator--()
        {
            T *tmp = iter_;
            if(tmp == end_)
            {
                tmp = end_->parent;
            }
            else if(tmp->left)
            {
                tmp = tmp->left;
                while(tmp->right)
                    tmp = tmp->right;
            }
            else
            {
                while(tmp->parent && tmp == tmp->parent->left)
                    tmp = tmp->parent;
                if(tmp->parent)
                    tmp = tmp->parent;
                else
                    tmp = rend_;
            }
            iter_ = tmp;
            return (*this);
        }

        const_rbt_iterator operator--(int)
        {
            const_rbt_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        bool operator==(rbt_iterator<T, Tree> &rhs)
        {
            return (this->base() == rhs.base());
        }
        bool operator==(const_rbt_iterator<T, Tree> &rhs) const
        {
            return (this->base() == rhs.base());
        }

        bool operator!=(rbt_iterator<T, Tree> &rhs)
        {
            return (this->base() != rhs.base());
        }

        bool operator!=(const_rbt_iterator<T, Tree> &rhs) const
        {
            return (this->base() != rhs.base());
        }

        private:
        pointer iter_;
        pointer end_;
        pointer rend_;
    };
}




#endif

