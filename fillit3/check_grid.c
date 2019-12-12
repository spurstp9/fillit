/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:33:28 by agardina          #+#    #+#             */
/*   Updated: 2019/12/03 10:27:22 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_next_space(char **grid, int size, char mv, t_point cursor)
{
	if (mv == MV_N && cursor.y > 0 && grid[cursor.y - 1][cursor.x] == '.')
		return (1);
	if (mv == MV_S && cursor.y < size - 1
		&& grid[cursor.y + 1][cursor.x] == '.')
		return (1);
	if (mv == MV_W && cursor.x > 0 && grid[cursor.y][cursor.x - 1] == '.')
		return (1);
	if (mv == MV_E && cursor.x < size - 1
		&& grid[cursor.y][cursor.x + 1] == '.')
		return (1);
	if (mv == MV_NW && cursor.y > 0 && cursor.x > 0
		&& grid[cursor.y - 1][cursor.x - 1] == '.')
		return (1);
	if (mv == MV_NE && cursor.y > 0 && cursor.x < size - 1
		&& grid[cursor.y - 1][cursor.x + 1] == '.')
		return (1);
	if (mv == MV_SW && cursor.y < size - 1 && cursor.x > 0
		&& grid[cursor.y + 1][cursor.x - 1] == '.')
		return (1);
	if (mv == MV_SE && cursor.y < size - 1 && cursor.x < size - 1
		&& grid[cursor.y + 1][cursor.x + 1] == '.')
		return (1);
	return (0);
}

int	check_grid(char **grid, int size, t_tetri tetri, t_point cursor)
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
