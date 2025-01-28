/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:14:49 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/28 17:26:40 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solitary.h"

void	place_card(t_var **var)
{
	int	line;
	int	x;
	int	col;
	int	type;
	int	card;

	line = 0;
	x = 0;
	col = 0;
	while (line < 7)
	{
		col = line;
		while (col < 7)
		{
			printf("col_%d, line_%d\n", col, line);
			type = ((*var)->rnd_draft[x] / 13);
			card = ((*var)->rnd_draft[x] % 13);
			if (line == col)
				mlx_put_image_to_window((*var)->mlx, (*var)->win,
					(*var)->draft[type][card].front.img,
					((col + 1) * ((*var)->draft[type][card].front.length + 20)) + 50,
					((line + 1) * 40));
			else
				mlx_put_image_to_window((*var)->mlx, (*var)->win,
					(*var)->draft[type][card].back.img,
					((col + 1) * ((*var)->draft[type][card].front.length + 20)) + 50,
					((line + 1) * 40));
			
			col++;
			x++;
		}
		line++;
	}
	while (x < 52)
	{
		type = ((*var)->rnd_draft[x] / 13);
		card = ((*var)->rnd_draft[x] % 13);
		mlx_put_image_to_window((*var)->mlx, (*var)->win,
				(*var)->draft[type][card].back.img,
				 30, 80 - x);
		x++;
	}
	x = 0;
	while (x < 4)
	{
		mlx_put_image_to_window((*var)->mlx, (*var)->win,
			(*var)->placement[x].img,
				1000, ((((*var)->placement[x].height + 20) * (x + 1))) - 120);
		x++;
	}
}

