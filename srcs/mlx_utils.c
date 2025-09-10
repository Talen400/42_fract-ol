/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 02:41:00 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/10 03:10:06 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_drawbuffer(mlx_image_t *img, int x, int y, uint32_t color)
{
	if (x >= 0 && x <= (int)img->width && y >= 0 && y < (int)img->height)
		*((uint32_t *)(img->pixels + (y * img->width + x) * 4)) = color;
}

void	ft_clear(mlx_image_t *img)
{
	uint32_t	*pixels;
	int			total_pixels;
	int			i;

	pixels = (uint32_t *)img->pixels;
	total_pixels = img->width * img->height;
	i = 0;
	while (i < total_pixels)
	{
		pixels[i] = 0x000000FF;
		i++;
	}
}
