#ifndef SET_HPP
#define SET_HPP

#include "rbt_iter.hpp"
#include "new_rbt.hpp"


#include "tools.hpp"


namespace ft
{
    template< typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
    class set
    {
        public:
        typedef T key_type;
        typedef T value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef Alloc allocator_type;
        typedef new_RBT<key_type, key_compare, allocator_type> tree_type;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename ft::const_rbt_iterator<typename tree_type::node, tree_type> iterator;
        typedef typename ft::const_rbt_iterator<typename tree_type::node, tree_type> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;


        explicit set(const key_compare & comp = key_compare(), const allocator_type &alloc = allocator_type())
        : tree_(comp,alloc), comp_(comp), alloc_(alloc)
        {

        }
        template<typename InputIterator>
        set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        : tree_(comp, alloc), comp_(comp), alloc_(alloc)
        {
            insert(first, last);
        }

        set (const set &cp)
        {
            *this = cp;
        }

        ~set()
        {
            tree_.clear();
            tree_.delete_ends();
        }

        set &operator= (const set &rhs)
        {
            alloc_ = rhs.alloc_;
            comp_ = rhs.comp_;
            clear();
            tree_ = rhs.tree_;
            return (*this);
        }

        iterator begin()
        {
            return tree_.begin();
        }

        const_iterator begin() const
        {
            return tree_.end();
        }

        iterator end()
        {
            return tree_.end();
        }
        
        const_iterator end() const
        {
            return tree_.end();
        }

        const_reverse_iterator rbegin() const
        {
            const_reverse_iterator tmp(end());
            return tmp;
        }

        reverse_iterator rbegin()
        {
            reverse_iterator tmp(end());
            return tmp;
        }

        reverse_iterator rend()
        {
            reverse_iterator tmp(begin());
            return tmp;
        }

        const_reverse_iterator rend() const
        {
            const_reverse_iterator tmp(begin());
            return tmp;
        }

        bool empty() const
        {
            return !(size());
        }

        size_type size() const
        {
            return tree_.size();
        }

        size_type max_size() const
        {
            return alloc_.max_size();
        }

        ft::pair<iterator, bool> insert(const value_type &val)
        {
            bool btmp = ((tree_.find_node<value_type>(val)) == tree_.getEnd());
            iterator tmp = iterator(tree_.insert(val), tree_.getEnd(), tree_.getRend());

            return ft::make_pair<iterator, bool>(tmp, btmp);
        }

        iterator insert(iterator pos, const value_type &val)
        {
            (void)pos;
            return insert(val).first;
        }

        template<typename InputIterator>
        void insert(InputIterator first, InputIterator second)
        {
            while(first != second)
            {
                tree_.insert(*(first));
                first++;
            }
        }

        void erase(iterator pos)
        {
            tree_.erase(pos);
        }

        size_type erase(const value_type &val)
        {
            return tree_.erase(val);
        }

        void erase(iterator first, iterator second)
        {
            set<value_type> tmp(first, second);
            for(iterator it = tmp.begin(); it != tmp.end(); it++)
                erase(it);
        }

        void swap(set &x)
        {
            tree_.swap(x.tree_);
        }

        void clear()
        {
            tree_.clear();
        }

        key_compare key_comp() const
        {
            return comp_;
        }

        value_compare value_comp() const
        {
            return comp_;
        }

        iterator find(const value_type &key)
        {
            return iterator(tree_.template find_node<key_type>(key), tree_.getEnd(), tree_.getRend());
        }

        const_iterator find(const value_type &key) const
        {
            return const_iterator(tree_.template find_node<const key_type>(key), tree_.getEnd(), tree_.getRend());
        }

        size_type count (const value_type &key) const
        {
            if(find(key) == end())
            {
                return 0;
            }else{
                return 1;
            }
        }

        ft::pair<iterator, iterator> equal_range(const key_type &key)
        {
            iterator it = find(key);
            if(it != end())
                return ft::make_pair<iterator, iterator>(it, ++it);
            it = begin();
            while(it != end() && comp_(*it, key))
            {
                it++;
            }
            return ft::make_pair<iterator, iterator>(it, it);
        }


        ft::pair<const_iterator, const_iterator> equal_range(const key_type &key) const
        {
            const_iterator it = find(key);
            if(it != end())
                return ft::make_pair<const_iterator, const_iterator>(it, ++it);
            it = begin();
            while(it != end() && comp_(*it, key))
            {
                it++;
            }
            return ft::make_pair<const_iterator, const_iterator>(it, it);
        }

        iterator lower_bound(const value_type &key)
        {
            iterator it = begin();
            while(it != end() && comp_(*it, key))
                it++;
            return it;
        }

        const_iterator lower_bound(const value_type &key) const
        {
            const_iterator it = begin();
            while(it != end() && comp_(*it, key))
                it++;
            return it;
        }

        const_iterator upper_bound(const value_type &key) const
        {
            const_iterator it = begin();
            while(it != end() && comp_(key, *it))
                it++;
            return it;
        }

        iterator upper_bound(const value_type &key)
        {
            iterator it = begin();
            while(it != end() && comp_(key, *it))
                it++;
            return it;
        }

        allocator_type get_allocator() const
        {
            return alloc_;
        }
        private:
        tree_type tree_;
        key_compare comp_;
        allocator_type alloc_;
    };

    template< class Key, class Compare, class Alloc >
    bool operator==( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        if (lhs.size() != rhs.size())
            return (false);
        return (ft::equal<typename ft::set<Key>::const_iterator, typename ft::set<Key>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin()));
    }
    template< class Key, class Compare, class Alloc >
    bool operator!=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        return (!(lhs == rhs));
    }

    template< class Key, class Compare, class Alloc >
    bool operator<( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        return (ft::lexicographical_compare<typename ft::set<Key>::const_iterator, typename ft::set<Key>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template< class Key, class Compare, class Alloc >
    bool operator<=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        return (!(rhs < lhs));
    }

    template< class Key, class Compare, class Alloc >
    bool operator>( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        return (rhs < lhs);
    }

    template< class Key, class Compare, class Alloc >
    bool operator>=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        return (!(lhs < rhs));
    }
}

namespace std
{
    template<typename Key, typename Compare, typename Alloc>
    void swap( ft::set<Key, Compare, Alloc> &f,ft::set<Key, Compare, Alloc> &s )
    {
        f.swap(s);
    }
}

#endif