#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# define WIDTH 800
# define HEIGHT 640

void	ft_drawbuffer(mlx_image_t *img, int x, int y, uint32_t color);
void	ft_clear(mlx_image_t *img);

#endif
