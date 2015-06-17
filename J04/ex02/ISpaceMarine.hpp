#ifndef I_SPACE_MARINE_HPP
#define I_SPACE_MARINE_HPP

class ISpaceMarine
{
	public:
		virtual ~ISpaceMarine(void){};
		virtual ISpaceMarine* clone(void) const = 0;
		virtual void battleCry() const = 0;
		virtual void rangedAttack() const = 0;
		virtual void meleeAttack() const = 0;
};
#endif