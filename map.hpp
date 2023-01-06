/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:23:29 by jkaczmar          #+#    #+#             */
/*   Updated: 2023/01/06 15:29:38 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_rbt.hpp"
#include "rbt_iter.hpp"
#include "tools.hpp"
// #include <functional>
#include <memory>

namespace ft
{
    template<typename Key, typename T, 
        typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef new_RBT<value_type, key_compare, allocator_type> tree_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        //Iterators        
        typedef rbt_iterator<typename tree_type::node, tree_type> iterator;
        typedef const_rbt_iterator<typename tree_type::node, tree_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        class value_compare : std::binary_function<value_type, value_type, bool>
        {
            friend class map;

            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {} 
            
            public:
                typedef bool result_type;
                typedef value_type first_arg_type;
                typedef value_type second_arg_type;
                bool operator() (const value_type &x, const value_type &y) const
                {
                    return comp(x.first, y.second);    
                }
        };
        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : tree_(comp, alloc), comp_(comp), alloc_(alloc)
        {

        }
        
        template <typename InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) : tree_(comp, alloc), comp_(comp), alloc_(alloc) 
        {
            insert(first, last);   
        }

        map(const map &x)
        {
            *this = x;
        }

        ~map()
        {
            this->tree_.clear();
            this->tree_.delete_ends();
        }
        
        map &operator=(const map &x)
        {
            alloc_ = x.alloc_;    
            comp_ = x.comp_;
            tree_.clear();
            tree_ = x.tree_;
            return (*this);
        }
        
    
        iterator begin()
        {
            return tree_.begin();
        }
        const_iterator begin() const
        {
            return tree_.begin();
        }
        iterator end()
        {
            return tree_.end();
        }
        const_iterator end() const
        {
            return tree_.end();
        }
        reverse_iterator rbegin()
        {
            reverse_iterator tmp(tree_.end());
            return tmp;
        }
        const_reverse_iterator rbegin() const
        {
            const_reverse_iterator tmp(this->end());
            return tmp;
        } 
        
        reverse_iterator rend()
        {
            return (reverse_iterator(tree_.begin()));
        }

        const_reverse_iterator rend() const
        {
            return (reverse_iterator(tree_->begin()));
        }

        
        bool empty() const
        {
            if(this->size() == 0)
                return true;
            return false;
        }

        size_type size() const
        {
            return this->tree_.size();
        }

        size_type max_size() const
        {
            return this->tree_.max_size();
        }

        mapped_type &operator[] (const key_type &k)
        {
            return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
        }

        mapped_type &at (const key_type &k)
        {
            iterator tmp = find(k);
            if(tmp == this->end())
                throw std::out_of_range("Out of range");
            return (*tmp).second;
        }

        ft::pair<iterator, bool> insert (const value_type &val)
        {
            bool tmp;
            if(tree_.find_node(val) == tree_.getEnd())
                tmp = true;
            else
                tmp = false;
            iterator temp = iterator(tree_.insert(val), tree_.getEnd(), tree_.getRend());
            return ft::make_pair<iterator, bool>(temp, tmp);
        }

        iterator insert(iterator position, const value_type &val)
        {
            if(position){}
            return (insert(val).first);
        }

        template<typename InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while(first != last)
            {
                tree_.insert(*first);
                first++;
            }
        }

        void erase (iterator pos)
        {
            tree_.delete_val(*pos);
        }

        size_t erase(const key_type &k)
        {
            return tree_.delete_val(k);
        }

        void erase(iterator first, iterator last)
        {
            ft::map<key_type, mapped_type> tmp(first, last);
            iterator it = tmp.begin();
            while(it != tmp.end())
            {
                erase(it->first);
                it++;
            }
        }

        void swap(map &other)
        {
            tree_.swap(other.tree_);
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
            return (value_compare(comp_));
        }

        iterator find(const key_type &k)
        {
            return (iterator(tree_.template find_node<key_type>(k), tree_.getEnd(), tree_.getRend()));
        }

        const_iterator find(const key_type &k)  const
        {
            return (const_iterator(tree_.template find_node<const key_type>(k), tree_.getEnd(), tree_.getRend()));
        }

        size_t count (const key_type &k) const
        {
            if(find(k) == end())
                return 0;
            else
                return 1;
        }

        iterator lower_bound(const key_type &k) 
        {
            iterator it = begin();
            while(it != end() && comp_(it->first, k))
                it++;
            return it;
        }

        const_iterator lower_bound(const key_type &k) const
        {
            const_iterator it = begin();
            while(it != end() && comp_(it->first, k))
                it++;
            return it;
        }

        iterator upper_bound(const key_type &k) 
        {
            iterator it = begin();
            while(it != end() && !(comp_(k, it->first)))
            {
                it++;
            }
            return it;
        }
        
        const_iterator upper_bound(const key_type &k) const
        {
            const_iterator it = begin();
            while(it != end() && !(comp_(k, it->first)))
            {
                it++;
            }
            return it;
        }

        ft::pair<iterator, iterator> equal_range(const key_type &k)
        {
            iterator it = find(k);
            if(it != end())
                return ft::make_pair<iterator, iterator>(it, ++it);
            it = begin();
            while(it != end() && comp_(it->first,k))
                it++;
            return ft::make_pair<iterator, iterator>(it, it);
        }
        
        ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
        {
            const_iterator it = find(k);
            if(it != end())
                return ft::make_pair<const_iterator, const_iterator>(it, ++it);
            it = begin();
            while(it != end() && comp_(it->first,k))
                it++;
            return ft::make_pair<const_iterator, const_iterator>(it, it);
        }

        allocator_type get_allocator() const
        {
            return alloc_;
        }
            
            private:
            ft::new_RBT<value_type, key_compare, allocator_type> tree_;
            key_compare comp_;
            allocator_type alloc_;
        };

        template<typename Key, typename T, typename Compare, typename Alloc>
        bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
        {
            if(lhs.size() != rhs.size())
                return false;
            return (ft::equal<typename ft::map<Key, T>::const_iterator, typename ft::map<Key, T>::const_iterator>(lhs.begin(), rhs.end(), rhs.begin()));
        }

        template<typename Key, typename T, typename Compare, typename Alloc>
        bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
        {
            return !(lhs == rhs);
        }

        template<typename Key, typename T, typename Compare, typename Alloc>
        bool operator< (const map<Key, T, Compare, Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
        {
            return ft::lexicographical_compare<typename ft::map<Key, T>::const_iterator, typename ft::map<Key, T>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }

        template<typename Key, typename T, typename Compare, typename Alloc>
        bool operator<= (const map<Key, T, Compare, Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
        {
            return !(rhs < lhs);
        }

        template<typename Key, typename T, typename Compare, typename Alloc>
        bool operator> (const map<Key, T, Compare, Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
        {
            return rhs < lhs;
        }

        template<typename Key, typename T, typename Compare, typename Alloc>
        bool operator>= (const map<Key, T, Compare, Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
        {
            return !(lhs < rhs);
        }
    template<class Key, class T, class Compare, class Alloc>
    void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
    {
        x.swap(y);
    }        
};