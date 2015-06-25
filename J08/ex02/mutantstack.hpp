#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <list>

template<typename T>
class MutantStack: public std::stack<T>, public virtual std::list<T>
{
    public:
        MutantStack(void):std::stack<T>(){};
        MutantStack(MutantStack const & src):std::stack<T>(src){};
        ~MutantStack(void){};
        T& top(void)
        {
            return (std::stack<T>::top());
        }

        void push(const T& value)
        {
            std::stack<T>::push(value);
            std::list<T>::push_front(value);
            return;
        }

        void pop()
        {
            std::stack<T>::pop();
            std::list<T>::pop_front();
            return;
        }
        int size()
        {
            return (std::stack<T>::size());
        }

        MutantStack& operator=(MutantStack const & rhs)
        {
            std::list<T>::operator=(rhs);
            std::stack<T>::operator=(rhs);
            return (*this);
        };
};
#endif