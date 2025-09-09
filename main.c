#include "fractol.h"

typedef struct s_data {
    void    *mlx;
    void    *win;
}               t_data;

// Função para fechar a janela ao pressionar 'ESC' ou clicar no 'X' da janela
static int close_window(int keycode, t_data *data)
{
    if (keycode == 65307) // Código da tecla ESC no sistema (pode variar, este é para X11)
        mlx_destroy_window(data->mlx, data->win);
    return (0);
}

// Função para fechar a janela quando o usuário clica no 'X'
static int exit_button(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Teste MinilibX");

    // Desenha um pixel vermelho no centro da janela
    mlx_pixel_put(data.mlx, data.win, 400, 300, 0xFF0000);

    // Configura os hooks (eventos)
    mlx_key_hook(data.win, close_window, &data);
    mlx_hook(data.win, 17, 0, exit_button, &data); // 17 é o evento de clicar no 'X' da janela

    mlx_loop(data.mlx);
    return (0);
}
