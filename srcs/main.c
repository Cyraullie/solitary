/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:45:09 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/27 17:30:43 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solitary.h"

int	handle_keypress(int keycode, t_var *var)
{
	printf("Key pressed: %d\n", keycode);

	(void)var;
	if (keycode == 65307)
	{
		printf("Escape key pressed. Exiting program...\n");
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	return (0);
}



int	check_tab(int *tab, int nb)
{
	int	i;

	i = -1;
	while (tab[++i] != -1)
	{
		if (tab[i] == nb)
			return (1);
	}
	return (0);
}

void	init_rng(t_var **var)
{
	int	i;
	int	rng;

	i = 0;
	(*var)->rnd_draft = ft_calloc(sizeof(int), 53);
	(*var)->rnd_draft[i] = -1;
	while (i < 52)
	{
		rng = rand() % 52;
		if (!check_tab((*var)->rnd_draft, rng))
		{
			(*var)->rnd_draft[i] = rng;
			(*var)->rnd_draft[i + 1] = -1;
			i++;
		}
	}
}

void	init(t_var *var)
{
	int	type;
	int	card;
	int	i;

	srand(time(NULL));
	var->screen_height = 1000;
	var->screen_length = 1600;
	init_img(&var);
	add_floor(var);
	init_rng(&var);
	//TODO virer ca 
	i = 52;
	while (--i > 40)
	{
		type = (var->rnd_draft[i] / 13);
		card = (var->rnd_draft[i] % 13);
		mlx_put_image_to_window(var->mlx, var->win, var->draft[type][card].front.img, (card * (var->draft[type][card].front.length + 20)) + 20, (type * (var->draft[type][card].front.height + 50)) + 50);
	}
}
/*
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
*/



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
	//mlx_mouse_hook(var.win, mouse_press, &var);
	mlx_key_hook(var.win, handle_keypress, &var);
	mlx_loop(var.mlx);
	return (0);
}
