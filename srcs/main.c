/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:45:09 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/26 15:37:02 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solitary.h"

int	handle_keypress(int keycode, t_var *var)
{
	printf("Key pressed: %d\n", keycode);

	(void)var;
	if (keycode == 65307) // Escape key (code clavier standard pour "echap")
	{
		printf("Escape key pressed. Exiting program...\n");
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	return (0);
}

void	add_floor(t_var *var, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < var->card_height) // Hauteur de la fenêtre
	{
		x = 0;
		while (x < var->card_length) // Largeur de la fenêtre
		{
			mlx_pixel_put(var->mlx, var->win, x, y, color);
			x++;
		}
		y++;
	}
}

void	init_diams(t_var **var)
{
	int		i;
	char	*path;

	i = 0;
	while (++i <= 13)
	{
		(*var)->diams[i - 1] = malloc(sizeof(t_card));
		path = ft_strjoin("./textures/card-diamonds-", ft_itoa(i));
		path = ft_strjoin(path, ".xpm");
		(*var)->diams[i - 1]->img = mlx_xpm_file_to_image((*var)->mlx, path,
				&((*var)->card_length), &((*var)->card_height));
		(*var)->diams[i - 1]->back = mlx_xpm_file_to_image((*var)->mlx,
				"./textures/card-back2.xpm", &((*var)->card_length),
				&((*var)->card_height));
		(*var)->diams[i - 1]->id = i;
		(*var)->diams[i - 1]->is_face_up = true;
	}
}

void	init_heart(t_var **var)
{
	int		i;
	char	*path;

	i = 0;
	while (++i <= 13)
	{
		(*var)->heart[i - 1] = malloc(sizeof(t_card));
		path = ft_strjoin("./textures/card-hearts-", ft_itoa(i));
		path = ft_strjoin(path, ".xpm");
		(*var)->heart[i - 1]->img = mlx_xpm_file_to_image((*var)->mlx, path,
				&((*var)->card_length), &((*var)->card_height));
		(*var)->heart[i - 1]->back = mlx_xpm_file_to_image((*var)->mlx,
				"./textures/card-back2.xpm", &((*var)->card_length),
				&((*var)->card_height));
		(*var)->heart[i - 1]->id = i;
		(*var)->heart[i - 1]->is_face_up = true;
	}
}

void	init_spade(t_var **var)
{
	int		i;
	char	*path;

	i = 0;
	while (++i <= 13)
	{
		(*var)->spade[i - 1] = malloc(sizeof(t_card));
		path = ft_strjoin("./textures/card-spades-", ft_itoa(i));
		path = ft_strjoin(path, ".xpm");
		(*var)->spade[i - 1]->img = mlx_xpm_file_to_image((*var)->mlx,
				path, &((*var)->card_length), &((*var)->card_height));
		(*var)->spade[i - 1]->back = mlx_xpm_file_to_image((*var)->mlx,
				"./textures/card-back2.xpm", &((*var)->card_length),
				&((*var)->card_height));
		(*var)->spade[i - 1]->id = i;
		(*var)->spade[i - 1]->is_face_up = true;
	}
}

void	init_club(t_var **var)
{
	int		i;
	char	*path;

	i = 0;
	while (++i <= 13)
	{
		(*var)->club[i - 1] = malloc(sizeof(t_card));
		path = ft_strjoin("./textures/card-clubs-", ft_itoa(i));
		path = ft_strjoin(path, ".xpm");
		(*var)->club[i - 1]->img = mlx_xpm_file_to_image((*var)->mlx, path,
				&((*var)->card_length), &((*var)->card_height));
		(*var)->club[i - 1]->back = mlx_xpm_file_to_image((*var)->mlx,
				"./textures/card-back2.xpm", &((*var)->card_length),
				&((*var)->card_height));
		(*var)->club[i - 1]->id = i;
		(*var)->club[i - 1]->is_face_up = true;
	}
}

void	init_img(t_var **var)
{
	init_diams(var);
	init_club(var);
	init_heart(var);
	init_spade(var);
}

int	check_tab(int *tab, int nb)
{
	int	i;

	i = -1;
	
}

void	init(t_var *var)
{
	int	type;
	int	card;
	int tab[52];
	var->card_height = 144;
	var->card_length = 96;
	var->screen_height = 144;
	var->screen_length = 1600;
	init_img(&var);
	//add_floor(var, GREEN);

	int i;
	int rng;
	
	i = 0;
    srand(time(NULL));
while (i < 12)
{
	rng = rand() % 52;

	tab[i] = rng;
	tab[i + 1] = -1;
	type = (rng / 13);
	card = (rng % 14);
	printf("nb_rand:%d\ntype:%d\ncard:%d\n", rng, type, card);
	if (type == 0)
		mlx_put_image_to_window(var->mlx, var->win, var->spade[card]->img, (card * (var->card_length + 20)), 0);
	if (type == 1)
		mlx_put_image_to_window(var->mlx, var->win, var->heart[card]->img, (card * (var->card_length + 20)),  (1 * (var->card_length + 50)));
	if (type == 2)
		mlx_put_image_to_window(var->mlx, var->win, var->club[card]->img, (card * (var->card_length + 20)),  (2 * (var->card_length + 50)));
	if (type == 3)
		mlx_put_image_to_window(var->mlx, var->win, var->diams[card]->img, (card * (var->card_length + 20)),  (3 * (var->card_length + 50)));
	//TODO checker si le rng et tomber sur un nombre deja existant
	i++;
}



    // Générer un nombre aléatoire entre 0 et 51
   /* int rnd = rand() % 52;

	type = (rng / 13);
	card = (rng % 14);
	printf("nb_rand:%d\ntype:%d\ncard:%d\n", rng, type, card);*/
	//if (((rng / 13) - 1) = 0)
	//mlx_put_image_to_window(var->mlx, var->win, var->spade[((rng - 1) % 13)]->img, (((0 - 1) % 13) * (var->card_length + 20)), 0);
	/*int	i;
	i = -1;
	while (++i < 13)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->spade[i]->img,  (i * (var->card_length + 20)), 0);
		mlx_put_image_to_window(var->mlx, var->win, var->heart[i]->img,  (i * (var->card_length + 20)), (1 * (var->card_length + 50)));
		mlx_put_image_to_window(var->mlx, var->win, var->club[i]->img,  (i * (var->card_length + 20)), (2 * (var->card_length + 50)));
		mlx_put_image_to_window(var->mlx, var->win, var->diams[i]->img,  (i * (var->card_length + 20)), (3 * (var->card_length + 50)));
	}*/

}

int	mouse_press(int button, int x, int y, t_var *var)
{
	int i;

	(void)var;

	if (button == 1)
	{
		// Piques (Spades)
		for (i = 0; i < 13; i++)
		{
			if (x >= i * (var->card_length + 20) && x <= (i + 1) * (var->card_length + 20)
				&& y >= 0 && y <= var->card_height)
			{
				if (var->spade[i]->is_face_up)
				{
					mlx_put_image_to_window(var->mlx, var->win, var->spade[i]->back,
											i * (var->card_length + 20), 0);
				}
				else
				{
					mlx_put_image_to_window(var->mlx, var->win, var->spade[i]->img,
											i * (var->card_length + 20), 0);
				}
				var->spade[i]->is_face_up = !var->spade[i]->is_face_up;
				return (0);
			}
		}

		// Cœurs (Hearts)
		for (i = 0; i < 13; i++)
		{
			if (x >= i * (var->card_length + 20) && x <= (i + 1) * (var->card_length + 20)
				&& y >= (1 * (var->card_length + 50)) && y <= (1 * (var->card_length + 50)) + var->card_height)
			{
				if (var->heart[i]->is_face_up)
				{
					mlx_put_image_to_window(var->mlx, var->win, var->heart[i]->back,
											i * (var->card_length + 20), (1 * (var->card_length + 50)));
				}
				else
				{
					mlx_put_image_to_window(var->mlx, var->win, var->heart[i]->img,
											i * (var->card_length + 20), (1 * (var->card_length + 50)));
				}
				var->heart[i]->is_face_up = !var->heart[i]->is_face_up;
				return (0);
			}
		}

		// Trèfles (Clubs)
		for (i = 0; i < 13; i++)
		{
			if (x >= i * (var->card_length + 20) && x <= (i + 1) * (var->card_length + 20)
				&& y >= (2 * (var->card_length + 50)) && y <= (2 * (var->card_length + 50)) + var->card_height)
			{
				if (var->club[i]->is_face_up)
				{
					mlx_put_image_to_window(var->mlx, var->win, var->club[i]->back,
											i * (var->card_length + 20), (2 * (var->card_length + 50)));
				}
				else
				{
					mlx_put_image_to_window(var->mlx, var->win, var->club[i]->img,
											i * (var->card_length + 20), (2 * (var->card_length + 50)));
				}
				var->club[i]->is_face_up = !var->club[i]->is_face_up;
				return (0);
			}
		}

		// Carreaux (Diamonds)
		for (i = 0; i < 13; i++)
		{
			if (x >= i * (var->card_length + 20) && x <= (i + 1) * (var->card_length + 20)
				&& y >= (3 * (var->card_length + 50)) && y <= (3 * (var->card_length + 50)) + var->card_height)
			{
				if (var->diams[i]->is_face_up)
				{
					mlx_put_image_to_window(var->mlx, var->win, var->diams[i]->back,
											i * (var->card_length + 20), (3 * (var->card_length + 50)));
				}
				else
				{
					mlx_put_image_to_window(var->mlx, var->win, var->diams[i]->img,
											i * (var->card_length + 20), (3 * (var->card_length + 50)));
				}
				var->diams[i]->is_face_up = !var->diams[i]->is_face_up;
				return (0);
			}
		}
	}
	return (0);
}




int	main(void)
{
	t_var	var;

	var.mlx = mlx_init();
	if (!var.mlx)
	{
		printf("Failed to initialize MLX\n");
		return (1);
	}
	printf("MLX initialized successfully!\n");
	var.win = mlx_new_window(var.mlx, 1600, 1000, "Solitaire");
	if (!var.win)
	{
		fprintf(stderr, "Failed to create a window\n");
		return (1);
	}
	init(&var);
	mlx_mouse_hook(var.win, mouse_press, &var);
	mlx_key_hook(var.win, handle_keypress, &var);
	mlx_loop(var.mlx);
	return (0);
}
