/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:25:40 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/19 22:06:07 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double dist_two_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	cast_ray(t_data *data, double ray_angle, int i)
{
	ray_angle = setup_rot_angle(ray_angle);
	horz_inter(data, ray_angle, i);
	vert_inter(data, ray_angle, i);
	calculate_dis(data, i);
	data->ray.rayAngle = ray_angle;
	data->ray.is_FaceDown = isFace_Down;
	data->ray.is_FaceUp = isFace_Up;
	data->ray.is_FaceRight = isFace_Left;
	data->ray.is_FaceRight = isFace_Right;
}

void	cast_ray(t_data *data, double ray_angle, int i)
{
	ray_angle = setup_rot_angle(ray_angle);
	int	isFace_Down = ray_angle > 0 && ray_angle < M_PI;
	int	isFace_Up = !isFace_Down;

	int isFace_Right = ray_angle < (M_PI / 2) || ray_angle > (3 * M_PI / 2);
	int isFace_Left = !isFace_Right;

	double x_inter, y_inter;
	double x_step, y_step;

	// ==================
	// CHECK HORZ HITS
	// ==================

	// horz_inter();
	int foundHorz_hit = 0;
	double horzHit_x = 0;
	double horzHit_y = 0;
	int	horzContent = 0;

	x_inter = floor(data->ray.player_y / data->map_info.square_S) * data->map_info.square_S;
	x_inter += isFace_Down ? data->map_info.square_S : 0;

	y_inter = data->ray.player_x + (y_inter - data->ray.player_y) / tan(ray_angle);

	//calculate the xstep and ystep
	y_step = data->map_info.square_S;
	y_step *= isFace_Up ? -1 : 1;

	x_step = data->map_info.square_S / tan(ray_angle);
	x_step *= (isFace_Left && x_step > 0) ? -1 : 1;
	x_step *= (isFace_Right && x_step < 0) ? -1 : 1;

	double next_x = x_inter;
	double next_y = y_inter;

	//increment xstep and ystep until find a wall hit
	while (next_x >= 0 && next_x <= WIDTH && next_y >= 0 && next_y <= HEIGHT)
	{
		double x_toCheck = next_x;
		double y_toCheck = next_y + (isFace_Up ? -1 : 0);

		if (is_wall(x_toCheck, y_toCheck))
		{
			horzHit_x = next_x;
			horzHit_y = next_y;
			horzContent = data->map_info.map_wt[(int)floor(x_toCheck / data->map_info.square_S)][(int)floor(y_toCheck / data->map_info.square_S)];
			foundHorz_hit = 1;
			break;
		}
		else
		{
			next_x += x_step;
			next_y += y_step;
		}
	}

	// ==================
	// CHECK VERT HITS
	// ==================

	// vert_inter();
	int foundVert_hit = 0;
	double vertHit_x = 0;
	double vertHit_y = 0;
	int	vertContent = 0;

	x_inter = floor(data->ray.player_y / data->map_info.square_S) * data->map_info.square_S;
	x_inter += isFace_Down ? data->map_info.square_S : 0;

	y_inter = data->ray.player_x + (y_inter - data->ray.player_y) * tan(ray_angle);

	//calculate the xstep and ystep
	y_step = data->map_info.square_S;
	y_step *= isFace_Up ? -1 : 1;

	x_step = data->map_info.square_S * tan(ray_angle);
	x_step *= (isFace_Left && y_step > 0) ? -1 : 1;
	x_step *= (isFace_Right && y_step < 0) ? -1 : 1;

	double next_x = x_inter;
	double next_y = y_inter;

	//increment xstep and ystep until find a wall hit
	while (next_x >= 0 && next_x <= WIDTH && next_y >= 0 && next_y <= HEIGHT)
	{
		double x_toCheck = next_x;
		double y_toCheck = next_y + (isFace_Up ? -1 : 0);

		if (is_wall(x_toCheck, y_toCheck))
		{
			vertHit_x = next_x;
			vertHit_y = next_y;
			vertContent = data->map_info.map_wt[(int)floor(x_toCheck / data->map_info.square_S)][(int)floor(y_toCheck / data->map_info.square_S)];
			foundVert_hit = 1;
			break;
		}
		else
		{
			next_x += x_step;
			next_y += y_step;
		}
	}

	// calculate_dis();
	//calculate both horz and vert hit distances and choose the smallest one
	double horzHit_dist = foundHorz_hit ? dist_two_points(data->ray.player_size, data->ray.player_y, horzHit_x, horzHit_y)
										: INT_MAX;
	double vertHit_dist = foundVert_hit ? dist_two_points(data->ray.player_size, data->ray.player_y, vertHit_x, vertHit_y)
										: INT_MAX;
	if (vertHit_dist < horzHit_dist)
	{
		data->ray.distance = vertHit_dist;
		data->ray.wallHit_x = vertHit_x;
		data->ray.wallHit_y = vertHit_y;
		data->ray.wallHit_content = vertContent;
		data->ray.wasHitVertical = 1;
	}
	else
	{
		data->ray.distance = horzHit_dist;
		data->ray.wallHit_x = horzHit_x;
		data->ray.wallHit_y = horzHit_y;
		data->ray.wallHit_content = horzContent;
		data->ray.wasHitVertical = 0;
	}

	// already add in the cast_ray function
	data->ray.rayAngle = ray_angle;
	data->ray.is_FaceDown = isFace_Down;
	data->ray.is_FaceUp = isFace_Up;
	data->ray.is_FaceRight = isFace_Left;
	data->ray.is_FaceRight = isFace_Right;
}

void	castAll_rays(t_data *data)
{
    int 	i = 0;
    double	ray_angle = data->r_angle - (FOV_ANGLE / 2);

    while (i < WIDTH)
    {
        cast_ray(data, ray_angle, i);
        ray_angle += FOV_ANGLE / WIDTH;
        i++;
    }
}
