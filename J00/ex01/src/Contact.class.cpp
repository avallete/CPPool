/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 17:55:29 by avallete          #+#    #+#             */
/*   Updated: 2015/06/08 18:59:24 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void)
{
    std::cout << "Contact has been created" << std::endl;
    std::cout << "Please Enter Contact First Name : ";
    std::cin >> this->_infos[0];
    return;
}

Contact::~Contact(void)
{
    std::cout << "Contact has been destroyed" << std::endl;
    return;
}

void Contact::get_infos(void) const
{
    std::cout << "Contact First Name == " << this->_infos[0] << std::endl;
    return;
}