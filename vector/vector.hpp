#include <memory>

namespace ft
{   
    template<typename T, typename allocator = std::allocator<T> >
    class vector_iterator
    {
        public:
            typedef vector_iterator self_type;
            typedef T                       value_type;
            typedef T&                     reference;
            typedef T*                      pointer;
            typedef std::random_access_iterator_tag iterator_category;
            typedef ptrdiff_t            difference_type;

            explicit vector_iterator(pointer ptr, size_t const index) : ptr(ptr), index(index)
            {

            }
            vector_iterator(vector_iterator const & o) = default;
            vector_iterator& operator= (vector_iterator const & o) = default;
            ~vector_iterator() = default;
            self_type &operator++ ()
            {
                if(index >= size)
                {
                    throw std::out_of_range("It's out of range cannot increment");
                }
                ++index;
                return *this;
            }
            self_type operator++ (int)
            {
                self_type tmp = *this;
                ++*this;
                return tmp;
            }
        private:
            pointer ptr = nullptr;
            size_t index = 0;
        bool compatible(self_type const & other )const
        {
            return ptr == other.ptr;
        }
    
    };
    template<typename T, typename allocator = std::allocator<T> >
    class vector
    {
        
        public:
        // typedef value_type T;
        typedef allocator allocator_type;
        // typedef reference allocator_type::reference;
        // typedef const_reference allocator_type::const_reference;
        // typedef pointer allocator_type::pointer;
        // typedef const_pointer allocator_type::const_pointer;
        //Iterator Time
        // typedef iterator std::iterator<T>;
        typedef T value_type;
        typedef size_t size_type;
        //Constructors
        //default constructor
        explicit vector(const allocator_type& alloc = allocator_type())
        : begin(0), end(0), capacity(0), aloc()
        {

        }
        //Fill constructor
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type())
        {
            begin = alloc.allocate(n);
            end = begin;
            for(size_type i = 0; i < n; i++)
            {
                alloc.construct(end, val);
                end++;
            }
        }
        //Range constructor
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
        {
            
        }
        //Copy constructor
        vector(const vector &vec)
        {

        }
        //Destructor
        ~vector()
        {

        }
        //  Methods
        void    push_back(const value_type &val)
        {
        
        }

        void    pop_back()
        {

        }

        
        private:
        allocator_type aloc;
        T *begin;
        T *end;
        T *capacity;

    };
}