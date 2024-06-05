/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:37:10 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/05 22:21:46 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct base
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
}	t_data;

typedef struct s_so_long
{
	char		**map;
	t_data 		mlx_data;
	
}	t_so_long;


char	**arg_handler(int argc, char **argv, char **map);
char	*map_check(char **map);
void	is_char(char **map, int width, int height);
int	is_map_valid(char **map, int width, int height);
