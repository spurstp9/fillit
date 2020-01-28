/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:23:00 by agardina          #+#    #+#             */
/*   Updated: 2019/12/03 14:48:16 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_line(char *buffer, char line[6], int start)
{
	int i;

	i = 0;
	while (i < 6)
	{
		line[i] = '\0';
		i++;
	}
	i = 0;
	while (buffer[start + i] && i < 5)
	{
		line[i] = buffer[start + i];
		if (buffer[start + i] == '\n')
			return (1);
		i++;
	}
	return (1);
}

int	check_line(char line[6], int line_nb)
{
	int i;

	if (line_nb % 5 == 0)
	{
		if (!(ft_strlen(line) == 1 && (line[0] == '\n'
						|| line[0] == '\0')))
			return (0);
	}
	else
	{
		i = 0;
		if (ft_strlen(line) != 5)
			return (0);
		while (i < 5)
		{
			if (i < 4)
				if (!(line[i] == '.' || line[i] == '#'))
					return (0);
			if (i == 4 && line[i] != '\n')
				return (0);
			i++;
		}
	}
	return (1);
}

int	count_adj_blocs(t_tetri tetri, t_point p)
{
	int res;

	res = 0;
	if (p.y > 0)
		if ((tetri.tab)[p.y - 1][p.x] == '#')
			res++;
	if (p.y < 3)
		if ((tetri.tab)[p.y + 1][p.x] == '#')
			res++;
	if (p.x > 0)
		if ((tetri.tab)[p.y][p.x - 1] == '#')
			res++;
	if (p.x < 3)
		if ((tetri.tab)[p.y][p.x + 1] == '#')
			res++;
	return (res);
}

int	check_tetri(t_tetri *tetri)
{
	int		blocs_nb;
	int		adj_blocs;
	t_point p;
	int		res;

	blocs_nb = 0;
	adj_blocs = 0;
	p.x = -1;
	p.y = -1;
	while (++p.y < 4)
	{
		while (++p.x < 5)
		{
			if ((tetri->tab)[p.y][p.x] == '#')
			{
				blocs_nb++;
				if (!(res = count_adj_blocs(*tetri, p)))
					return (0);
				adj_blocs += res;
			}
		}
		p.x = -1;
	}
	return ((blocs_nb == 4 && adj_blocs >= 6) ? 1 : 0);
}

int	check_list(t_tetri *head)
{
	t_tetri *to_check;

	to_check = head;
	while (to_check)
	{
		if (!check_tetri(to_check))
			return (0);
		get_first_block(to_check);
		(to_check->path)[3] = '\0';
		get_path(to_check, to_check->first, 0, 0);
		to_check = to_check->next;
	}
	return (1);
}
