/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solitary.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:11:12 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/29 13:56:31 by cgoldens         ###   ########.fr       */
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

# define GREEN 0x006400
# define EVENT_MOUSE_PRESS     4
# define EVENT_MOUSE_RELEASE   5
# define EVENT_MOUSE_MOVE      6

typedef struct img
{
	void			*img;
	int				height;
	int				length;
}					t_img;

typedef struct card
{
	t_img			front;
	t_img			back;
	int				id;
	int				family;
	bool			is_face_up;
	bool			is_red;
}				t_card;

typedef struct s_var {
	void	*mlx;
	void	*win;
	int		screen_height;
	int		screen_length;
	t_img	background;
	t_card	draft[4][13];
	t_card	play[7][25];
	t_img	placement[4];
	int		*rnd_draft;
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


#endif