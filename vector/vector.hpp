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
            
            //If we resize to less than we had before we have
            //to save elements somewhere temporary and copy them to a new place in 
            //Memory
    
            if(capacity_num > count)
            {
                while(count != capacity_num--)
                {
                    this->alloc.destroy(end_--);
                }
                capacity_ = end_;
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
        size_type size()
        {
            return (end_ - begin_);
        }
    private:
        allocator_type alloc;
        T *begin_;
        T *end_;
        T *capacity_;
    };
}