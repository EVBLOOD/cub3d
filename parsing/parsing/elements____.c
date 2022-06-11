/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements____.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:30:00 by sakllam           #+#    #+#             */
/*   Updated: 2022/06/11 10:34:23 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	getgvals_(char *line, t_mapelm *map, int *x)
{
	int	y;
	int	tmpy;

	y = 0;
	while (ft_isdigit(line[*x + y]))
		y++;
	tmpy = y;
	map->ceilling_color.g[y] = '\0';
	y--;
	while (y >= 0)
	{
		map->ceilling_color.g[y] = line[*x + y];
		y--;
	}
	*x += tmpy;
}

void	getbvals_(char *line, t_mapelm *map, int *x)
{
	int	y;
	int	tmpy;

	y = 0;
	while (ft_isdigit(line[*x + y]))
		y++;
	tmpy = y;
	map->ceilling_color.b[y] = '\0';
	y--;
	while (y >= 0)
	{
		map->ceilling_color.b[y] = line[*x + y];
		y--;
	}
	*x += tmpy;
}

void	ceilling_color__(char *line, t_mapelm *map, int *i, int x)
{
	int	y;

	y = 0;
	if (line[x])
		x++;
	while (ft_isdigit(line[x + y]))
		y++;
	if (y > 0 && y <= 3 && (line[x + y] == '\n' || line[x + y] == '\0'))
		getbvals_(line, map, &x);
	else
	{
		*i = 1;
		return ;
	}
}

char	*ft_strdup_(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *) malloc(ft_strlen(s) + 1);
	if (!p)
		return (0);
	while (s[i] && s[i] != '\n')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
