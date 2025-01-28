/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:36:38 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/28 17:23:14 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solitary.h"


char	*create_path(int type, int nb)
{
	char	*path;

	path = "./textures/card-";
	if (type == 0)
		path = ft_strjoin(path, "hearts-");
	else if (type == 1)
		path = ft_strjoin(path, "clubs-");
	else if (type == 2)
		path = ft_strjoin(path, "diamonds-");
	else if (type == 3)
		path = ft_strjoin(path, "spades-");
	path = ft_strjoin(path, ft_itoa(nb));
	path = ft_strjoin(path, ".xpm");
	return (path);
}


void	init_cards(t_var **var, int type, int card, char *path)
{
	(*var)->draft[type][card].front.img = malloc(sizeof(void *));
	(*var)->draft[type][card].front.img = mlx_xpm_file_to_image((*var)->mlx,
			path, &(*var)->draft[type][card].front.length,
			&(*var)->draft[type][card].front.height);
	(*var)->draft[type][card].back.img = mlx_xpm_file_to_image((*var)->mlx,
			"./textures/card-back2.xpm",
			&(*var)->draft[type][card].front.length,
			&(*var)->draft[type][card].front.height);
	(*var)->draft[type][card].id = card;
	(*var)->draft[type][card].family = type;
	(*var)->draft[type][card].is_face_up = true;
	if (type % 2 == 0)
		(*var)->draft[type][card].is_red = true;
	else
		(*var)->draft[type][card].is_red = false;
}


void	init_img(t_var **var)
{
	char	*path;
	int		x;
	int		y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 13)
		{
			path = create_path(x, y + 1);
			init_cards(var, x, y, path);
			free(path);
		}
	}
	init_placement(var);
}

void	init_placement(t_var **var)
{
	(*var)->placement[0].img = malloc(sizeof(void *));
	(*var)->placement[1].img = malloc(sizeof(void *));
	(*var)->placement[2].img = malloc(sizeof(void *));
	(*var)->placement[3].img = malloc(sizeof(void *));
	(*var)->placement[0].img = mlx_xpm_file_to_image((*var)->mlx,
			"./textures/card-hearts.xpm",
			&(*var)->placement[0].length,
			&(*var)->placement[0].height);
	(*var)->placement[1].img = mlx_xpm_file_to_image((*var)->mlx,
			"./textures/card-diamonds.xpm",
			&(*var)->placement[1].length,
			&(*var)->placement[1].height);
	(*var)->placement[2].img = mlx_xpm_file_to_image((*var)->mlx,
			"./textures/card-clubs.xpm",
			&(*var)->placement[2].length,
			&(*var)->placement[2].height);
	(*var)->placement[3].img = mlx_xpm_file_to_image((*var)->mlx,
			"./textures/card-spades.xpm",
			&(*var)->placement[3].length,
			&(*var)->placement[3].height);
}

void	add_floor(t_var *var)
{
	int		x;
	int		y;

	y = 0;
	var->background.img = mlx_xpm_file_to_image(var->mlx,
			"./textures/background.xpm",
			&var->background.length, &var->background.height);
	while (y < var->screen_height)
	{
		x = 0;
		while (x < var->screen_length)
		{
			mlx_put_image_to_window(var->mlx, var->win,
				var->background.img, x, y);
			x += 100;
		}
		y += 100;
	}
}

