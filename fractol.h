#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>

# include <math.h>

# define WIDTH 800
# define HEIGHT 640

typedef struct s_line
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	uint32_t	*pixels;
	double		a, b, c, d;
	int			mode;
} t_sine;

void	ft_drawbuffer(mlx_image_t *img, int x, int y, uint32_t color);
void	ft_keyhook(mlx_key_data_t keydata, void *param);
int	ft_errorinit(mlx_t *mlx);
int	ft_errorimg(mlx_t *mlx, mlx_image_t *img);
void	ft_clearimg(t_sine *s);
#endif
