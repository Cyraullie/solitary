/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solitary.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:11:12 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/30 14:46:44 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLITARY_H
# define SOLITARY_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdbool.h>
# include <time.h>

# define WIN_WIDTH 1150
# define WIN_HEIGHT 1000
# define CARD_WIDTH 96
# define CARD_HEIGHT 144
# define GREEN 0x006400
# define EVENT_MOUSE_PRESS     4
# define EVENT_MOUSE_RELEASE   5
# define EVENT_MOUSE_MOVE      6

typedef struct img
{
	void		*img;
	int			height;
	int			length;
	int			is_card_revealed;
}					t_img;

typedef struct card
{
	t_img		front;
	t_img		back;
	int			id;
	int			family;
	bool		is_face_up;
	bool		is_red;
	int			pos_x;
	int			pos_y;
	int			tmp_x;
	int			tmp_y;
}				t_card;

typedef struct s_var {
	void	*mlx;
	void	*win;
	t_img	background;
	t_card	draft[4][13];
	t_card	play[7][25];
	t_card	stack[25];
	t_img	placement[4];
	int		*rnd_draft;
	int		dragging;
	t_card	*dragged_card;
}				t_var;

void	init_img(t_var **var);
void	add_floor(t_var *var);
int		check_tab(int *tab, int nb);
void	init_rng(t_var **var);
void	init(t_var *var);
void	place_card(t_var **var);
void	init_placement(t_var **var);
void	display_play(t_var **var, int line, int col, int x);
void	display_draft(t_var **var, int x);
void	display_placement(t_var **var);
void	put_img_front(t_var *var, t_card card, int pos_x, int pos_y);
void	put_img_back(t_var *var, t_card card, int pos_x, int pos_y);


#endif