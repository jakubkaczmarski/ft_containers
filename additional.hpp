template<bool B, typename T = void>
struct enable_if{};

template <typename T>
struct enable_if<true, T>
{
    typedef T type;
};

template<typename T1, typename T2>
class pair
{
    public:
        pair() : first(), second(){};
        pair(const T1& val1, const T2& val2)
        {
            first = val1;
            second = val2;
        }
        template<typename U, typename V>
        pair(const pair<U, V> &pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }
    T1 first;
    T2 second;
};
template<typename T1, typename T2>
bool operator == (const pair<T1, T2> &f1, const pair<T1, T2> &f2)
{
    return (f1.first == f2.first && f1.first == f1.second);
}
template<typename T1, typename T2>
bool operator != (const pair<T1, T2> &f1, const pair<T1, T2> &f2)
{
    return (f1 != f2);
}
template<typename T1, typename T2>
bool operator < (const pair<T1, T2> &f1, const pair<T1, T2> &f2)
{
    return (f1.first < f2.first || !(f1.first < f2.first) && f1.second < f2.second);
}
template<typename T1, typename T2>
bool operator <= (const pair<T1, T2> &f1, const pair<T1, T2> &f2)
{
    return (!(f1 < f2));
}

template<typename T1, typename T2>
bool operator > (const pair<T1, T2> &f1, const pair<T1, T2> &f2)
{
    return ((f1 < f2));
}
template<typename T1, typename T2>
bool operator >= (const pair<T1, T2> &f1, const pair<T1, T2> &f2)
{
    return (!(f1 < f2));
}

template< class T1, class T2 >
pair<T1, T2> make_pair( T1 t, T2 u )
{
    return (pair<T1, T2>(t, u));
}
