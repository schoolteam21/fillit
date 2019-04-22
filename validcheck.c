/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:02:37 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/02/15 18:33:16 by dhelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_not_valid(char *fig)
{
	int i;
	int hash;

	i = 0;
	hash = 0;
	while (i < 20)
	{
		if (fig[i] != '#' && fig[i] != '.' && i % 5 <= 3)
			return (1);
		if ((i % 5 == 4) && fig[i] != '\n')
			return (1);
		if (fig[i] == '#' && ++hash > 4)
			return (1);
		i++;
	}
	if ((fig[i] != '\n' && fig[i] != '\0') || i != 20 || hash != 4)
		return (1);
	return (0);
}

int	ft_no_contact(char *fig)
{
	int i;
	int connect;

	i = 0;
	connect = 0;
	while (i < 20)
	{
		if (fig[i] == '#' && fig[i + 5] == '#')
			connect++;
		if (fig[i] == '#' && fig[i - 5] == '#')
			connect++;
		if (fig[i] == '#' && fig[i + 1] == '#')
			connect++;
		if (fig[i] == '#' && fig[i - 1] == '#')
			connect++;
		i++;
	}
	if (connect != 6 && connect != 8)
		return (1);
	return (0);
}
