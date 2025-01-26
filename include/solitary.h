/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solitary.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:11:12 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/26 15:11:12 by cgoldens         ###   ########.fr       */
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



typedef struct card
{
	void			*img;
	void			*back;
	int				id;
	bool			is_face_up;
}				t_card;

typedef struct s_var {
	void	*mlx;
	void	*win;
	int		screen_height;
	int		screen_length;
	int		card_height;
	int		card_length;
	t_card	*heart[13];
	t_card	*club[13];
	t_card	*diams[13];
	t_card	*spade[13];
}				t_var;

#endif