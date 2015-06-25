#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <list>

class MutantStack
{
    public:
        MutantStack(void);
        MutantStack(MutantStack const & src);
        ~MutantStack(void);

        MutantStack& operator=(MutantStack const & rhs);
    private:
        std::list m_list;
};
#endif