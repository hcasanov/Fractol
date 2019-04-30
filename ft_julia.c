/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:02:22 by hcasanov          #+#    #+#             */
/*   Updated: 2019/04/29 17:02:25 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./fractol.h"

void       ft_test(t_mlx *mlx)
{
    int   i;

    i = 0;
    while (i < 1800*1200)
    {
      mlx->img_str[i] = mlx->red;
	    mlx->img_str[i + 1] = mlx->red;
	    mlx->img_str[i + 2] = mlx->red;
      i = i + 4;
    }
}

void        ft_julia(void)
{
    t_mlx   *list;

    if (!(list = (t_mlx *)malloc(sizeof(t_mlx))))
        ft_exit();
    ft_init_list(list);
    ft_creat_img(list);
    ft_test(list);
    printf("%s\n", list->img_ptr);
    //mlx_new_window(list->img_ptr, 1800, 1200, "Test"); FONCTION A ENLEVER (OUVRE JUSTE UNE FENETRE SEUL
    //ft_draw_fractal(mlx);
    //ft_push_img(list);
    //mlx_hook(mlx->window, 2, (1L << 0), ft_get_key, mlx);
    //mlx_loop(list->ptr);
}