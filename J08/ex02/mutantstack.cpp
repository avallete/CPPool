#include "mutantstack.hpp"

MutantStack::MutantStack(void)
{
    return;
}

MutantStack::MutantStack(MutantStack const & src)
{
    *this = src;
    return;
}

MutantStack::~MutantStack(void)
{
    return;
}

MutantStack& MutantStack::operator=(MutantStack const & rhs)
{
    return (*this);
}