/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:48:41 by agardina          #+#    #+#             */
/*   Updated: 2019/08/02 13:18:28 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_tetri_list(int fd, t_tetri **head)
{
	t_tetri *list;

	if (check_file(fd, head))
	{
		list = *head;
		while (list)
		{
			list->first = get_first_block(*list);
			get_path(list, list->first, 0, 0);
			list = list->next;
		}
		return (1);
	}
	else
		write(1, "error\n", 6);
	return (0);
}

int		add_tetri(t_tetri **head)
{
	t_tetri *new;
	t_tetri *tmp;
	int		i;

	if (!head || !(new = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		(*head)->letter = 'A';
	}
	else
	{
		tmp = get_last_tetri(*head);
		tmp->next = new;
		new->letter = tmp->letter + 1;
	}
	i = -1;
	while (++i < 4)
		ft_bzero((new->str)[i], 5);
	return (1);
}

t_tetri	*get_last_tetri(t_tetri *head)
{
	t_tetri *last;

	last = head;
	while (last->next)
		last = last->next;
	return (last);
}

void	free_tetri_list(t_tetri *head)
{
	t_tetri *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
