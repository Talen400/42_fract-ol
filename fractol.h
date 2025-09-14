#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>

# include <math.h>

# define WIDTH 800
# define HEIGHT 600
# define HALF_WIDTH (WIDTH / 2)
# define HALF_HEIGHT (HEIGHT / 2)

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	uint32_t	*pixels;
} t_fractol;

typedef struct s_complex
{
	float	real;
	float	img;
} t_complex;

void	ft_draw(t_fractol	*f);
void	ft_keyhook(mlx_key_data_t keydata, void *param);
int	ft_errorinit(mlx_t *mlx);
int	ft_errorimg(mlx_t *mlx, mlx_image_t *img);
void	ft_clearimg(t_fractol *f);
void	ft_scrollhook(double xd, double yd, void *param);
#endif
