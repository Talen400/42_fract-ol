/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 03:09:20 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/10 03:09:22 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	ft_keyhook(mlx_key_data_t keydata, void *param);

static void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!mlx)
	{
		ft_printf("Error: Failed to initialize MLX42\n");
		return (1);
	}
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		mlx_terminate(mlx);
		return (1);
	}
	ft_clear(img);
	// fractal..
	if (mlx_image_to_window(mlx, img, 0, 0) == -1)
	{
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
		return (1);
	}
	mlx_key_hook(mlx, &ft_keyhook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
