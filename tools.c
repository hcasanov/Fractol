/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:10 by hcasanov          #+#    #+#             */
/*   Updated: 2019/04/29 17:22:12 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./fractol.h"

void    ft_init_list(t_mlx *mlx)
{
    mlx->ptr = mlx_init();
    mlx->img_w = 1800;
    mlx->img_h = 1200;
    mlx->color = 0xffffff;
    mlx->red = ((unsigned char *)&(mlx->color))[2];
	mlx->green = ((unsigned char *)&(mlx->color))[1];
	mlx->blue = ((unsigned char *)&(mlx->color))[0];
    mlx->window = mlx_new_window(mlx->ptr, mlx->img_w, mlx->img_h, "test");
    mlx->m_x = 500;
    mlx->m_y = 200;

    mlx->x1 = -1.0;
    mlx->x2 = 1.2;
    mlx->y1 = -1.2;
    mlx->y2 = 1.2;
    mlx->zoom = 300;
    mlx->in_max = 50;
    mlx->c_r = 0.285;
    mlx->c_i = 0.02;
}

int		ft_get_key(int key, t_mlx *mlx)
{
	if (key == 5 || key == 2)
		ft_zoom(key, mlx);
    else if (key == 83 || key == 84)
		ft_var_c(key, mlx);
    else if (key == 123 || key == 124)
        ft_move_h(key, mlx);
    else if (key == 126 || key == 125)
        ft_move_v(key, mlx);
	return (0);
}

int     ft_get_key_mouse(int mouse_key, int x, int y, t_mlx *mlx)
{
    if (mouse_key == 5)
        ft_zoom(mouse_key, mlx);
    else if (mouse_key == 4)
        ft_zoom(mouse_key, mlx);
    return (0);
}

void    ft_move_v(int key, t_mlx *mlx)
{
    if (key == 126)
        mlx->m_y = mlx->m_y - 50;
    else if (key == 125)
        mlx->m_y = mlx->m_y + 50;
    ft_refresh_img(mlx);
}

void    ft_move_h(int key, t_mlx *mlx)
{
    if (key == 123)
        mlx->m_x = mlx->m_x - 50;
    else if (key == 124)
        mlx->m_x = mlx->m_x + 50;
    ft_refresh_img(mlx);
}

void	ft_zoom(int key, t_mlx *mlx)
{
	if (key == 5)
        mlx->zoom = mlx->zoom / 2;
    else if (key == 4)
        mlx->zoom = mlx->zoom * 2;
    ft_refresh_img(mlx);
}

void	ft_var_c(int key, t_mlx *mlx)
{
    if (key == 83 && mlx->c_i > 0.000001)
        mlx->c_i = mlx->c_i / 1.1;
    else if (key == 84 && mlx->c_i < 0.748087)
        mlx->c_i = mlx->c_i * 1.1;
    ft_refresh_img(mlx);
}