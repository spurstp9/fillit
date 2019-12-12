/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:43:02 by agardina          #+#    #+#             */
/*   Updated: 2019/08/02 12:46:35 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point	get_first_block(t_tetri tetri)
{
	t_point p;

	p.x = 0;
	p.y = 0;
	while (p.y < 4)
	{
		while (p.x < 5)
		{
			if (tetri.str[p.y][p.x] == '#' && (check_bloc_side(tetri, p) == 1
						|| is_square(tetri)))
				return (p);
			(p.x)++;
		}
		p.x = 0;
		(p.y)++;
	}
	p.x = -1;
	p.y = -1;
	return (p);
}

int		is_square(t_tetri tetri)
{
	t_point p;

	p.x = 0;
	p.y = 0;
	while (p.y < 4)
	{
		while (p.x < 5)
		{
			if (tetri.str[p.y][p.x] != '#')
				(p.x)++;
			else
			{
				if (tetri.str[p.y][p.x + 1] == '#'
						&& tetri.str[p.y + 1][p.x] == '#'
						&& tetri.str[p.y + 1][p.x + 1] == '#')
					return (1);
				else
					return (0);
			}
		}
		p.x = 0;
		(p.y)++;
	}
	return (0);
}

/*
** Diagonal moves are related to T-shaped tetriminos only.
*/

char	get_diag_move(t_tetri tetri, t_point *p, char lst_mv)
{
	if (lst_mv == 'n')
	{
		p->x++;
		p->y++;
		return ('d');
	}
	else
	{
		p->y--;
		if (tetri.str[p->y][p->x + 1] == '#')
		{
			p->x++;
			return ('b');
		}
		else
		{
			p->x--;
			return ('a');
		}
	}
	return (0);
}

char	get_move(t_tetri tetri, t_point *p, char lst_mv)
{
	if (p->y > 0 && tetri.str[p->y - 1][p->x] == '#'
		&& lst_mv != 's')
	{
		p->y--;
		return ('n');
	}
	else if (p->y < 3 && tetri.str[p->y + 1][p->x] == '#'
		&& lst_mv != 'n')
	{
		p->y++;
		return ('s');
	}
	else if (p->x > 0 && tetri.str[p->y][p->x - 1] == '#'
		&& lst_mv != 'e')
	{
		p->x--;
		return ('w');
	}
	else if (p->x < 3 && tetri.str[p->y][p->x + 1] == '#'
		&& lst_mv != 'w')
	{
		p->x++;
		return ('e');
	}
	return (get_diag_move(tetri, p, lst_mv));
}

int		get_path(t_tetri *tetri, t_point p, int index, char lst_mv)
{
	if (index == 3)
	{
		(tetri->path)[index] = '\0';
		return (0);
	}
	(tetri->path)[index] = get_move(*tetri, &p, lst_mv);
	get_path(tetri, p, index + 1, (tetri->path)[index]);
	return (1);
}
