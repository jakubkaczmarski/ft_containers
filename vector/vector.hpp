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
            if(end_ + 1 != capacity_)
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
                iterator temp_beg;
                temp_beg = alloc.allocate((end_ + capacity_ + 1) * 2)
                {
                    
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