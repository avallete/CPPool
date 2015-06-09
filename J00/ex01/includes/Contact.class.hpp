#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP
#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
    public:
        				Contact();
        				~Contact();
        void			take_infos(void);
        void 			get_infos(void) const;
        void 			get_search(void) const;
        bool			valid_contact(void) const;
    private:
            std::string	_infos[11];
};
#endif