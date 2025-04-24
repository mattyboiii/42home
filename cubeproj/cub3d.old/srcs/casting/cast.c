/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:09:12 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/24 13:37:57 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

static float	get_diff(t_ray *ray, t_intsct *intsct)
{
	if (ray->pos.x == intsct->pos.x)
		return (fabsf(ray->pos.y - intsct->pos.y));
	return (fabsf(ray->pos.x - intsct->pos.x));
}

/**
 * cast ray casts the set amount of rays from a set ange starting left to right.
 * in our case it is a 0degree angle and will cast 960 rays till it hits 90degree
 */
t_intsct	*cast_ray(t_ray *ray, t_vector *bounds)
{
	t_intsct	*closest;
	t_intsct	*new;
	size_t		i;
	float		best_diff;
	float		diff;

	best_diff = INFINITY;
	closest = 0;
	i = 0;
	while (i < bounds->length)
	{
		new = get_intersection(ray, ft_vecindex(bounds, i++));
		if (!new)
			continue ;
		diff = get_diff(ray, new);
		if (diff < best_diff)
		{
			best_diff = diff;
			free(closest);
			closest = new;
		}
		else
			free(new);
	}
	return (closest);
}

/**
 * this function will set the PERCENTAGE the players first distance is.
 * Not the linar distance from the camera to the interection. Its the
 * view plain distance. Multiply the linar distance with the co sign of the differance in angle.
 *
 * the angle of intersection and the facing direction angle.
 *
 * CHECK LATER
 *
 * this uses the vfov. whcih is calculated based on the fov set in the config file.
 */
static void	set_intsct_height(t_intsct *intsct, t_cast *cast)
{
	float	distance;

	distance = hypotf(cast->pos.x - intsct->pos.x, cast->pos.y - intsct->pos.y)
		* cosf(fmodf(cast->dir - intsct->angle + M_PI * 2, M_PI * 2));
	intsct->height = 2 * atan2f(1, 2 * distance) / cast->vfov;
}

t_vector	*cast_rays(t_vector *rays, t_cast *cast)
{
	t_vector	*closest_intscts;
	t_intsct	*closest;
	size_t		i;

	closest_intscts = ft_vecnew_with_capacity(rays->length, sizeof(t_intsct));
	i = 0;
	while (i < rays->length)
	{
		closest = cast_ray(ft_vecindex(rays, i++), cast->bounds);
		if (closest)
		{
			set_intsct_height(closest, cast);
			ft_vecpush_consume(closest_intscts, closest);
		}
	}
	return (closest_intscts);
}

t_vector	*cast(t_cast *cast)
{
	t_vector	*rays;
	t_vector	*out;

	rays = get_rays(cast);
	out = cast_rays(rays, cast);
	ft_vecfree(&rays, 0);
	return (out);
}
