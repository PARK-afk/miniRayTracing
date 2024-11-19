/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:57:21 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/06 17:50:58 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "vector.h"
# include "object.h"
# include "ray.h"
# include "../mlx/mlx.h"

# define SUCCESS 0
# define ERROR 1
# define KEY_ESC 53
# define X_EVENT_KEY_EXIT 17
# define EPSILON 1e-6

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_mlx;

typedef struct s_vport
{
	double	aspect_ratio;
	double	fov;
	double	v_height;
	double	v_width;
	double	forcal_len;
	t_vec	center;
	t_vec	ri_dir;
	t_vec	up_dir;
	t_vec	left_up;
}t_vport;

typedef struct s_scene
{
	int			width;
	int			height;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_ob		*sphere;
	t_ob		*plane;
	t_ob		*cylinder;
	int			ob_cnt[6];
	t_vport		vport;
	t_mlx		mlx;
}t_scene;

/*get*/
t_color	get_color(char *str);
double	get_height(char *str);
double	get_diameter(char *str);
double	get_ratio(char *str);
t_vec	get_nomalized_vec(char *str);
t_vec	get_vector(char *str);

/*porse utils*/
bool	check_vec(const t_vec vec);
bool	check_color(const t_color color);

/*parse*/
void	parse_data(char *av, t_scene *scene);
void	parse_ambient(char **split, t_scene *scene);
void	parse_camera(char **split, t_scene *scene);
void	parse_light(char **split, t_scene *scene);
void	parse_sphere(char **split, t_scene *scene);
void	parse_plane(char **split, t_scene *scene);
void	parse_cylinder(char **split, t_scene *scene);

/*init*/
void	set_vec(t_vec *vec, double x, double y, double z);
void	init_scene(t_scene *scene);
bool	check_vec(const t_vec vec);

/*cam2view*/
t_vport	cam2view(t_camera *camera, int width, int height);
// t_ray	create_ray(t_scene *scene, int u, int v);
t_ray	create_ray(t_scene *scene, double u, double v);

/*utils*/
void	error_msg(char *msg);
void	free_split(char **str);
void	solve_quadratic(t_quad *q);
void	list_free(t_ob *element);
void	all_list_free(t_scene *scene);

/*color_utils*/
int		color2rgb(t_color c);
int		rgb_to_int(t_color color);
void	ray_color_set(t_ray *ray, t_color color);

/*ob_hit*/
void	hit_sphere(t_ray *ray, t_ob *sphere, t_scene *scene);
void	hit_plane(t_ray *ray, t_ob *plane, t_scene *scene);
void	hit_cylinder(t_ray *ray, t_ob *cylinder, t_scene *scene);
int		hit_shadow(t_ray *ray, t_scene scene);
void	hit_cap(t_ray *ray, t_ob *cy, t_cap *cap);

/*keyhook*/
int		exit_hook(t_mlx *data);
int		press_key(int key_val, t_mlx *data);

/*obj utils*/
double	cos_sp(t_ob *obj, t_ray *ray, t_scene *scene);
double	ref_sp(t_ob *obj, t_ray *ray, t_scene *scene);
double	cos_cy(t_ob *obj, t_ray *ray, t_scene *scene);
double	ref_cy(t_ob *obj, t_ray *ray, t_scene *scene);
double	cos_pl(t_ob *obj, t_ray *ray, t_scene *scene);
double	ref_pl(t_ob *obj, t_ray *ray, t_scene *scene);

/*lightcalculate*/
void	ray_color(t_scene *scene, t_ray *ray);
t_vec	check_plane_direction(t_ob *pl, t_ray *ray);
t_vec	reflective(t_vec normal, t_vec light_dir);
void	shadow_check(t_ray *ray, t_scene scene, int idx);

void	cap_set(t_ob *cy);
bool	finite_height(t_ray *ray, t_ob *cy, double t);

/*shadow_ob*/
void	shadow_cylinder(t_ray *ray, t_ob *cy);
void	shadow_sphere(t_ray *ray, t_ob *sp);
void	shadow_plane(t_ray *ray, t_ob *plane);
t_color	color_scalar(t_color color, double scalar);

/*mlxutils*/
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	m_init(t_mlx *mlx, char *width, char *height, int *wh);
void	ray_set(t_ray *ray, t_mlx *mlx, t_scene *scene, int *xy);

#endif