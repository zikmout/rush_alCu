/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:53:35 by abary             #+#    #+#             */
/*   Updated: 2015/12/20 21:56:48 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	nb;

	if (!s1 || !s2)
		return (NULL);
	nb = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * nb + 1);
	if (!str)
		return (NULL);
	nb = 0;
	while (*s1)
	{
		*(str + nb) = *s1;
		s1++;
		nb++;
	}
	while (*s2)
	{
		*(str + nb) = *s2;
		s2++;
		nb++;
	}
	*(str + nb) = '\0';
	return (str);
}
