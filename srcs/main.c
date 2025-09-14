/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 03:09:20 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/13 21:47:46 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static inline void	ft_put(uint32_t *pixels, int x, int y,
		uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		pixels[y * WIDTH + x] = color;
}

static inline t_complex	ft_addcomplex(t_complex a, t_complex b)
{
	t_complex	new;

	new.real = a.real + b.real;
	new.img = a.img + b.img;
	return (new);
}

static inline t_complex	ft_multcomplex(t_complex a, t_complex b)
{
	t_complex	new;

	new.real = (a.real * b.real - a.img * b.img);
	new.img = (a.real * b.img + a.img * b.img);
	return (new);
}

static inline float	ft_abscomplex(t_complex z)
{
	return (z.real * z.real + z.img * z.img);
}

void	ft_draw(t_fractol	*s)
{
	int	x;
	int	y;

}

int	main(void)
{
	t_fractol	f;

	f.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!f.mlx)
		return (ft_errorinit(f.mlx));
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	if (!f.img)
			return (ft_errorinit(f.mlx));
	f.pixels = (uint32_t *) f.img->pixels;
	ft_draw(&f);
	// fractal..
	if (mlx_image_to_window(f.mlx, f.img, 0, 0) == -1)
		return (ft_errorimg(f.mlx, f.img));
	mlx_scroll_hook(f.mlx, &ft_scrollhook, &f);
	mlx_key_hook(f.mlx, &ft_keyhook, &f);
	ft_printf("y = A * sin(B * x + C) + D\n");
	ft_printf("1-4: modo A,B,D,D | Scroll: alterar | R: reset\n", 1);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}
