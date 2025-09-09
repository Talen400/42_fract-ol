#include "fractol.h"

#define WIN_WIDTH 1280
#define WIN_HEIGHT 800

#define MLX_ERROR 1

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
} t_mlx_data;

int	ft_mlx_init(t_mlx_data *t_mlx)
{
	t_mlx->mlx = mlx_init();
	if (t_mlx->mlx == NULL)
		return (MLX_ERROR);
	t_mlx->win = mlx_new_window(t_mlx->mlx, WIN_WIDTH, WIN_HEIGHT, 
			"Hello World");
	if (t_mlx->win == NULL)
	{
		mlx_destroy_display(t_mlx->mlx);
		free(t_mlx->mlx);
		return (MLX_ERROR);
	}
	t_mlx->img = mlx_new_image(t_mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (t_mlx->img == NULL)
	{
		mlx_destroy_window(t_mlx->mlx, t_mlx->win);
		mlx_destroy_display(t_mlx->mlx);
		free(t_mlx->mlx);
		return (MLX_ERROR);
	}
	return (0);
}

void	ft_destroy(t_mlx_data *t_mlx)
{
	mlx_clear_window(t_mlx->mlx, t_mlx->win);
	mlx_destroy_image(t_mlx->mlx, t_mlx->img);
	mlx_destroy_window(t_mlx->mlx, t_mlx->win);
	mlx_destroy_display(t_mlx->mlx);
	free(t_mlx->mlx);
}

void	ft_draw(void *img, int x, int y, int color)
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
	char	*pixel;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	pixel = data + (y * size_line) + (x * (bpp / 8));
	*(int*) pixel = color;
}

void	ft_map(t_mlx_data *t_mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < 300)
	{
		x = 0;
		while (x < 400)
		{
			ft_draw(t_mlx->img, x, y, 0xFFFFFFF);
			x++;
		}
		y++;
	}
}

int	ft_rendering(void *param)
{
	t_mlx_data	*t_mlx;

	t_mlx = (t_mlx_data *) param;
	ft_map(t_mlx);
	mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, t_mlx->img, 0, 0);
	return (0);
}

int main(void)
{
	t_mlx_data *t_mlx;
	int			ret;

	t_mlx = ft_calloc(1, sizeof(t_mlx));
	ret = ft_mlx_init(t_mlx);
	if (ret < 0)
	{
		free(t_mlx);
		return (MLX_ERROR);
	}
	mlx_loop_hook(t_mlx->mlx, ft_rendering, t_mlx);
	mlx_loop(t_mlx->mlx);
	ft_destroy(t_mlx);
	free(t_mlx);
	return (0);
}
