/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 02:41:00 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/11 17:30:19 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_drawbuffer(mlx_image_t *img, int x, int y, uint32_t color)
{
	if (x >= 0 && x <= (int)img->width && y >= 0 && y < (int)img->height)
		*((uint32_t *)(img->pixels + (y * img->width + x) * 4)) = color;
}

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}

int	ft_errorinit(mlx_t *mlx)
{
	if (mlx)
		mlx_terminate(mlx);
	ft_printf("%s", mlx_strerror(mlx_errno));
	return (1);
}

int	ft_errorimg(mlx_t *mlx, mlx_image_t *img)
{
	if (img)
		mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (1);
}

void	ft_clearimg(t_sine *s)
{
	ft_memset(s->img->pixels, 255, s->img->width * s->img->height * sizeof(uint32_t));
}
