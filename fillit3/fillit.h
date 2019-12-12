/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:44:42 by agardina          #+#    #+#             */
/*   Updated: 2019/12/03 11:10:11 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# define MV_N 1
# define MV_S 2
# define MV_W 3
# define MV_E 4
# define MV_NW 5
# define MV_NE 6
# define MV_SW 7
# define MV_SE 8

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_tetri
{
	char			letter;
	t_point			first;
	char			tab[4][5];
	char			path[4];
	struct s_tetri	*prev;
	struct s_tetri	*next;
}					t_tetri;

int					build_tetri(t_tetri **head, char line[6], int res);
void				change_cursor(t_point *cursor, char mv);
int					check_file(int fd, t_tetri **head);
int					check_grid(char **grid, int size, t_tetri tetri,
		t_point cursor);
int					check_line(char line[6], int line_nb);
int					check_list(t_tetri *head);
int					check_next_move(t_tetri *tetri, t_point *p, char mv);
int					check_next_space(char **grid, int size, char mv,
		t_point cursor);
int					check_tetri(t_tetri *tetri);
int					count_adj_blocs(t_tetri tetri, t_point p);
int					create_new_tetri(t_tetri **head);
void				erase_letter(char **grid, int size, char letter);
void				fill_grid(char **grid, t_tetri tetri, t_point cursor);
void				free_grid(char ***grid, int size);
void				free_tetri_list(t_tetri *head);
int					get_first_block(t_tetri *tetri);
int					get_line(char *buffer, char line[6], int start);
int					get_path(t_tetri *tetri, t_point p, int index, char lst_mv);
void				get_tail(t_tetri **tail, t_tetri *head);
void				init_grid(char **grid, int size);
int					is_square(t_tetri tetri);
int					manage_tetri(t_tetri **head, char line[6], int line_nb);
t_point				move_fw(int size, t_point cursor);
int					new_grid(char ***grid, int size);
void				print_grid(char **grid, int size);
t_point				reset_cursor(t_point cursor);
int					solve(t_tetri *head);
int					solve_recurs(char **grid, int size, t_point cursor,
		t_tetri *tetri);

#endif
