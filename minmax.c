/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:02:31 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/02/15 18:19:56 by dhelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_points	ft_min_point(char *fig)
{
	t_points	points;
	int			i;

	points.x = 3;
	points.y = 3;
	i = 0;
	while (i < 20)
	{
		if (fig[i] == '#' && (i % 5 < points.x))
			points.x = i % 5;
		if (fig[i] == '#' && (i / 5 < points.y))
			points.y = i / 5;
		i++;
	}
	return (points);
}

t_points	ft_points(char *fig, t_points points)
{
	int			i;
	int			hash;
	int			sdvig;

	hash = 0;
	i = 0;
	sdvig = points.x + points.y * 5;
	while (i < 20)
	{
		if (fig[i] == '#')
		{
			points.p[hash] = i - sdvig;
			hash++;
		}
		i++;
	}
	points.last_symb = fig[20];
	return (points);
}

int			ft_min_square(int tetnum)
{
	int sqrt;
	int nb;

	nb = tetnum * 4;
	sqrt = 1;
	if (nb <= 0)
		return (0);
	while ((sqrt * sqrt) < nb)
		sqrt++;
	return (sqrt + 1);
}

t_points	ft_change_points(int n, int now, t_points points)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (points.p[i] < now)
			points.p[i] += 0;
		else if (points.p[i] < now * 2)
			points.p[i] = points.p[i] - now + n;
		else if (points.p[i] < now * 3)
			points.p[i] = points.p[i] - now * 2 + n * 2;
		else if (points.p[i] < now * 4)
			points.p[i] = points.p[i] - now * 3 + n * 3;
		i++;
	}
	points.field = n;
	return (points);
}
