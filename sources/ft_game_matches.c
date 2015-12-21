/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_matches.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 21:28:58 by abary             #+#    #+#             */
/*   Updated: 2015/12/21 16:40:30 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

static int		ft_ask_player(int alcu)
{
	int		result;
	char	*matches;
	int		time;

	time = 0;
	result = 0;
	while ((result <= 0 || result > 3) || result > alcu)
	{
		ft_ask_user(time);
		matches = ft_read_user();
		result = ft_atoi(matches);
		matches = ft_strlower(matches);
		if (!ft_strcmp(matches, "one\n"))
			result = 1;
		else if (!ft_strcmp(matches, "two\n"))
			result = 2;
		else if (!ft_strcmp(matches, "three\n"))
			result = 3;
		++time;
		if (time == 8)
			time = 0;
	}
	free(matches);
	matches = NULL;
	return (result);
}

static int		ft_game(t_list *line, int answer, int nbr)
{
	int		result;

	if (answer == 1)
		result = ft_ask_player(line->content);
	else
	{
		ft_putstr("The Computer picked ");
		result = ft_solve_matches(line, nbr);
		ft_putnbr(result);
		ft_putstr(" matches\n");
	}
	line->content -= result;
	if (line->content == 0)
		--nbr;
	return (nbr);
}

static	void	ft_end_game(int answer)
{
	ft_putstr("GAME OVER\n");
	if (answer == 1)
		ft_putstr("You win\n");
	else
		ft_putstr("The Computer won\n");
}

int				ft_game_match(t_list *first)
{
	int		answer;
	int		nbr;
	t_list	*line;

	nbr = ft_len_list(first);
	line = ft_lstlast(first);
	answer = ft_let_choice();
	ft_print_matches(first);
	while (nbr != 0)
	{
		nbr = ft_game(line, answer, nbr);
		if (answer == 1)
			answer = 2;
		else
			answer = 1;
		if (line->content == 0)
		{
			ft_lstdel_zero(first);
			line = ft_lstlast(first);
		}
		if (nbr != 0)
			ft_print_matches(first);
	}
	ft_end_game(answer);
	return (1);
}
