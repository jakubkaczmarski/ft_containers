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

        rbt_iterator(T *p = nullptr) : iter_(p), nil_(p)
        {
            if(p)
            {
                while(nil_->left)
                {
                    nil_ = nil_->left;
                }
            }
        }

        rbt_iterator(T *ptr, T *nil) : iter_(ptr), nil_(nil)
        {

        }

        rbt_iterator(const rbt_iterator &cp) 
        : iter_(cp.iter_), nil_(cp.nil)
        {
        }

        virtual ~rbt_iterator(){

        }

        rbt_iterator &operator=(const rbt_iterator &cp)
        {
            iter_ = cp.iter_;
            nil_ = cp.nil_;
            prev_ = cp.prev_;
            return *this;
        }

        T *base() const
        {
            return this->iter_;
        }

        reference operator*() const
        {
            return *iter_->data;
        }

        reference operator->() const
        {
            return &(this->operator*());
        }

        rbt_iterator &operator++()
        {
            T *tmp = iter_;
            if(!tmp)
                tmp = prev_;
            else if(tmp->right != nil_)
            {
                tmp = tmp->right;
                while(tmp->left != nil_)
                {
                    tmp = tmp->left;
                }
            }else if(tmp->parent && tmp == tmp->parent->left)
            {
                tmp = tmp->parent;
            }else if(tmp->parent && tmp == tmp->parent->right)
            {
                while(tmp->parent && tmp == tmp->parent->right)
                {
                    tmp = tmp->parent;
                }
                if(tmp->parent)
                    tmp = tmp->parent;
                else
                    tmp = nil_;
            }else{
                tmp = nil_;
            }
            prev_ = iter_;
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
            if(!tmp->parent && tmp->left == nil_)
            {
                tmp = tmp->parent;
            }else if(tmp == nil_)
            {
                tmp = nil_->parent;
            }else if(tmp->left != nil_ && tmp->left_)
            {
                tmp = tmp->left;
                while(tmp->right != nil_)
                {
                    tmp = tmp->right;
                }
            }else if(tmp->parent && tmp == tmp->parent->right)
            {
                tmp = tmp->parent;
            }else if(tmp->parent && tmp == tmp->parent->left)
            {
                while(tmp->parent && tmp ==  tmp->parent->left)
                {
                    tmp = tmp->parent;
                }
                if(tmp->parent)
                {
                    tmp = tmp->parent;
                }else{
                    tmp = nullptr;
                }
            }else
            {
                tmp = nil_->parent;
            }
            prev_ = iter_;
            iter_ = tmp;
            return (*this);
        }
        
        rbt_iterator operator--(int)
        {
            rbt_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        pointer getNil() const
        {
            return nil_;
        }
        pointer getIter() const
        {
            return iter_;
        }
        pointer getPrev() const
        {
            return prev_;
        }

        bool operator==(const rbt_iterator<T, Tree> &rhs) const
        {
            return (this->base() == rhs.base());
        }
        bool operator==(const const_rbt_iterator<T, Tree> &rhs) const
        {
            return (this->base() == rhs.base());
        }

        bool operator!=(const rbt_iterator<T, Tree> &rhs) const
        {
            return (this->base() != rhs.base());
        }

        bool operator!=(const const_rbt_iterator<T, Tree> &rhs) const
        {
            return (this->base() != rhs.base());
        }

        private:
        pointer iter_;
        pointer prev_;
        pointer nil_;
    };


        template<typename T, typename Tree>
    class const_rbt_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:
        typedef typename Tree::value_type value_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type difference_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer pointer;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;

        const_rbt_iterator(T *p = nullptr) : iter_(p), nil_(p)
        {
            if(p)
            {
                while(nil_->left)
                {
                    nil_ = nil_->left;
                }
            }
        }

        const_rbt_iterator(T *ptr, T *nil) : iter_(ptr), nil_(nil)
        {

        }

        const_rbt_iterator(const const_rbt_iterator &cp) 
        : iter_(cp.iter_), nil_(cp.nil)
        {
        }

        virtual ~const_rbt_iterator(){

        }

        const_rbt_iterator &operator=(const const_rbt_iterator &cp)
        {
            iter_ = cp.iter_;
            nil_ = cp.nil_;
            prev_ = cp.prev_;
            return *this;
        }

        T *base() const
        {
            return this->iter_;
        }

        reference operator*() const
        {
            return *iter_->data;
        }

        reference operator->() const
        {
            return &(this->operator*());
        }

        const_rbt_iterator &operator++()
        {
            T *tmp = iter_;
            if(!tmp)
                tmp = prev_;
            else if(tmp->right != nil_)
            {
                tmp = tmp->right;
                while(tmp->left != nil_)
                {
                    tmp = tmp->left;
                }
            }else if(tmp->parent && tmp == tmp->parent->left)
            {
                tmp = tmp->parent;
            }else if(tmp->parent && tmp == tmp->parent->right)
            {
                while(tmp->parent && tmp == tmp->parent->right)
                {
                    tmp = tmp->parent;
                }
                if(tmp->parent)
                    tmp = tmp->parent;
                else
                    tmp = nil_;
            }else{
                tmp = nil_;
            }
            prev_ = iter_;
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
            if(!tmp->parent && tmp->left == nil_)
            {
                tmp = tmp->parent;
            }else if(tmp == nil_)
            {
                tmp = nil_->parent;
            }else if(tmp->left != nil_ && tmp->left)
            {
                tmp = tmp->left;
                while(tmp->right != nil_)
                {
                    tmp = tmp->right;
                }
            }else if(tmp->parent && tmp == tmp->parent->right)
            {
                tmp = tmp->parent;
            }else if(tmp->parent && tmp == tmp->parent->left)
            {
                while(tmp->parent && tmp ==  tmp->parent->left)
                {
                    tmp = tmp->parent;
                }
                if(tmp->parent)
                {
                    tmp = tmp->parent;
                }else{
                    tmp = nullptr;
                }
            }else
            {
                tmp = nil_->parent;
            }
            prev_ = iter_;
            iter_ = tmp;
            return (*this);
        }
        
        const_rbt_iterator operator--(int)
        {
            const_rbt_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        pointer getNil() const
        {
            return nil_;
        }
        pointer getIter() const
        {
            return iter_;
        }
        pointer getPrev() const
        {
            return prev_;
        }

        bool operator==(const rbt_iterator<T, Tree> &rhs) const
        {
            return (this->base() == rhs.base());
        }
        bool operator==(const const_rbt_iterator<T, Tree> &rhs) const
        {
            return (this->base() == rhs.base());
        }

        bool operator!=(const rbt_iteratotior<T, Tree> &rhs) const
        {
            return (this->base() != rhs.base());
        }

        bool operator!=(const const_rbt_iterator<T, Tree> &rhs) const
        {
            return (this->base() != rhs.base());
        }

        private:
        pointer iter_;
        pointer prev_;
        pointer nil_;
    };
}




#endif

