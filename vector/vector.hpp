#include <memory>

namespace ft
{   

    template<typename T, typename allocator = std::allocator<T> >
    class vector
    {
        typedef allocator allocator_type;
        typedef T value_type;
        typedef size_t size_type;
        public:

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

        //Methods
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