/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:43:02 by agardina          #+#    #+#             */
/*   Updated: 2019/12/03 10:31:23 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_first_block(t_tetri *tetri)
{
	t_point p;

	p.x = 0;
	p.y = 0;
	while (p.y < 4)
	{
		while (p.x < 5)
		{
			if (tetri->tab[p.y][p.x] == '#'
					&& (count_adj_blocs(*tetri, p) == 1
						|| is_square(*tetri)))
			{
				(tetri->first).x = p.x;
				(tetri->first).y = p.y;
				return (1);
			}
			(p.x)++;
		}
		p.x = 0;
		(p.y)++;
	}
	return (0);
}

int	is_square(t_tetri tetri)
{
	t_point p;

	p.x = 0;
	p.y = 0;
	while (p.y < 4)
	{
		while (p.x < 5)
		{
			if (tetri.tab[p.y][p.x] != '#')
				(p.x)++;
			else
			{
				if (tetri.tab[p.y][p.x + 1] == '#'
						&& tetri.tab[p.y + 1][p.x] == '#'
						&& tetri.tab[p.y + 1][p.x + 1] == '#')
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

int	get_path(t_tetri *tetri, t_point p, int index, char last_mv)
{
	int i;

	if (index == 3)
		return (1);
	change_cursor(&p, last_mv);
	i = 1;
	while (i < 8)
	{
		if (!(check_next_move(tetri, &p, i)))
			i++;
		else
		{
			tetri->tab[p.y][p.x] = '0';
			tetri->path[index] = i;
			if (!get_path(tetri, p, index + 1, i))
			{
				tetri->tab[p.y][p.x] = '#';
				i++;
			}
			else
				return (1);
		}
	}
	return (0);
}

int	check_next_move(t_tetri *tetri, t_point *p, char mv)
{
	if (mv == MV_N && p->y > 0 && tetri->tab[p->y - 1][p->x] == '#')
		return (1);
	else if (mv == MV_S && p->y < 3 && tetri->tab[p->y + 1][p->x] == '#')
		return (1);
	else if (mv == MV_W && p->x > 0 && tetri->tab[p->y][p->x - 1] == '#')
		return (1);
	else if (mv == MV_E && p->x < 3 && tetri->tab[p->y][p->x + 1] == '#')
		return (1);
	else if (mv == MV_NW && p->y > 0 && p->x > 0
			&& tetri->tab[p->y - 1][p->x - 1] == '#')
		return (1);
	else if (mv == MV_NE && p->y > 0 && p->x < 3
			&& tetri->tab[p->y - 1][p->x + 1] == '#')
		return (1);
	else if (mv == MV_SW && p->y < 3 && p->x > 0
			&& tetri->tab[p->y + 1][p->x - 1] == '#')
		return (1);
	else if (mv == MV_SE && p->y < 3 && p->x < 3
			&& tetri->tab[p->y + 1][p->x + 1] == '#')
		return (1);
	return (0);
}
