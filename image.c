/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:10:11 by hcasanov          #+#    #+#             */
/*   Updated: 2019/04/29 17:10:12 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./fractol.h"

/*void	ft_draw_fractal(t_mlx *mlx)
{

}*/

void	ft_push_img(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img_ptr, 0, 0);
}

void	ft_creat_img(t_mlx *mlx)
{
	int	bpp;
	int	s_l;
	int	endian;

	bpp = 32;
	s_l = (mlx->screen_w) * 4;
	endian = 0;
	
	mlx->img_ptr = mlx_new_image(mlx->ptr, mlx->img_w, mlx->img_h);
	mlx->img_str = mlx_get_data_addr(mlx->img_ptr, &bpp, &s_l, &endian);
}