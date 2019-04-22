/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:02:23 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/02/15 18:32:19 by dhelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_points	tetro[26];
	char		*res;
	int			fd;
	int			g;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(g = ft_readmap(fd, tetro)))
		{
			ft_putstr("error\n");
			return (0);
		}
		if (!(ft_field(&res, tetro, g)))
			return (0);
		while ((ft_putfigure(&res, tetro, g) == 0))
			if (!(ft_bigger_field(&res, tetro, g)))
				break ;
		ft_putstr(res);
		ft_strdel(&res);
	}
	else
		ft_putstr("usage: fillit target_file\n");
	return (0);
}
