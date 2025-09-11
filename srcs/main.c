/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 03:09:20 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/11 17:26:09 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(void)
{
	t_sine	s;

	s.a = 1.0;
	s.b = 1.0;
	s.c = 0.0;
	s.d = 0.0;
	s.mode = 0;
	s.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!s.mlx)
		return (ft_errorinit(s.mlx));
	s.img = mlx_new_image(s.mlx, WIDTH, HEIGHT);
	if (!s.img)
			return (ft_errorinit(s.mlx));
	ft_clearimg(&s);
	// fractal..
	if (mlx_image_to_window(s.mlx, s.img, 0, 0) == -1)
		return (ft_errorimg(s.mlx, s.img));
	mlx_key_hook(s.mlx, &ft_keyhook, s.mlx);
	mlx_loop(s.mlx);
	mlx_terminate(s.mlx);
	return (0);
}
