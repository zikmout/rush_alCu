/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:25:35 by abary             #+#    #+#             */
/*   Updated: 2015/12/21 16:45:36 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

char	*ft_strlower(char *str)
{
	char *d;

	if (str == NULL)
		return (NULL);
	d = str;
	while (*str)
	{
		*str = ft_tolower(*str);
		++str;
	}
	return (d);
}
