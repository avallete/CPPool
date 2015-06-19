#ifndef I_OBJECT_HPP
#define I_OBJECT_HPP
#include <string>

class IObject
{
	public:
		virtual int 			getposX(void)	const = 0;
		virtual int 			getposY(void)	const = 0;
		virtual int 			getdirX(void)	const = 0;
		virtual int 			getdirY(void)	const = 0;
		virtual int 			getSpeed(void)	const = 0;
		virtual int				getsizeX(void)	const = 0;
		virtual int				getsizeY(void)	const = 0;
		virtual int				getHP(void)		const = 0;
		virtual std::string&	getForm(void) 	const = 0;
		virtual void			move(void) = 0;
};
#endif