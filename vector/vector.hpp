#include "random_access_it.hpp"
#include <memory>

namespace ft
{
    // template<typename T, typename allocator = std::allocator<T> >
    // class vector_iterator
    // {
    //     public:
    //         typedef vector_iterator self_type;
    //         typedef T                       value_type;
    //         typedef T&                     reference;
    //         typedef T*                      pointer;
    //         typedef std::random_access_iterator_tag iterator_category;
    //         typedef ptrdiff_t            difference_type;

    //         explicit vector_iterator(pointer ptr, size_t const index) : ptr(ptr), index(index)
    //         {

    //         }
    //         vector_iterator(vector_iterator const & o) = default;
    //         vector_iterator& operator= (vector_iterator const & o) = default;
    //         ~vector_iterator() = default;
    //         // self_type &operator++ ()
    //         // {
    //         //     if(index >= size)
    //         //     {
    //         //         throw std::out_of_range("It's out of range cannot increment");
    //         //     }
    //         //     ++index;
    //         //     return *this;
    //         // }
    //         // self_type operator++ (int)
    //         // {
    //         //     self_type tmp = *this;
    //         //     ++*this;
    //         //     return tmp;
    //         // }
    //     private:
    //         pointer ptr = nullptr;
    //         size_t index = 0;
    //     bool compatible(self_type const & other )const
    //     {
    //         return ptr == other.ptr;
    //     }

    // };
    template <typename T, typename allocator = std::allocator<T> >
    class vector
    {

    public:
        // typedef value_type T;
        typedef allocator allocator_type;
        // typedef reference allocator_type::reference;
        // typedef const_reference allocator_type::const_reference;
        // typedef pointer allocator_type::pointer;
        // typedef const_pointer allocator_type::const_pointer;
        // Iterator Time
        // typedef iterator std::iterator<T>;
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
            begin_ = alloc.allocate(n);
            end_ = begin_;
            for (size_type i = 0; i < n; i++)
            {
                alloc.construct(end_, val);
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