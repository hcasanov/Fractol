/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:58:41 by hcasanov          #+#    #+#             */
/*   Updated: 2019/04/29 13:58:42 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef struct      s_mlx
{
   // int     red;
    //int     green;
    //int     blue;
    int     img_w;
    int     img_h;
    int     screen_w;
    int     screen_h;
    void    *img_ptr;
    void    *ptr;
    void    *window;
    char    *img_str;
    int					color;
	unsigned char		red;
	unsigned char		green;
	unsigned char		blue;
}                   t_mlx;

void    ft_usage(void);
void    ft_julia(void);
void	ft_creat_img(t_mlx *mlx);
void    ft_init_list(t_mlx *mlx);
void	ft_exit(void);
void	ft_draw_fractal(t_mlx *mlx);
void	ft_push_img(t_mlx *mlx);

#endif