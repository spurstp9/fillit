/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:36:35 by agardina          #+#    #+#             */
/*   Updated: 2019/12/03 14:41:27 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_grid(char **grid, t_tetri tetri, t_point cursor)
{
	int i;

	i = 0;
	grid[cursor.y][cursor.x] = tetri.letter;
	while (i < 3)
	{
		change_cursor(&cursor, (tetri.path)[i]);
		grid[cursor.y][cursor.x] = tetri.letter;
		i++;
	}
}

int		new_grid(char ***grid, int size)
{
	int		i;
	char	**new;

	i = 0;
	if (!(new = (char**)malloc(sizeof(char*) * size)))
		return (0);
	while (i < size)
	{
		if (!(new[i] = (char*)malloc(sizeof(char) * (size + 1))))
			return (0);
		i++;
	}
	init_grid(new, size);
	if (*grid)
		free_grid(grid, size - 1);
	*grid = new;
	return (1);
}

void	free_grid(char ***grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free((*grid)[i]);
		i++;
	}
	free(*grid);
}

void	init_grid(char **grid, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		j = 0;
		i++;
	}
}

void	erase_letter(char **grid, int size, char letter)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (grid[i][j] == letter)
				grid[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}
