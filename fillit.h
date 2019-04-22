/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:07:45 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/02/15 18:29:07 by dhelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_points
{
	int		p[4];
	int		x;
	int		y;
	int		field;
	char	letter;
	int		s;
	char	last_symb;
}				t_points;

t_points		ft_min_point(char *fig);
t_points		ft_points(char *fig, t_points points);
int				ft_min_square(int tetnum);
t_points		ft_change_points(int n, int now, t_points points);
int				ft_not_valid(char *fig);
int				ft_no_contact(char *fig);
void			ft_lstadd_end(t_list **alst, t_list *new);
int				ft_readmap(int fd, t_points *tetro);
int				ft_putfigure(char **res, t_points *tetro, int count);
int				ft_field(char **res, t_points *tetro, int count);
int				ft_back(char **res, t_points *tetro, int j);
int				ft_bigger_field(char **res, t_points *tetro, int count);

#endif
