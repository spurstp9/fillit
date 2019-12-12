/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:51:42 by agardina          #+#    #+#             */
/*   Updated: 2019/09/04 14:57:16 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		write(1, "usage: ./fillit file\n", 21);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	else
	{
		launch_solve(fd);
		close(fd);
	}
	return (0);
}

int		launch_solve(int fd)
{
	t_tetri			*head;
	char			**grid;
	t_point			cursor;
	unsigned int	size;

	head = NULL;
	grid = NULL;
	cursor.x = 0;
	cursor.y = 0;
	if (!get_tetri_list(fd, &head))
	{
		free_tetri_list(head);
		return (0);
	}
	size = ft_sqrt((int)(get_last_tetri(head)->letter - 'A' + 1) * 4) - 1;
	new_grid(&grid, &size);
	solve(&grid, &size, cursor, head);
	print_grid(grid, size);
	free_tetri_list(head);
	free_grid(grid, size);
	return (0);
}

int		solve(char ***grid, unsigned int *size, t_point cursor, t_tetri *tetri)
{
	if (cursor.x > *size - 1 || cursor.y > *size - 1)
		return (0);
	if (tetri == NULL)
		return (1);
	if (check_grid(*grid, *size, *tetri, cursor))
	{
		fill_grid(*grid, *tetri, cursor);
		if (!solve(grid, size, reset_cursor(cursor), tetri->next))
		{
			erase_letter(*grid, *size, tetri->letter);
			return (solve(grid, size, move_fw(*size, cursor), tetri));
		}
	}
	else
	{
		if (tetri->letter == 'A' && cursor.x == *size - 1
			&& cursor.y == *size - 1)
		{
			new_grid(grid, size);
			return (solve(grid, size, reset_cursor(cursor), tetri));
		}
		return (solve(grid, size, move_fw(*size, cursor), tetri));
	}
	return (1);
}

void	print_grid(char **grid, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}
