/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:12:03 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/06 18:04:27 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

bool	check_line_continue(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\\')
			return (true);
		else if (line[i] == '#')
			return (true);
		else if (ft_strcmp(line, "\n") == 0)
			return (true);
		else if (line[i] == '\0')
			return (false);
		i++;
	}
	return (false);
}

void	parse_line(char *line, t_scene *scene)
{
	char	**split;

	split = ft_split(line, " \t\n");
	if (ft_strcmp(split[0], "A") == 0)
		parse_ambient(split, scene);
	else if (ft_strcmp(split[0], "C") == 0)
		parse_camera(split, scene);
	else if (ft_strcmp(split[0], "L") == 0)
		parse_light(split, scene);
	else if (ft_strcmp(split[0], "sp") == 0)
		parse_sphere(split, scene);
	else if (ft_strcmp(split[0], "pl") == 0)
		parse_plane(split, scene);
	else if (ft_strcmp(split[0], "cy") == 0)
		parse_cylinder(split, scene);
	else
		error_msg("invalid identifier\n");
	free_split(split);
}

void	check_ob_cnt(t_scene *scene)
{
	if (scene->ob_cnt[AMBIENT] != 1)
		error_msg("Not one data for Ambient\n");
	if (scene->ob_cnt[CAMERA] != 1)
		error_msg("Not one data for Camera\n");
	if (scene->ob_cnt[LIGHT] != 1)
		error_msg("Not one data for Light\n");
	if (scene->ob_cnt[SPHERE] == 0 && scene->ob_cnt[PLANE] == 0 \
		&& scene->ob_cnt[CYLINDER] == 0)
		error_msg("object data is empty\n");
}

void	parse_data(char *av, t_scene *scene)
{
	int		fd;
	char	*line;

	if (ft_strnrcmp(av, ".rt", 3) != 0)
		error_msg("file extension");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_msg("file open");
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		if (check_line_continue(line) == false)
			parse_line(line, scene);
		free(line);
	}
	free(line);
	close(fd);
	check_ob_cnt(scene);
}
