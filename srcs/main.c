/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:45:09 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/31 10:37:15 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solitary.h"

bool	g_first_click = true;

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



void	reveal_card(t_var **var)
{
	int	i;

	i = 24;
	while (--i > 0)
	{
		(*var)->stack[i].is_face_up = false;
		(*var)->stack[i].pos_x = 30;
		(*var)->stack[i].pos_y = 80;
	}

}

int	mouse_press_on_stack(int button, int x, int y, t_var *var)
{
	static int	i;

	if (g_first_click)
	{
		g_first_click = false;
		i = 23;
	}
	if (i == 0)
		i = 23;
	if (button == 1)
	{
		if (x >= 30 && x <= 120 && y >= 30 && y <= 200)
		{
			printf("%d\n", i);
			if (!var->stack[i].is_face_up)
			{
				var->stack[i].is_face_up = true;
				put_img_front(var, var->stack[i], 30, 250);
				i--;
			}
			if (i == 0)
				reveal_card(&var);
			return (0);
		}
	}
	return (1);
}

t_card	*find_clicked_card_stack(t_var *vars, int x, int y)
{
	for (int i = 0; i < 25; i++) // Supposons qu'il y ait au max 25 cartes
	{
		t_card *card = &vars->stack[i];
		if (card->is_face_up && x >= card->pos_x && x <= card->pos_x + CARD_WIDTH &&
			y >= card->pos_y && y <= card->pos_y + CARD_HEIGHT)
		{
			return card; // Retourne la carte sur laquelle on a cliqué
		}
	}
	return NULL; // Aucune carte trouvée
}

t_card *find_clicked_card_play(t_var *vars, int x, int y)
{
    for (int col = 0; col < 7; col++) // 7 colonnes du solitaire
    {
        for (int row = 0; row < 25; row++) // 25 max cartes empilées
        {
            t_card *card = &vars->play[col][row];
            if (card->is_face_up && x >= card->pos_x && x <= card->pos_x + CARD_WIDTH &&
                y >= card->pos_y && y <= card->pos_y + CARD_HEIGHT)
            {
                return card; // Retourne la carte trouvée
            }
        }
    }
    return NULL; // Aucune carte trouvée
}


int mouse_press(int button, int x, int y, t_var *vars)
{
    if (button == 1) // Clic gauche
    {
		if (mouse_press_on_stack(button, x, y, vars))
		{
			t_card *clicked_card = find_clicked_card_stack(vars, x, y);
			if (!clicked_card)
				clicked_card = find_clicked_card_play(vars, x, y);

			if (clicked_card)
			{
				printf("Carte cliquée : ID = %d, Position = (%d, %d)\n",
					clicked_card->id, clicked_card->pos_x, clicked_card->pos_y);

				// Active le dragging si la carte est face visible
				if (clicked_card->is_face_up)
				{
					vars->dragging = 1;
					vars->dragged_card = clicked_card; // Stocke la carte en cours de déplacement
					clicked_card->tmp_x = clicked_card->pos_x;
					clicked_card->tmp_y = clicked_card->pos_y;
					printf("Début du drag sur la carte ID = %d\n", clicked_card->id);
				}
			}
		}
    }
    return (0);
}

int mouse_move(long long x, long long y, t_var *vars)
{
	printf("Mouse moving at (%lld, %lld)\n", x, y);
	printf("drag_%d\n", vars->dragging);
	usleep(50);
    /*if (vars->dragging && vars->dragged_card)
    {
	//printf("cardx%d cady%d\n", vars->dragged_card->tmp_x, vars->dragged_card->tmp_y);
        vars->dragged_card->pos_x = x - (CARD_WIDTH / 2);  // Centre la carte sur la souris
        vars->dragged_card->pos_y = y - (CARD_HEIGHT / 2);

        mlx_clear_window(vars->mlx, vars->win); // Efface l'écran
        //display_play(&vars, 0, 0, 0); // Redessine le plateau
        put_img_front(vars, *vars->dragged_card, vars->dragged_card->pos_x, vars->dragged_card->pos_y); // Dessine la carte déplacée
    }*/
    return (0);
}

t_card *get_top_card(t_var *vars, int col)
{
    int row = 24; // Dernière ligne possible (car max 25 cartes par colonne)

    while (row >= 0)
    {
        if (vars->play[col][row].id != 0) // Vérifie si une carte existe ici
        {
            return &vars->play[col][row]; // Retourne la carte trouvée
        }
        row--;
    }
    return NULL; // Aucune carte dans cette colonne
}

bool is_valid_position(t_var *vars, t_card *card, int x, int y)
{
    for (int col = 0; col < 7; col++)
    {
        if (x >= vars->play[col][0].pos_x && x <= vars->play[col][0].pos_x + CARD_WIDTH &&
            y >= vars->play[col][0].pos_y && y <= vars->play[col][0].pos_y + CARD_HEIGHT)
        {
            // Vérifie si on peut placer la carte ici (exemple : couleur opposée et valeur inférieure de 1)
            t_card *top_card = get_top_card(vars, col);
            if (top_card && top_card->is_face_up &&
                top_card->is_red != card->is_red && top_card->id == card->id + 1)
            {
                return true;
            }
        }
    }
    return false;
}


int mouse_release(int button, int x, int y, t_var *vars)
{
    if (button == 1 && vars->dragging) // Clic gauche relâché
    {
        t_card *card = vars->dragged_card;
        
        // Vérifie si la carte peut être posée ici
        if (is_valid_position(vars, card, x, y)) 
        {
            card->pos_x = x - (CARD_WIDTH / 2);
            card->pos_y = y - (CARD_HEIGHT / 2);
            printf("Carte ID %d placée à (%d, %d)\n", card->id, card->pos_x, card->pos_y);
        }
        else
        {
            // Remet la carte à sa position initiale
            card->pos_x = card->tmp_x;
            card->pos_y = card->tmp_y;
            printf("Mauvais emplacement, retour à (%d, %d)\n", card->pos_x, card->pos_y);
        }

        // Stoppe le dragging
        vars->dragging = 0;
        vars->dragged_card = NULL;

        mlx_clear_window(vars->mlx, vars->win);
        display_play(&vars, 0, 0, 0); // Redessine le plateau
    }
    return (0);
}


//TODO gerer les free de toutes les merdes a free;
int	main(void)
{
	t_var	var;

	srand(time(NULL));
	var.mlx = mlx_init();
	if (!var.mlx)
	{
		printf("Failed to initialize MLX\n");
		return (1);
	}
	printf("MLX initialized successfully!\n");
	var.win = mlx_new_window(var.mlx, WIN_WIDTH, WIN_HEIGHT, "Solitaire");
	if (!var.win)
	{
		fprintf(stderr, "Failed to create a window\n");
		return (1);
	}
	init(&var);
	var.dragging = 0;
	mlx_key_hook(var.win, handle_keypress, &var);
	mlx_mouse_hook(var.win, mouse_press, &var);
	//mlx_hook(var.win, 6, 0, mouse_move, &var);
	mlx_loop_hook(var.mlx, mouse_move, &var);

	mlx_hook(var.win, EVENT_MOUSE_RELEASE, 0, mouse_release, &var);
	mlx_loop(var.mlx);
	return (0);
}
