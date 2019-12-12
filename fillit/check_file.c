/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:11:09 by agardina          #+#    #+#             */
/*   Updated: 2019/06/14 11:35:27 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_double_sides(t_tetri tetri, t_point p, int *count)
{
	int nb;

	nb = check_bloc_side(tetri, p);
	if (nb >= 2)
		(*count)++;
	if (nb > 2)
		(*count)++;
	return ((nb > 0) ? 1 : 0);
}

int	check_bloc_side(t_tetri tetri, t_point p)
{
	int nb;

	nb = 0;
	if (p.y > 0)
		if ((tetri.str)[p.y - 1][p.x] == '#')
			nb++;
	if (p.y < 3)
		if ((tetri.str)[p.y + 1][p.x] == '#')
			nb++;
	if (p.x > 0)
		if ((tetri.str)[p.y][p.x - 1] == '#')
			nb++;
	if (p.x < 3)
		if ((tetri.str)[p.y][p.x + 1] == '#')
			nb++;
	return (nb);
}

int	check_tetri(t_tetri *tetri)
{
	int		blocs_nb;
	int		count;
	t_point p;

	blocs_nb = 0;
	p.x = -1;
	p.y = -1;
	count = 0;
	while (++p.y < 4)
	{
		while (++p.x < 5)
		{
			if ((tetri->str)[p.y][p.x] == '#')
			{
				if (!count_double_sides(*tetri, p, &count))
					return (0);
				else
					blocs_nb++;
			}
		}
		p.x = -1;
	}
	return ((blocs_nb == 4 && count >= 2) ? 1 : 0);
}

int	check_line(char *line, int line_index)
{
	int i;
	int len;

	len = ft_strlen(line);
	if (line_index % 5 == 0)
	{
		if (len > 0)
			return (0);
	}
	else
	{
		if (len != 4)
			return (0);
		i = 0;
		while (i < 4)
		{
			if (line[i] != '.' && line[i] != '#')
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_file(const int fd, t_tetri **list)
{
	char	*line;
	int		line_index;
	t_tetri *head;

	line_index = 0;
	head = NULL;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		line_index++;
		if (!check_line(line, line_index))
			return (free_line(&line, 0));
		if (line_index % 5 == 1)
			if (!add_tetri(&head))
				return (free_line(&line, 0));
		if (line_index % 5 > 0)
			ft_strcpy((get_last_tetri(head)->str)[(line_index % 5) - 1], line);
		if (line_index % 5 == 4)
			if (!check_tetri(get_last_tetri(head)))
				return (free_line(&line, 0));
		ft_strdel(&line);
	}
	*list = head;
	return (free_line(&line, (line_index % 5 != 4) ? 0 : 1));
}
