#include "random_access_it.hpp"
#include <memory>

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
            size_t pos_num = position.base() - begin_;
            size_t vec_size = this->size();
            iterator position_to_place = position;
            iterator temp_end = end_ - 1 ;
            if(end_ + 1 != capacity_ && end_ != capacity_)
            {
                int i = pos_num;
                while(pos_num < vec_size)
                {
                    *(temp_end + 1) = *temp_end;
                    temp_end--;
                    pos_num++;
                }
                *position_to_place = val;
                std::cout << *position_to_place << std::endl;
                end_++;
            }else{
                int num = end_ - begin_;
                //Reallocate and change the pointers in the right order
                T *temp_og_begin = begin_;
                T  *temp_beg;
                T  *temp_end;
                temp_beg = alloc.allocate((num + 1 )* 2);
                temp_end = temp_beg;
                    while(temp_og_begin != end_)
                    {
                        
                        if(temp_og_begin == position_to_place.base())
                        {

                            temp_beg++;
                            *temp_beg = val;
                            position_to_place = NULL;
                            continue;
                        }
                        *temp_beg = *temp_og_begin;
                        temp_beg++;
                        temp_og_begin++;
                    }
                }
            return position_to_place;
        }
        //Inserting a single element 
        //{ 5 , 3 , 2 , 4}
        //insert(begin() + 1, 42)
        //{5 , 42, 3 , 2 , 4 }
        void insert(iterator position, size_type n, const value_type &val)
        {
            // if()
        }
        template<typename InputIterator>
        void insert(iterator position, InputIterator first, InputIterator second)
        {
            int inserted_size = second - first;
            T   *tmp_beg = begin_;
            T   *after_insert = begin_;
            T   *end_after_insert = end_ + second - first;
            T   *save_pos;
            if(inserted_size <= capacity_ - end_)
            {
                while(tmp_beg != position)
                {
                    tmp_beg++;
                }
                save_pos = tmp_beg;
                after_insert = tmp_beg + second - first;
                while(after_insert != end_after_insert)
                {
                    *after_insert = *save_pos;
                    after_insert++;
                    save_pos++;
                }
                while(first != second)
                {
                    *tmp_beg = *first;
                    first++;
                }
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
        }
        //  Methods
        void push_back(const value_type &val)
        {
        }

        void pop_back()
        {
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