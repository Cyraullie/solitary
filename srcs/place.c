/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:14:49 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/30 13:57:21 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solitary.h"

void	place_card(t_var **var)
{
	int	line;
	int	x;
	int	col;

	line = 0;
	x = 0;
	col = 0;
	while (line < 7)
	{
		col = line;
		while (col < 7)
		{
			display_play(var, line, col, x);
			col++;
			x++;
		}
		line++;
	}
	display_draft(var, x);
	display_placement(var);
}

/**
 * @brief function to display the draft
 * 
 * @param var 
 * @param x 
 */
void	display_draft(t_var **var, int x)
{
	int	type;
	int	card;

	while (x < 52)
	{
		type = ((*var)->rnd_draft[x] / 13);
		card = ((*var)->rnd_draft[x] % 13);
		(*var)->stack[x - 28] = (*var)->draft[type][card];
		mlx_put_image_to_window((*var)->mlx, (*var)->win,
			(*var)->stack[x - 28].back.img,
			30, 80 - x);
		(*var)->stack[x - 28].is_face_up = false;
		(*var)->stack[x - 28].pos_x = 30;
		(*var)->stack[x - 28].pos_y = 80;
		x++;
	}
}

/**
 * @brief function to display the playable area
 * 
 * @param var 
 * @param line 
 * @param col 
 * @param x 
 */
void	display_play(t_var **var, int line, int col, int i)
{
	int	x;
	int	y;
	int	type;
	int	card;

	type = ((*var)->rnd_draft[i] / 13);
	card = ((*var)->rnd_draft[i] % 13);
	(*var)->play[col][line] = (*var)->draft[type][card];
	x = ((col + 1) * ((*var)->play[col][line].front.length + 20)) + 50;
	y = (line + 1) * 40;
	if (line == col)
	{
		put_img_front(*var, (*var)->play[col][line], x, y);
		(*var)->play[col][line].is_face_up = true;
	}
	else
	{
		put_img_back(*var, (*var)->play[col][line], x, y);
		(*var)->play[col][line].is_face_up = false;
	}
	(*var)->play[col][line].pos_x = x;
	(*var)->play[col][line].pos_y = y;
}

/**
 * @brief function to display the placement for final stack
 * 
 * @param var 
 */
void	display_placement(t_var **var)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		mlx_put_image_to_window((*var)->mlx, (*var)->win,
			(*var)->placement[x].img,
			1000, ((((*var)->placement[x].height + 20)
					* (x + 1))) - 120);
		x++;
	}
}
