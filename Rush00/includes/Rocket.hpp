/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rocket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlevieil <jlevieil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 17:01:46 by jlevieil          #+#    #+#             */
/*   Updated: 2015/06/21 17:15:20 by jlevieil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROCKET_HPP
#define ROCKET_HPP
#include "AObject.hpp"
#include "Player.hpp"
#include "EnnemyHorde.hpp"
#include "Window.hpp"

class Rocket: public AObject
{
	public:
		Rocket(int N, std::string form);
		Rocket(Rocket const & src);
		~Rocket(void);
		Rocket* getRocket(void) const;	
		int	getIndex(void) const;		
		int	getMax(void) const;
		void printit(Window& win) const;
		void move(Window& win);
		void activate(int xpos, int ypos, int input);
		void checkDamages(EnnemyHorde* horde, int N, Window& win);
		void print_chargeur(Window & win);
		Rocket& operator=(Rocket const & rhs);
		int			check_m_dispo(void);

	private:
		Rocket(void);
		Rocket* m_rockets;
		int		 m_max;
		int		 m_index;
};
#endif
