/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:35:33 by agardina          #+#    #+#             */
/*   Updated: 2019/11/28 15:54:28 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	change_cursor(t_point *cursor, char mv)
{
	if (mv == 'n')
		cursor->y--;
	if (mv == 's')
		cursor->y++;
	if (mv == 'w')
		cursor->x--;
	if (mv == 'e')
		cursor->x++;
	if (mv == 'a')
	{
		cursor->y--;
		cursor->x--;
	}
	if (mv == 'b')
	{
		cursor->y--;
		cursor->x++;
	}
	if (mv == 'd')
	{
		cursor->y++;
		cursor->x++;
	}
}

t_point	move_fw(unsigned int size, t_point cursor)
{
	if (cursor.x + 1 > size - 1)
	{
		cursor.x = 0;
		(cursor.y)++;
	}
	else
		(cursor.x)++;
	return (cursor);
}

t_point	reset_cursor(t_point cursor)
{
	cursor.x = 0;
	cursor.y = 0;
	return (cursor);
}
