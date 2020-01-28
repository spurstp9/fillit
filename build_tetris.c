/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:27:53 by agardina          #+#    #+#             */
/*   Updated: 2019/12/03 10:39:58 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	manage_tetri(t_tetri **head, char line[6], int line_nb)
{
	int res;

	res = line_nb % 5;
	if (res > 0)
		return (build_tetri(head, line, res));
	return (1);
}

int	build_tetri(t_tetri **head, char line[6], int res)
{
	int i;

	if (res == 1)
		if (!create_new_tetri(head))
			return (0);
	i = 0;
	while (i < 4)
	{
		(*head)->tab[res - 1][i] = line[i];
		i++;
	}
	return (1);
}

int	create_new_tetri(t_tetri **head)
{
	int		i;
	int		j;
	t_tetri *new;

	if (!(new = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	new->letter = *head ? (*head)->letter + 1 : 'A';
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 5)
		{
			new->tab[i][j] = '\0';
			j++;
		}
		i++;
		j = 0;
	}
	new->prev = NULL;
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;
	return (1);
}
