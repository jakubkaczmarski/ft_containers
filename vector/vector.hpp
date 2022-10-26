#include <memory>


//How to live with those containers
namespace ft
{   

    template<typename T, typename allocator = std::allocator<T> >
    class vector
    {
        typedef allocator allocator_type;
        public:
        explicit vector(const allocator_type& alloc = allocator_type())
        : begin(0), end(0), capacity(0), aloc()
        {
        }
        T &operator[](size_t index)   
        {
            if(begin)
            {
                return  *(begin + index);
            }
            return *begin;
        }
        private:
        allocator_type aloc;
        T *begin;
        T *end;
        T *capacity;

    };
}