/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:46:39 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/20 14:40:34 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "struct.h"
# include "dimension.h"

t_wolf		*loading_wolf_data(void);
void		zero_wolf_data(t_wolf *wolf);
void		zero_mlx_data(t_mlx *mlx);
void		zero_loading_data(t_load *load);
void		install_mlx_data(t_wolf *wolf, t_mlx *mlx);
void		install_loading_data(t_wolf *wolf, t_load *load);
void		loading_data(t_wolf *wolf);
void		loading_bar(t_mlx *mlx, t_load *load, int maxy);
void		loading_gool(t_wolf *wolf, t_load *load, int gool);
void		destroy_wolf_data(t_wolf *wolf, int opt);
void		wolf_exit(int opt);
void		destroy_mlx_data(t_mlx *mlx);
void		destroy_loading_data(t_wolf *wolf, t_load *load);
t_map		*install_map_data(void);
t_map		*read_map_data(t_map *map);
int			read_map_file(char *path, int **map);
int			read_map_line(int **map, int line, char *buf);
int			read_map_error(char *path);
int			alloc_map(t_map *map);
int			free_map(t_map *map);
int			install_tex_data(char *path, t_tex *tex, t_mlx *mlx);
int			install_walls_data(t_boy *boy, t_mlx *mlx);
int			install_wop_data(t_boy *boy, t_mlx *mlx);
void		zero_boy_data(t_boy *boy);
t_boy		*destroy_boy(t_boy *boy, t_wolf *wolf);
t_boy		*install_boy_data(t_wolf *wolf);
t_sta		*install_sta_data(t_wolf *wolf);
t_sta		*destroy_sta_data(t_sta *sta, t_mlx *mlx);
void		zero_sta_data(t_sta *sta);
void		draw_start_selection(t_sta *sta, t_wolf *wolf, int x, int y);
void		event_start_mouse(t_wolf *wolf, t_evt *evt, int x, int y);
void		draw_start(t_sta *sta, t_wolf *wolf);
t_gen		*install_gen_data(t_wolf *wolf);
t_gen		*destroy_gen_data(t_gen *gen, t_mlx *mlx);
void		zero_gen_data(t_gen *gen);
void		draw_gen(t_gen *gen, t_wolf *wofl);
void		darw_gen_map(t_gen *gen, t_wolf *wolf);
void		gen_event_mouse(t_wolf *wolf, int boy, int x, int y);
void		gen_select_event(t_evt *evt, t_wolf *wolf, int x, int y);
t_mmap		*install_mmap_data(t_wolf *wolf);
void		draw_mmap(t_wolf *wolf, t_mmap *map);
t_mus		*install_mus_data(void);
t_mus		*destroy_mus_data(t_mus *mus);
void		detect_music(t_wolf *wolf);
void		zero_player(t_player *player);
void		zero_event(t_evt *evt);
void		draw_wop(t_wolf *wolf, t_evt *evt, t_wop *wop);
void		draw_box(t_wolf *wolf, t_box *box, t_evt *evt);
void		draw_rayc(t_wolf *wolf);
void		ft_clear_data(int *tab);
void		draw_wolf(t_wolf *wolf);
t_point		rotat(t_point p, double angle);
void		init_side(t_side *s);
void		init_ray_cmp2(t_ray *ray, t_wolf *f);
void		init_ray_cmp(t_ray *ray, t_wolf *f, int x);
void		detect_walls(t_wolf *f, t_ray *ray);
void		detect_side_wallh(t_ray *ray, t_wolf *f);
int			*detect_tex(t_ray *ray, t_wal wal);
void		draw_text(t_wolf *f, int x, t_ray *ray);
void		init_floor_cel(t_ray *ray);
void		aplly_flo(t_ray *ray, t_wolf *f, int x, int *flo);
void		aplly_cel(t_ray *ray, t_wolf *f, int x, int *cel);
int			get_color(int color, double dist);
void		*part1(void *arg);
void		*part2(void *arg);
void		*part3(void *arg);
void		*part4(void *arg);
int			key_event_pres(int key, t_wolf *wolf);
int			key_event_relese(int key, t_wolf *wolf);
void		update_move(t_wolf *wolf, t_evt *evt);
void		mouse_wolf(t_wolf *f);
int			close_wolf(t_wolf *wolf);
void		check_seting(int key, t_wolf *wolf, t_evt *evt);
void		check_rotation(int key, t_evt *evt);
void		check_moves(int key, t_wolf *wolf, t_evt *evt);
int			close_wolf(t_wolf *wolf);
void		*get_png_ptr(char *path, t_mlx *mlx, int w, int h);
void		free_png_ptr(void *png_ptr, t_mlx *mlx);
void		put_png_ptr(void *png_ptr, int x, int y, t_mlx *mxl);
void		put_str(char *str);

#endif
