/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:37:10 by barjimen          #+#    #+#             */
/*   Updated: 2024/07/30 23:53:10 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>

typedef enum e_sprites {
	FLOOR,
	PLAYER_UP,
	PLAYER_DOWN,
	PLAYER_RGHT,
	PLAYER_LEFT,
	COLLECT,
	WALL,
	EXIT,
	EXIT_OK,
	ENEMY,
	COVER
} t_sprites;

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bppx;
	int		line_length;
	int		endian;
	int     width;
    int     height;
}				t_img;

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	t_img		sprites[11]; // MLX image pointers (on the stack)
	t_img		img; //TODO: background
}	t_data;

typedef struct s_player
{
	int x;
	int y;
	int player_moves;
	int	collect_num;
} t_player;

typedef struct s_map
{
	int c;
	int p;
	int e;
	int width;
	int height;
} t_map;

typedef struct s_so_long
{
	char		**map;
	int			map_h;
	int 		map_w;
	int			h_offset;
	int			w_offset;
	
	t_map		maps;
	t_player	player;
	t_data 		mlx_data;
	
}	t_so_long;


void	arg_handler(int argc, char **argv);
char	*map_check(t_so_long *so_long);
void 	map_iter_context(char **map, void (*f)(void *, int x, int y), void *data);
void 	is_char(void *data, int x, int y);
void 	is_map_valid(void *data, int x, int y);
void 	is_valid_e_c(void *data, int x, int y);
void	render_map(t_so_long    *so_long);
int 	length_map(char **map);
int		height_map(char **map);
void	paint_map(int width, int height, char *img, t_so_long *so_long);
char	**load_map(char *path);
void    offset_calculator(t_so_long *so_long);


/* Image Handle */
void			put_pixel_img(t_img img, int x, int y, int color);
t_img			create_image(void *mlx, int width, int height);
unsigned int	get_pixel_img(t_img img, int x, int y);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
t_img			load_xpm(void *mlx, char *path);

void	create_background(void	*data, int x, int y);
void	 item_removed(t_so_long	*so_long);
void	create_items(void	*data, int x, int y);
void	create_player(void	*data, int x);
int check_all_img(void);




//Hooks
int	exit_msg(char *msg);
int close_w(t_data *mlx);
int	key_hook(int keycode, t_so_long *so_long);

// To library
int	ft_str_end_with(const char *str, const char *end);

//-- Window and other things

# define W_SIZE 3840
# define H_SIZE 1980

//-- Error msg --
# define FD_0 "FD error!"
# define NOT_BER "File needs to be .ber!"
# define ARG_KO "To much arguments!"
# define MAP_KO "Invalid map!"
# define MAP_CHAR_KO "Only valid 1,0,C,P,E"
# define MAP_H_KO "Height not valid!"
# define MAP_W_KO "Width not valid!"
# define MAP_LENGHT_KO "Different lenght lines!"
# define IMG_KO "Image missing!!!"
//-- Map checker error msg --
# define CPE_MSG "C,P or E error!"
# define C_MSG "Can't reach C!"
# define E_MSG "Can't reach E!"
//-- Close window --
# define C_WINDOW "Bye!"
# define WIN 	  "Has ganado!"

//-- SRC IMG
# define WALLS_SRC "./img/grass.xpm"
# define FLOOR_SRC "./img/wood_floor.xpm"
# define ROOMBA_SRC_RHT "./img/roomba_right.xpm"
# define ROOMBA_SRC_LFT "./img/roomba_left.xpm"
# define ROOMBA_SRC_UP "./img/roomba_up.xpm"
# define ROOMBA_SRC_DWN "./img/roomba_down.xpm"
# define EXIT_OK_SRC "./img/exit_win.xpm"
# define EXIT_KO_SRC "./img/exit_close.xpm"
# define COLLECT_SRC "./img/item_1.xpm"
# define COVER_SRC "./img/cover.xpm"

//-- Others
# define MSG_GUIDE "Los controles son: AWSD o Flechas para moverte."

#endif