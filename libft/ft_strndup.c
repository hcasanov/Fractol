/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:27:44 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/13 21:23:15 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strndup(char *s, int n)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n && s[i])
	{
		cpy[i] = (char)s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
