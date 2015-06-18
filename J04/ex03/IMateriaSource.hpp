#ifndef I_MATERIA_SOURCE_HPP
#define I_MATERIA_SOURCE_HPP
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(void) {};
		virtual void learnMaterial(AMateria*) = 0;
		virtual void AMateria* createMateria(std::string const & type) = 0;
};
#endif