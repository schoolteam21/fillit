/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:35:31 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/02/15 18:33:57 by dhelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_field(char **res, t_points *tetro, int count)
{
	int i;
	int k;

	ft_strdel(res);
	if (tetro[count - 1].last_symb == '\n')
	{
		ft_putstr("error\n");
		return (0);
	}
	k = tetro[0].field;
	if (!(*res = ft_strnew(k * (k - 1))))
		exit(0);
	ft_memset(*res, '.', (k * (k - 1)));
	i = 1;
	while (i < k)
	{
		(*res)[(k * i) - 1] = '\n';
		i++;
	}
	return (1);
}

int		ft_putfigure(char **res, t_points *tetro, int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < count)
	{
		if ((*res)[tetro[j].p[0] + tetro[j].s] == '.'
		&& (*res)[tetro[j].p[1] + tetro[j].s] == '.'
		&& (*res)[tetro[j].p[2] + tetro[j].s] == '.'
		&& (*res)[tetro[j].p[3] + tetro[j].s] == '.')
		{
			i = 0;
			while (i < 4)
				(*res)[tetro[j].p[i++] + tetro[j].s] = tetro[j].letter;
			j++;
			continue ;
		}
		tetro[j].s++;
		if ((tetro[j].p[3] + tetro[j].s) >= (int)(ft_strlen(*res)))
			if (!(ft_back(res, tetro, j--)))
				return (0);
	}
	return (1);
}

int		ft_bigger_field(char **res, t_points *tetro, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		tetro[i] = ft_change_points((tetro[i].field + 1),
		tetro[i].field, tetro[i]);
		tetro[i].s = 0;
		i++;
	}
	ft_field(res, tetro, count);
	if (ft_putfigure(res, tetro, count))
		return (0);
	return (1);
}

int		ft_back(char **res, t_points *tetro, int j)
{
	int len;
	int i;

	if (j == 0)
		return (0);
	len = ft_strlen(*res);
	i = 0;
	while (i < len)
	{
		if ((*res)[i] == tetro[j - 1].letter)
			(*res)[i] = '.';
		i++;
	}
	tetro[j].s = 0;
	tetro[j - 1].s++;
	return (1);
}

int		ft_readmap(int fd, t_points *tetro)
{
	char	buf[21];
	char	letter;
	int		ret;
	int		count;
	int		i;

	i = 0;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if (ft_not_valid(buf) || ft_no_contact(buf) || i >= 26)
			return (0);
		tetro[i++] = ft_points(buf, ft_min_point(buf));
	}
	count = i;
	i = 0;
	letter = 'A';
	while (i < count)
	{
		tetro[i] = ft_change_points(ft_min_square(count), 5, tetro[i]);
		tetro[i].letter = letter++;
		tetro[i].s = 0;
		i++;
	}
	return (count);
}
