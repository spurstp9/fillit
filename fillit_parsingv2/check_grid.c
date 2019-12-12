/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:33:28 by agardina          #+#    #+#             */
/*   Updated: 2019/08/02 12:34:58 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_next_space(char **grid, unsigned int size, char mv, t_point cursor)
{
	if (cursor.y > 0 && mv == 'n' && grid[cursor.y - 1][cursor.x] == '.')
		return (1);
	if (cursor.y < size - 1 && mv == 's' && grid[cursor.y + 1][cursor.x] == '.')
		return (1);
	if (cursor.x > 0 && mv == 'w' && grid[cursor.y][cursor.x - 1] == '.')
		return (1);
	if (cursor.x < size && mv == 'e' && grid[cursor.y][cursor.x + 1] == '.')
		return (1);
	if (cursor.y > 0 && cursor.x > 0 && mv == 'a'
		&& grid[cursor.y - 1][cursor.x - 1] == '.')
		return (1);
	if (cursor.y > 0 && cursor.x < size && mv == 'b'
			&& grid[cursor.y - 1][cursor.x + 1] == '.')
		return (1);
	if (cursor.y < size && cursor.x < size && mv == 'd'
		&& grid[cursor.y + 1][cursor.x + 1] == '.')
		return (1);
	return (0);
}

int	check_grid(char **grid, unsigned int size, t_tetri tetri, t_point cursor)
{
	int i;

	if (grid[cursor.y][cursor.x] != '.')
		return (0);
	i = 0;
	while (i < 3)
	{
		if (check_next_space(grid, size, (tetri.path)[i], cursor))
		{
			change_cursor(&cursor, (tetri.path)[i]);
			i++;
		}
		else
			return (0);
	}
	return (1);
}
