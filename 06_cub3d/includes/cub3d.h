/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:44:01 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/15 01:20:08 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../ft_libft/libft.h"
# include "../minilibx/mlx_int.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define BUFFER_SIZE 256
# define FILE_EXTENSION	(".cub")
# define ERR_WRONG_ARGS	("Error\nWrong number of arguments. Exit.")
# define ERR_WRONG_SEC_ARG ("Error\nSecond argument is wrong. Exit.")
# define ERR_WRONG_FILE_NAME	("Error\nWrong file name. Exit.")
# define ERR_WRONG_FILE_EXT	("Error\nWrong file extension. Exit.")
# define ERR_STR_INIT	("Error\nCan't alloc memory for param struct. Exit.")
# define ERR_DARR_INIT	("Error\nCan't alloc memory for map darray. Exit.")
# define ERR_CANT_OPEN	("Error\nCan't open file. Exit.")
# define ERR_WRONG_TYPE	("Error\nFound wrong type. Exit.")
# define ERR_WRONG_TYPE_ARGS ("Error\nWrong type's values set. Exit.")
# define ERR_DUPLICATE_TYPES ("Error\nDuplicate types definition. Exit.")
# define ERR_WRONG_DIAP		("Error\nrong diapasone. Exit.")
# define ERR_MAP_DARR_CREATION ("Error\nwhile creating map double array. Exit.")
# define MSG_STR_INIT_OK	("Info: parameters structure INIT is OK")
# define MSG_FILE_EXT_OK	("Info: file extension is OK")
# define MSG_FILE_OPEN_OK	("Info: file opens OK")
# define MSG_MAP_IS_OK	("MapInfo: Map if OK")
# define MSG_SCREENSHOT ("Info: Making a screenshot..")
# define MSG_SCR_OK ("Info: Screenshot 'first_frame.bmp' is done. Exit.")
# define MSG_CANT_OPEN_NPIC	("Info: wrong N texture filepath or format")
# define MSG_CANT_OPEN_SPIC	("Info: wrong S texture filepath or format")
# define MSG_CANT_OPEN_EPIC	("Info: wrong E texture filepath or format")
# define MSG_CANT_OPEN_WPIC	("Info: wrong W texture filepath or format")
# define ERR_CANT_OPEN_SPPIC ("Error\nWrong sprite texture file. Exit.")
# define ERR_MAP_MANY_GAMERS ("MapError\nMore than one player on map. Exit.")
# define ERR_MAP_BAD_EOL ("MapError\nBad ending of line. Exit.")
# define ERR_MAP_BAD_BOL ("MapError\nBad begginning of line. Exit.")
# define ERR_MAP_BAD_NEIGHBOR ("MapError\nBad neighbor. Exit.")
# define ERR_MAP_BAD_CHAR 	("MapError\nBad character found. Exit.")
# define ERR_MAP_NO_PLAYER	("MapError\nNo player on the map. Exit.")
# define SECOND_ARG			("--save")
# define TYPE_NO			(0b00000001u)
# define TYPE_SO			(0b00000010u)
# define TYPE_EA			(0b00000100u)
# define TYPE_WE			(0b00001000u)
# define TYPE_RES			(0b00010000u)
# define TYPE_F				(0b00100000u)
# define TYPE_C				(0b01000000u)
# define TYPE_S				(0b10000000u)
# define STR_NO				("NO ")
# define STR_SO				("SO ")
# define STR_EA				("EA ")
# define STR_WE				("WE ")
# define STR_RES			("R ")
# define STR_F				("F ")
# define STR_C				("C ")
# define STR_S				("S ")
# define POSS_CHAR			("012NSWE ")
# define POSS_SPACE_NEIB	(" 1")
# define POSS_02_NSWE_NEIB	("012NSWE")
# define POSS_1_NEIB		(" 012NSWE")
# define GAMER_CHAR			("NSWE")
# define POSS_SIDE_CHAR		("1 ")
# define MOVE_FORWARD 		'w'
# define MOVE_BACKW			's'
# define MOVE_LEFT			'a'
# define MOVE_RIGHT			'd'
# define LOOK_LEFT			65361
# define LOOK_RIGHT			65363
# define MAP_SQ_SIZE		17
# define FOV				0.66
# define DIST				2
# define MOVE_STEP			0.2
# define ROT_STEP			0.0872665

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct	s_game
{
	t_list		*map_list;
	char		**map_darray;
	char		*no_path;
	char		*so_path;
	char		*ea_path;
	char		*we_path;
	char		*s_path;
	int			res[2];
	int			color_floor[3];
	int			color_ceiling[3];
	int			fl_color;
	int			ceil_color;
	void		*mlx;
	void		*win;
	t_image		img1;
	t_image		textr[4];
	t_image		spr_textr;
	int			spr_count;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			curr_side;
	double		*dist_array;
	int			*sprite_order;
	double		*sprite_dist;
	double		**sprite_darr;
	int			skip;
}				t_game;

typedef struct	s_camera
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	double		step;
	int			collis;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_coord;
	int			textr_coord_x;
	int			textr_coord_y;
	float		textr_pos;
	int			x;
}				t_camera;

typedef struct	s_scrsht
{
	char		signature[2];
	uint		filesize;
	int			reserved;
	uint		offset;
	uint		header_size;
	uint		dimensions[2];
	ushort		col_planes;
	ushort		bpp;
	uint		compression;
	uint		img_size;
	uint		resolution[2];
	uint		pltcolor;
	uint		impcolor;
}				t_scrsht;

typedef struct	s_sprite
{
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transf_x;
	double		transf_y;
	int			sprite_scr_x;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			draw_start_x;
	int			draw_end_x;
	int			sprite_width;
	int			line;
	int			tex_x;
	int			y;
	int			d;
	int			tex_y;
	int			color;

}				t_sprite;

void			ft_buff_nclean(char *buffer, int start, int n);
int				ft_buff_shift(char *buffer, int shift_len, int buff_size);
int				ft_get_next_line(int fd, char **line);
int				ft_copy(char *buffer, char **line, int buf_size, int line_len);
void			ft_save_screen(t_game *exe);
int				ft_check_argc(int argc, char **argv);
void			ft_write_message(char *mess_name);
void			ft_strwrite(char *str);
int				ft_open_params_file(char *file_path);
t_game			*init_struct(void);
void			ft_free_struct(t_game *map_struct);
void			ft_print_struct(t_game *map_struct);
void			ft_free_str(char *str);
uint			ft_is_enabled_type(char *str, int *i);
int				ft_get_path(char *str, int *i, int type, t_game *param_str);
int				ft_get_resolution(char *str, int *i, t_game *param_str);
int				ft_get_color(char *str, int *i, int type, t_game *param_str);
int				ft_get_type(char *str, int *i, unsigned int *param_set,
				t_game *param_str);
int				ft_fill_type(char *str, int *i, int type,
				t_game *param_str);
int				ft_parameters_parser(int fd, t_game *map_params);
int				ft_spec_atoui(char *str, int *i, int diap_min, int diap_max);
void			ft_write_message(char *mess_name);
void			ft_skip_space(char *str, int *i);
void			ft_free_str(char *str);
char			**ft_get_map_darray(t_list *map_list);
void			ft_free_darray(char **darr);
t_list			*ft_get_map_list(int fd);
char			*ft_get_poss_arr(char symb);
int				*ft_get_neibhors_len(char **map_darray, int curr_line);
int				ft_check_line_validity(char **map_darr, int curr_line,
				int *is_gamer_here);
int				ft_check_map(char **map_darray);
int				ft_darr_len(char **darray);
int				ft_check_left(char *curr_line, int i, char *poss_symb);
int				ft_check_up(char **map_darray, int i, int j, char *poss_symb);
int				ft_check_right(char *curr_line, int i, char *poss_symb,
				int *gamer);
int				ft_check_down(char **map_darray, int i, int j,
				char *poss_symb);
void			ft_get_textures(t_game *exe);
void			ft_get_gamer_pos(t_game *exe);
void			ft_set_gamer_pos(t_game *exe, int i, int j, char way);
void			ft_prep_to_loop(t_game *exe, int argc);
void			ft_win_init(t_game *exe);
t_game			*ft_exe_struct(char **argv);
int				ft_check_resolution(t_game *exe);
int				ft_close_window(int keycode, t_game *exe);
int				ft_my_key_hook(int key, t_game *param);
void			ft_rot_right(t_game *exe);
void			ft_rot_left(t_game *exe);
int				ft_close_window(int keycode, t_game *exe);
void			ft_my_pixel_put(t_game *exe, int x, int y, int color);
void			ft_put_map_square(t_game *exe, int x, int y);
void			ft_create_map(t_game *exe);
void			ft_draw_line(t_game *exe, t_camera *ray);
int				ft_make_frame(t_game *exe);
void			ft_draw_perp(t_game *exe);
void			ft_fill_half(t_game *exe);
void			ft_get_textures(t_game *exe);
void			ft_find_collis(t_camera *ray, t_game *exe);
void			ft_get_textr_color(t_camera *ray, t_game *exe);
void			ft_get_card_point(t_camera *ray, t_game *exe);
int				ft_fill_textr(t_game *exe, t_image *textr, char *path);
int				ft_get_color_z(t_image textr, int x, int y);
void			ft_draw_sprite(t_game *exe);
void			ft_get_sprite_count(t_game *exe);
void			ft_sort_sprays(t_game *exe);

#endif
