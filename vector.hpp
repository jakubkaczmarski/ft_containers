#ifndef Vector_HPP
#define Vector_HPP

#include <memory>
#include <iostream>
#include "tools.hpp"
#include "random_access_iterator.hpp"

namespace ft
{
    template<typename T, typename Alloc = std::allocator<T> >
    class Vector
    {
        public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::random_access_iterator<T> iterator;
        typedef typename ft::const_random_access_iterator<const T> const_iterator;
        typedef typename ft::reverse_iterator<T> reverse_iterator;
        typedef typename ft::reverse_iterator<const T> const_reverse_iterator;
        typedef typename iterator_traits<iterator>::difference_type difference_type;
        typedef typename allocator_type::size_type size_type;

        explicit Vector (const allocator_type &alloc = allocator_type()) : alloc_(alloc), 
        start_(nullptr), end_(nullptr), capacity_(nullptr){}

        explicit Vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        : alloc_(alloc), start_(nullptr), end_(nullptr), capacity_(nullptr)
        {
            start_ = alloc_.allocate(n);
            capacity_ = start_ + n;
            end_ = start_;
            while(n != 0)
            {
                alloc_.construct(end_, val);
                end_++;
            }
        }

        template<typename InputIterator>
        Vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
				typename enable_if<!is_integral<InputIterator>::value>::type* = nullptr)
        : alloc_(alloc)
        {
            difference_type n = ft::distance(first, last);
            start_ = alloc_.allocate(n);
            end_ = start_;
            capacity_ = start_ + n;
            while(n != 0)
            {
                alloc_.construct(end_, *first);
                first++;
                end_++;
                n--;
            }
        }

        Vector(const Vector &val) : alloc_(val.alloc_), start_(NULL), end_(NULL), capacity_(NULL)
        {
            this->insert(this->begin(), val.begin(), val.end());
        }

        Vector &operator=(const Vector &x)
        {
            if(x == *this)
            {
                return (*this);
            }
            this->clear();
            this->insert(this->begin(), x.begin(), x.end());
            return (*this);
        }

        ~Vector(void)
        {
            this->clear();
            alloc_.deallocate(start_, this->capacity());
        }

        template<typename InputIterator>
        void assign(InputIterator first, InputIterator second, 
            typename enable_if<!is_integral<InputIterator >::value >::type* = nullptr)
        {   
            this->clear();
            size_type dist = ft::distance(first,second);

            if(size_type(capacity_ - start_) >= dist)
            {
                while(first != second)
                {
                    alloc_.construct(end_, *first);
                    first++;
                    end_++;
                }
            }else{
                pointer tmp_s = alloc_.allocate(dist);
                pointer tmp_e = tmp_s;
                pointer tmp_c = tmp_s + dist;
                while(first != second)
                {
                    alloc_.construct(tmp_e, *first);
                    first++;
                    tmp_e++;
                }
                alloc_.deallocate(start_, this->capacity());
                start_ = tmp_s;
                end_ = tmp_e;
                capacity_ = tmp_c;
            }
        }

        void assign(size_type n, const value_type &val)
        {
            this->clear();
            if(n == 0)
                return ;
            if(size_type(capacity_ - start_) >= n)
            {
                while(n != 0)
                {
                    alloc_.construct(end_, val);
                    n--;
                    end_++;
                }
            }else{
                alloc_.deallocate(start_, this->capacity());
                start_ = alloc_.allocate(n);
                end_ = start_;
                capacity_ = start_ + n;
                while(n != 0)
                {
                    alloc_.construct(end_, val);
                    n--;
                    end_++;
                }
            }
        }

        iterator begin()
        {
            return start_;
        }

        const_iterator begin() const
        {
            return const_iterator(start_);
        }

        iterator end()
        {
            if(this->empty())
            {
                return start_;
            }else{
                return end_;
            }
        }

        const_iterator end() const
        {
            if(this->empty())
            {
                return const_iterator(start_);
            }else{
                return const_iterator(end_);
            }
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(this->end());
        }

        const_reverse_iterator rbegin() const
        {
            return reverse_iterator(this->end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(this->begin());
        }
        
        const_reverse_iterator rend() const
        {
            return reverse_iterator(this->begin());
        }

        void swap(Vector &val)
        {
            pointer val_beg = val.start_;
            pointer val_end = val.end_;
            pointer val_capacity = val.capacity_;
            allocator_type val_alloc = val.alloc_;

            val.start_ = this->start_;
            val.end_ = this->end_;
            val.capacity_ = this->capacity_;
            val.alloc_ = this->alloc_;

            start_ = val_beg;
            end_  = val_end;
            capacity_ = val_capacity;
            alloc_ = val_alloc;
        }

        size_type size() const
        {
            return end_ - start_;
        }

        size_type max_size() const
        {
            return allocator_type().max_size();
        }

        size_type capacity() const
        {
            return capacity_ - start_;
        }

        bool empty() const
        {
            if(this->size() == 0)
                return true;
            return false;
        }

        reference operator[](size_type n)
        {
            return *(start_ + n);
        }

        const_reference operator[](size_type n) const
        {
            return *(start_ + n);
        }

        reference at(size_type n)
        {
            if(n >= this->size())
            {
                throw std::out_of_range("Accesing element out of range using at()");
            }
            return ((*this)[n]);
        }

        const_reference at(size_type n) const
        {
            if(n >= this->size())
            {
                throw std::out_of_range("Accesing element out of range using at()");
            }
            return ((*this)[n]);
        }

        reference front()
        {
            return *(start_);
        }

        const_reference front() const
        {
            return *(start_);
        }

        reference back()
        {
            return *(end_ - 1);
        }

        const_reference back() const
        {
            return *(end_ - 1);
        }

        pointer data()
        {
            return start_;
        }

        const_pointer data() const
        {
            return start_;
        }

        void reserve(size_type n)
        {
            if(this->max_size() < n)
            {
                throw std::length_error("Cannot reserve this much memory");
            }else if(n > this->capacity())
            {
                pointer tmp_s = start_;
                pointer tmp_e = end_;
                size_type tmp_size = this->size();
                size_type tmp_capactiy = this->capacity();

                start_ = alloc_.allocate(n);
                capacity_ = start_ + n;
                end_ = start_;
                while(tmp_s != tmp_e)
                {
                    alloc_.construct(end_, *tmp_s);
                    end_++;
                    tmp_s++;
                }
                alloc_.deallocate(tmp_s - tmp_size, tmp_capactiy);
            }
        }
        void pop_back()
        {
            alloc_.destroy(&(this->back()));
            end_--;
        }
        void push_back(const value_type &val)
        {
            if(end_ == capacity_)
            {
                size_type n;
                if(this->size() == 0)
                    n = 1;
                else{
                    n = this->size() * 2;
                }
                this->reserve(n);
            }
            alloc_.construct(end_, val);
            end_++;
        }

        void clear()
        {
            size_type size = this->size();
            for(size_type i = 0; i < size; i++)
            {
                alloc_.destroy(end_);
                end_--;
            }
        }


        iterator erase(iterator first, iterator last)
        {
            pointer pos = first.base();
            //Destroy elements 
            while(first != last)
            {
                alloc_.destroy(first);
                first++;
            }
            //Move elements 
            for(int i = 0; i < end_ - last; i++)
            {
                alloc_.destruct(last + i);
                alloc_.construct(pos + i, last + i);
            }
            end_ = last - pos;
            return (iterator(pos));
        }

        iterator erase(iterator position)
        {
            pointer pos = position.base();
            alloc_.destroy(pos);
            if(pos + 1 != end_)
            {
                for(int i = 0; i < end_ - pos - 1; i++)
                {
                    alloc_.construct(&(*pos) + i, &(*pos) + i + 1);
                    alloc_.destruct(&(*pos) + i + 1);
                }
            }
            end_--;
            return (iterator(pos));
        }

        allocator_type get_allocator() const 
        {
            return alloc_;
        }

        //Inserting single element
        iterator insert(iterator pos, const value_type& val)
        {
            size_type ins_pos = pos.base() - start_;
            if(size_type(capacity_ - end_) >= this->size() + 1)
            {
                for(size_type i = 0; i < ins_pos; i++)
                {
                    alloc_.construct(end_ - i, *(end_ - i - 1));
                }
                end_++;
                alloc_.construct(start_ + ins_pos, val);
            }else{
                int new_cap;
                if(this->size() == 0)
                    new_cap = 1;
                else{
                    new_cap = this->capacity() * 2;
                }
                pointer tmp_s = alloc_.allocate(new_cap);
                pointer tmp_e = tmp_s + this->size() + 1;
                pointer tmp_cap = tmp_s + new_cap;
                for(size_type i = 0; i < ins_pos; i++)
                {
                    alloc_.construct(tmp_s + i, *(start_ + i));
                }
                alloc_.construct(tmp_s + ins_pos, val);
                for(size_type i = 0; i < this->size() - ins_pos; i++)
                {
                    alloc_.construct(tmp_e - i - 1, *(end_ - i - 1));  
                }
                for(size_type i = 0; i < this->size(); i++)
                {
                    alloc_.destroy(start_ + i);
                }
                alloc_.deallocate(start_, this->capacity());
                start_ = tmp_s;
                end_ = tmp_e;
                capacity_ = tmp_cap;
            }
            return iterator(start_ + ins_pos);
        };

        //Inserting n elements to the position
        void insert(iterator pos, size_type n, const value_type &val)
        {
            if(n == 0)
                return ;
            if(n > this->max_size())
                throw std::length_error("Too many elements");
            size_type ins_pos = &(*pos) - start_;
            if(size_type(this->capacity_ - end_) >= n)
            {
                for(size_type i = 0;i < this->size() - ins_pos; i++)
                {
                    alloc_.construct(end_ - i + (n - 1), *(end_ - i - 1));
                }
                end_ += n;
                while(n != 0)
                {
                    alloc_(ins_pos + (n - 1), val);
                    n--;
                }
            }else{
                int new_cap;
                if(this->size() == 0)
                    new_cap = 0;
                else{
                    new_cap = this->capacity() * 2;
                }
                pointer tmp_s = alloc_.allocate(new_cap);
                pointer tmp_e = pointer();
                pointer tmp_cap = tmp_s + new_cap;
                
                if(size_type(tmp_cap - tmp_s) < this->size() + n)
                {
                    if(tmp_s)
                    {
                        alloc_deallocate(tmp_s, tmp_cap - tmp_s);
                    }
                    new_cap = this->size() + n;
                    tmp_s = this->alloc_.allocate(new_cap);
                    tmp_cap = tmp_s + new_cap;
                }
                tmp_e = tmp_s + this->size() + n;
                for(size_type i = 0; i < ins_pos - start_; i++)
                {
                    alloc_.construct(tmp_s + i, *(start_ + i));
                }
               
                for(size_type i = 0; i < n; i++)
                {
                    alloc_.construct(tmp_s + &(*pos) + i, val);
                }

                for(size_type i = 0; i < this->size() - &(*pos); i++)
                {
                    alloc_.construct(tmp_e - i - 1, *(end_ - i - 1));
                }
                for(size_type i = 0; i < this->size(); i++)
                {
                    alloc_.destroy(start_ + i);
                }
                alloc_.deallocate(start_, this->capacity());
                start_ = tmp_s;
                end_ = tmp_e;
                capacity_ = tmp_cap;
            }
        }

        template<typename InputIterator>
        void insert(iterator pos, InputIterator first, InputIterator second)
        {
            size_type n = ft::distance(first, second);
            if(size_type(capacity_ - end_) >= n)
            {
                for(size_type i = 0; i < (this->size() - (&(*pos) - this->start_)); i++)
                {
                    alloc_.construct(end_ - i + n - 1, *(end_ - i - 1));
                }
                end_ += n;
                while(first != second)
                {
                    alloc_.construct(&(*pos), *first);
                    pos++;
                    first++;
                }
            }else{
                pointer tmp_s = alloc_.allocate(this->size() * 2);
                pointer tmp_e = tmp_s + this->size() + n;
                pointer tmp_c = tmp_s + (this->size() * 2);
                if(size_type(tmp_c - tmp_s) < this->size() + n)
                {
                    if(tmp_s)
                    {
                        alloc_.deallocate(tmp_s, tmp_c - tmp_s);
                    }
                    tmp_s = alloc_.allocate(this->size() + n);
                    tmp_e = tmp_s + this->size() + n;
                    tmp_c = tmp_e;
                }
                for(int i = 0; i < (&(*pos) - this->start_); i++)
                {
                    alloc_.construct(tmp_s + i, *(start_ + i));
                }
                for(int i = 0; first != second; i++)
                {
                    alloc_.construct(tmp_s + (&(*pos) - this->start_) + i, *first);
                    first++;
                }
                for(size_type i = 0; i < (this->size() - (&(*pos) - this->start_)); i++)
                {
                    alloc_.construct(tmp_s + (&(*pos) - this->start_) + n + i, *(pos + i));
                }
                for(size_type i = 0; i < this->size(); i++)
                {
                    alloc_.destroy(start_ + i);
                }
                alloc_.deallocate(start_, this->capacity());
                start_ = tmp_s;
                end_ = tmp_e;
                capacity_ = tmp_c;
            }
        }
        private:
        pointer start_;
        pointer end_;
        pointer capacity_;
        allocator_type alloc_;
    };
template<class T, class Alloc>
bool operator==(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
    if(lhs.size() != rhs.size())
        return false;
    typename Vector<T, Alloc>::const_iterator iter_l = lhs.begin();
    typename Vector<T, Alloc>::const_iterator iter_r = rhs.begin();

    while(iter_l != lhs.end())
    {
        if(*iter_l != *iter_r || iter_r == rhs.end())
        {
            return false;
        }
        iter_l++;
        iter_r++;
    }
    return true;
}

template<class T, class Alloc>
bool operator!=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
    return (!(lhs == rhs));
}

template<class T, class Alloc>
bool operator<(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class T, class Alloc>
bool operator<=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
    return (!(rhs < lhs));
}

template<class T, class Alloc>
bool operator>(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
    return rhs < lhs;
}

template<class T, class Alloc>
bool operator>=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
    return (!(lhs < rhs));
}

template<typename T, class Alloc>
void swap(Vector<T, Alloc> &one, Vector<T, Alloc> &two)
{
    one.swap(two);
}

};
#endif