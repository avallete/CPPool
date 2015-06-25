#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
    public:
        typedef typename std::deque<T>::iterator iterator;
        MutantStack(void):std::stack<T>(){};
        MutantStack(MutantStack const & src):std::stack<T>(src){};
        ~MutantStack(void){};
        iterator begin(void)
        {
            return (this->c.begin());
        };
        iterator end(void)
        {
            return (this->c.end());
        };
        MutantStack& operator=(MutantStack const & rhs)
        {
            std::stack<T>::operator=(rhs);
            return (*this);
        };
};
#endif