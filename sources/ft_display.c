/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 06:50:08 by abary             #+#    #+#             */
/*   Updated: 2015/12/21 16:55:23 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_let_choice(void)
{
	int		result;

	result = 0;
	ft_putstr("/-----------MENU-------------\\\n");
	ft_putstr("|                            |\n");
	while (result != 1 && result != 2)
	{
		ft_putstr("|  Select the first player   |\n");
		ft_putstr("|  Player           : 1      |\n");
		ft_putstr("|  Computer         : 2      |\n");
		ft_putstr("|                            |\n");
		ft_putstr("\\----------------------------/\n");
		ft_putstr("Select (1 or 2) : ");
		result = ft_atoi(ft_read_user());
	}
	if (result == 1)
		ft_putstr("You choose to play first\n");
	else
		ft_putstr("You're in deep shit\n");
	ft_putstr("---------BEGIN GAME----------\n");
	return (result);
}

void	ft_ask_user(int time)
{
	if (time == 0)
		ft_putstr("Enter the right number of matches to pick (1 - 3) : ");
	else if (time == 1)
		ft_putstr("Is it Hard to Select the right Number ? \n");
	else if (time == 2)
		ft_putstr("Are you stupid  ? \n");
	else if (time == 3)
		ft_putstr("Are you brainless ? \n");
	else if (time == 4)
		ft_putstr("the answer is not 42 \n");
	else if (time == 5)
		ft_putstr("I 'm loosing hope \n");
	else if (time == 6)
		ft_putstr("Just kill Yourself \n");
	else if (time == 7)
		ft_putstr("WTF bro, go to sleep!\n");
}
