/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 17:14:04 by avallete          #+#    #+#             */
/*   Updated: 2015/06/08 17:38:06 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char *ft_touper(char *s)
{
    if (s)
    {
        for (int i = 0; s[i] != 0; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
        }
    }
    return (s);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        argv++;
        while (*argv)
        {
            std::cout << ft_touper(*argv);
            argv++;
        }
    }
    std::cout << std::endl;
    return (0);
}