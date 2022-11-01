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
            InputIterator test = first;
            size_type n = 0;

            while (test != last)
            {
                test++;
                n++;
            }
            begin_ = this->alloc.allocate(n);
            while (first != last)
        {
                this->alloc.construct(end_, *first);
                first++;
                end_++;
            }

            capacity_ = end_;
            this->begin_ = capacity_ - n;
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

    private:
        allocator_type alloc;
        T *begin_;
        T *end_;
        T *capacity_;
    };
}