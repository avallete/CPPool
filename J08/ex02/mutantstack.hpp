#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iterator>

template<typename T>
class MutantStack: public std::stack<T>
{
    public:
        typedef typename std::deque<T>::reverse_iterator iterator;
        MutantStack(void):std::stack<T>(){};
        MutantStack(MutantStack const & src):std::stack<T>(src){};
        ~MutantStack(void){};
        iterator begin(void)
        {
            return (this->c.rbegin());
        };
        iterator end(void)
        {
            return (this->c.rend());
        };
        MutantStack& operator=(MutantStack const & rhs)
        {
            std::stack<T>::operator=(rhs);
            return (*this);
        };
};
#endif