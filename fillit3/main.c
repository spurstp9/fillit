/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:45:22 by agardina          #+#    #+#             */
/*   Updated: 2019/12/03 14:29:43 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_tetri *head;

	if (argc != 2)
	{
		write(1, "usage: ./fillit file\n", 21);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	head = NULL;
	if (fd == -1 || !check_file(fd, &head))
		write(1, "error\n", 6);
	else
		solve(head);
	close(fd);
	free_tetri_list(head);
	return (0);
}

int		check_file(int fd, t_tetri **head)
{
	int		ret;
	char	buffer[547];
	int		i;
	char	line[6];
	int		line_nb;

	if ((ret = read(fd, buffer, 546)) > 545 || ret % 21 != 20)
		return (0);
	buffer[ret] = '\0';
	i = 0;
	line_nb = 1;
	while (i < ret)
	{
		get_line(buffer, line, i);
		if (check_line(line, line_nb))
			manage_tetri(head, line, line_nb);
		else
			return (0);
		i += line_nb % 5 == 0 ? 1 : 5;
		line_nb++;
	}
	if (!check_list(*head))
		return (0);
	return (1);
}

int		solve(t_tetri *head)
{
	unsigned int	size;
	char			**grid;
	t_point			cursor;
	t_tetri			*tail;

	tail = NULL;
	grid = NULL;
	cursor.x = 0;
	cursor.y = 0;
	get_tail(&tail, head);
	size = ft_sqrt((int)(head->letter - 'A' + 1) * 4);
	new_grid(&grid, size);
	while (!solve_recurs(grid, size, cursor, tail))
		new_grid(&grid, ++size);
	print_grid(grid, size);
	free_grid(&grid, size);
	return (1);
}

int		solve_recurs(char **grid, int size, t_point cursor, t_tetri *tetri)
{
	if (cursor.x > size - 1 || cursor.y > size - 1)
		return (0);
	if (tetri == NULL)
		return (1);
	if (check_grid(grid, size, *tetri, cursor))
	{
		fill_grid(grid, *tetri, cursor);
		if (!solve_recurs(grid, size, reset_cursor(cursor), tetri->prev))
		{
			erase_letter(grid, size, tetri->letter);
			return (solve_recurs(grid, size, move_fw(size, cursor), tetri));
		}
	}
	else
	{
		if (tetri->letter == 'A' && cursor.x == size - 1
				&& cursor.y == size - 1)
			return (0);
		return (solve_recurs(grid, size, move_fw(size, cursor), tetri));
	}
	return (1);
}

void	print_grid(char **grid, int size)
{
	int	i;
	int	j;

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
