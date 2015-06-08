/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 17:55:58 by avallete          #+#    #+#             */
/*   Updated: 2015/06/08 18:27:54 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP
#include <string>

class Contact
{
    public:
        Contact();
        ~Contact();
        void get_infos(void) const;
    private:
            std::string _infos[11];
};
#endif