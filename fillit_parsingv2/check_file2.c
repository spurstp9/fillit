/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:53:33 by agardina          #+#    #+#             */
/*   Updated: 2019/11/28 15:57:44 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks the line of the received file and copies it into a char array that
** will be part of a tetrimino.
*/

int		fill_line(char file[547], int *index, char line[5], int line_index)
{
	int i;

	i = 0;
	if (!file[*index])
		return ((line_index % 5 == 0) ? 0 : -1);
	while (i < 4 && file[*index] && (file[*index] == '#'
				|| file[*index] == '.'))
		line[i++] = file[(*index)++];
	if ((i < 4 && line_index % 5 != 0) || (i != 0 && line_index % 5 == 0))
		return (-1);
	line[i] = '\0';
	if (file[*index] == '\n')
		(*index)++;
	else
		return (-1);
	return (1);
}

/*
** Creates a tetri with the line received, or adds the line to the current
** tetri. When the tetri is complete, it is checked.
*/

int		make_check_tetri(t_tetri **head, char line[5], int line_index)
{
	if (line_index % 5 == 1)
		if (!add_tetri(head))
			return (0);
	if (line_index % 5 > 0)
		ft_strcpy((get_last_tetri(*head)->str)[(line_index % 5) - 1], line);
	if (line_index % 5 == 4)
		if (!check_tetri(get_last_tetri(*head)))
			return (0);
	return (1);
}
