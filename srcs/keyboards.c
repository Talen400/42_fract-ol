/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:35:03 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/13 20:39:40 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_keyhook(mlx_key_data_t k, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (k.action == MLX_PRESS)
	{
		if (k.key == MLX_KEY_ESCAPE)
			mlx_close_window(f->mlx);
		/*
		else if (k.key >= MLX_KEY_1 && k.key <= MLX_KEY_4)
        {
            f->mode = k.key - MLX_KEY_1;
            ft_draw(f);
		}*/
		else if (k.key == MLX_KEY_R)
		{
			ft_draw(f);
		}
	}
}

void	ft_scrollhook(double xd, double yd, void *param)
{
	t_fractol	*f;

	f = (t_fractol *) param;
	ft_draw(f);
	(void ) xd;
}
