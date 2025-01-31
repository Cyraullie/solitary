/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:51:09 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/30 13:54:25 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solitary.h"

void	put_img_front(t_var *var, t_card card, int pos_x, int pos_y)
{
	mlx_put_image_to_window(var->mlx, var->win,
		card.front.img, pos_x, pos_y);
	card.pos_x = pos_x;
	card.pos_y = pos_y;
}

void	put_img_back(t_var *var, t_card card, int pos_x, int pos_y)
{
	mlx_put_image_to_window(var->mlx, var->win,
		card.back.img, pos_x, pos_y);
	card.pos_x = pos_x;
	card.pos_y = pos_y;
}
