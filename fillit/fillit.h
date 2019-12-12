/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 18:05:57 by agardina          #+#    #+#             */
/*   Updated: 2019/09/04 14:52:08 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct		s_point
{
	unsigned int	x;
	unsigned int	y;
}					t_point;

typedef struct		s_tetri
{
	char			str[4][5];
	t_point			first;
	char			path[4];
	char			letter;
	struct s_tetri	*next;
}					t_tetri;

int					check_bloc_side(t_tetri tetri, t_point p);
int					count_double_sides(t_tetri tetri, t_point p, int *count);
int					check_tetri(t_tetri *tetri);
int					add_tetri(t_tetri **head);
int					check_line(char *line, int line_index);
int					check_file(const int fd, t_tetri **list);
t_point				get_first_block(t_tetri tetri);
char				get_move(t_tetri tetri, t_point *p, char lst_mv);
char				get_move2(t_tetri tetri, t_point *p, char lst_mv);
int					get_path(t_tetri *tetri, t_point p, int index, char lst_mv);
int					is_square(t_tetri tetri);
int					check_next_space(char **grid, unsigned int size, char mv,
		t_point cursor);
int					check_grid(char **grid, unsigned int size, t_tetri tetri,
		t_point cursor);
void				change_cursor(t_point *cursor, char mv);
void				fill_grid(char **grid, t_tetri tetri, t_point cursor);
int					new_grid(char ***grid, unsigned int *size);
t_tetri				*get_last_tetri(t_tetri *head);
t_point				move_fw(unsigned int size, t_point cursor);
t_point				reset_cursor(t_point cursor);
void				erase_letter(char **grid, unsigned int size, char letter);
void				init_grid(char **grid, unsigned int size);
int					solve(char ***grid, unsigned int *size, t_point cursor,
		t_tetri *tetri);
int					get_tetri_list(int fd, t_tetri **head);
void				print_grid(char **grid, unsigned int size);
void				free_grid(char **grid, unsigned int size);
void				free_tetri_list(t_tetri *head);
int					launch_solve(int fd);
int					free_line(char **line, int nb);

#endif
