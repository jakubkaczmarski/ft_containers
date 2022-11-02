#include "random_access_it.hpp"
#include <memory>
#include <algorithm>
namespace ft
{


    template <typename T, typename allocator = std::allocator<T> >
    class vector
    {

    public:
        typedef allocator allocator_type;
        typedef T value_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef size_t size_type;
        typedef typename ft::random_access_iterator<value_type> iterator;

        // Constructors
        // default constructor
        explicit vector(const allocator_type &alloc = allocator_type())
            : begin_(0), end_(0), capacity_(0), alloc()
        {
        }
        void clear()
        {
            for(size_type i = 0; i < this->size();i++)
            {
                this->alloc.destroy(begin_ + i);
            }
            this->end_ = this->begin_;
        }
        T* data()
        {
            return (begin_);
        }
        const T* data() const
        {
            return (begin_);
        }
        reference front()
        {
            return *(begin_);
        }
        const_reference front() const
        {
            return *(begin_);
        }
        reference back()
        {
            return *(this->end_);
        }
        const_reference back() const
        {
            return *(this->end_);
        }
        bool empty() const
        {
            if(this->size() == 0)
            {
                return true;
            }else{
                return false;
            }
        }
        // Fill constructor
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        {
            begin_ = this->alloc.allocate(n);
            end_ = begin_;
            for (size_type i = 0; i < n; i++)
            {
                this->alloc.construct(end_, val);
                end_++;
            }
            capacity_ = end_;
        }
        // Range constructor
        template <typename InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
               typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = 0) : alloc(alloc)
        {

        }
        // Copy constructor
        vector(const vector &vec)
        {

        }
        iterator begin()
        {
            iterator halp(this->begin_);
            return halp;
        }
        iterator end()
        {
            iterator halp(this->end_);  
            return halp;
        }
        size_type max_size()
        {
            return (this->alloc.max_size());
        }
        void reserve( size_type new_cap )
        {
            if(new_cap > this->max_size())
            {
                throw std::length_error("Cannot allocate this much memory");
            }
            if(new_cap > capacity_ - begin_)
            {
                T *new_beg = this->alloc.allocate(new_cap);
                T *new_end = new_beg;
                T *tmp_beg_old = begin_;
                while(tmp_beg_old != end_)
                {
                    *new_end = *tmp_beg_old;
                    new_end++;
                    tmp_beg_old++;
                }
                this->alloc.deallocate(begin_, this->size());
                begin_ = new_beg;
                end_  = new_end;
                this->capacity_ = new_beg + new_cap;
            }
        }
        void resize(size_type count, T value = T())
        {
            int capacity_num = 0;
            T *tmp = begin_;
            while(tmp != capacity_)
            {
                capacity_num++;
                tmp++;
            }
            if(this->size() > count)
            {
                while(count != capacity_num--)
                {
                    this->alloc.destroy(end_--);
                }
                capacity_ = end_;
                return ;
            }else if(capacity_num < count){
                if(count > capacity_num * 2)
                {
                    this->alloc.allocate(count);
                }else{
                    this->alloc.allocate(count * 2);
                }
            }
            while(capacity_num < count)
            {
                alloc.construct(end_++, value);
                capacity_num++;
            }
            capacity_ = begin_ + count;
        }

        iterator insert(iterator position, const value_type &val)
        {
            this->insert(position, 1, val);
            return (position);
        }
        iterator erase (iterator position)
        {
            return (this->erase(position, position +1));
        }
        iterator erase( iterator first, iterator last )
        {
            T *tmp_first = first;
            int size_of_erase = last - first;
            while(first.base() != last.base())
            {
                this->alloc.destroy(first);
                first++;
            }
            std::copy(last.base(),end_, tmp_first);
            for(int i = 0; i < size_of_erase; i++)
            {
                alloc.destroy(end_);
                end_--;
            }
            return last - first;
        }

        //Inserting a single element 
        //{ 5 , 3 , 2 , 4}
        //insert(begin() + 1, 42)
        //{5 , 42, 3 , 2 , 4 }
        void insert(iterator position, size_type n, const value_type &val)
        {
            ft::vector<T> tmp(n, val);
            this->insert(position, tmp.begin(), tmp.end()); 
        }
        template<typename InputIterator>
        void assign (InputIterator first, InputIterator last)
        {
            this->clear();
            this->insert(this->end(), first, last);
        }
        void assign (size_type n, const value_type& val)
        {
            ft::vector<T> tmp(n, val);
            this->clear();
            this->insert(this->end(), tmp.begin(), tmp.end());
        }
        template<typename InputIterator>
        void insert(iterator position, InputIterator first, InputIterator second , typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0)
        {
            int inserted_size = second.base() - first.base();
            T   *tmp_beg = begin_;
            T   *after_insert = begin_;
            int size_after_insert = this->size() + (second.base() - first.base());
        
            T   *save_pos;
            if(inserted_size <= capacity_ - end_)
            {
                
                while(tmp_beg != position.base())
                {
                    tmp_beg++;
                }
                save_pos = tmp_beg;
                int i = 0;
                after_insert = tmp_beg + (second.base() - first.base());
                while(save_pos != end_)
                {
                    *after_insert = *save_pos;
                    i++;
                    after_insert++;
                    save_pos++;
                }
                while(first != second)
                {
                    *tmp_beg = *first;
                    
                    std::cout << *tmp_beg << std::endl;
                    tmp_beg++;
                    first++;
                } 
                
                this->end_ = after_insert;
                std::cout << *end_ << std::endl;
               
            }else if(this->size() + inserted_size > this->capacity())
            {
                T *old_bg = begin_;
                int cap_val;
                if(this->size() + inserted_size > this->capacity() * 2)
                {
                    tmp_beg = alloc.allocate(this->size() + inserted_size);
                    cap_val = this->size() + inserted_size;
                }else{
                    tmp_beg = alloc.allocate(this->capacity() * 2);
                    cap_val = this->capacity() * 2;
                }
                T *new_beg = tmp_beg;
                while(old_bg != position.base())
                {
                    *tmp_beg = *old_bg;
                    old_bg++;
                    tmp_beg++;
                }
                save_pos = tmp_beg;
                int i = 0;
                after_insert = tmp_beg + (second.base() - first.base());
                while(old_bg != end_)
                {
                    *after_insert = *old_bg;
                    i++;
                    after_insert++;
                    old_bg++;
                }
                while(first != second)
                {
                    *tmp_beg = *first;
                    tmp_beg++;
                    first++;
                }
                this->alloc.deallocate(begin_, this->capacity());
                begin_ = new_beg;
                this->capacity_ = begin_ + cap_val;
                this->end_ = after_insert;
            }
            
        }

        void print_all()
        {
            T *s = begin_;
            while (s != end_)
            {
                std::cout << *s << std::endl;
                s++;
            }
        }
        // Destructor
        ~vector()
        {
            this->alloc.deallocate(this->begin_, this->capacity_ - this->begin_);
        }
        //  Methods
        void push_back(const value_type &val)
        {
            this->insert(this->end_, val);
        }
        
        void pop_back()
        {
            erase(end_);
        }
        size_type capacity()
        {
            return (capacity_ - begin_);
        }

        size_type size()
        {
            return (end_ - begin_);
        }
        reference operator [](size_t num)
        {
            return (*(this->begin_ + num));
        }
        const_reference operator [](size_t num) const
        {
            return (*(this->begin_ + num));
        }
        reference at (size_type num)
        {
            if(num >= this->size())
            {
                throw std::out_of_range("Index too big");
            }
            return (*(this->begin_ + num));
        }
        const_reference at (size_type num) const
        {
            if(num >= this->size())
            {
                throw std::out_of_range("Index too big");
            }
            return (*(this->begin_ + num));
        }
    private:
        allocator_type alloc;
        T *begin_;
        T *end_;
        T *capacity_;
    };
}