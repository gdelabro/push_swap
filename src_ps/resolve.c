/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 20:02:56 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/30 15:33:25 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		test_small(t_ps *e)
{
	if (e->t_a == 3 && e->p_a[0] > e->p_a[1] && e->p_a[1] > e->p_a[2])
	{
		op_sa(e);
		op_rra(e);
		return (1);
	}
	return (0);
}

int		is_there_lower(t_ps *e, int median)
{
	int i;

	i = -1;
	while (++i < e->t_a)
		if (e->p_a[i] < median)
			return (1);
	return (0);
}

void	sort_half(t_ps *e)
{
	int		index;
	int		median;
	float	med;

	index = e->t_a + 1;
	med = ((1.0 / 63) * e->t_a + 5.0 / 2.3) + 0.5;
	median = e->p_t[(int)(e->t_a / med) + e->t_b];
	while (--index && !tri_end(e))
	{
		if (e->p_a[0] >= median)
			op_ra(e);
		else if (is_there_lower(e, median))
			op_pb(e);
	}
}

int		tri_end(t_ps *e)
{
	int i;
	int i2;

	sort_end(e);
	i = e->t_a;
	i2 = e->t_t;
	while (i)
	{
		--i;
		--i2;
		if (e->p_a[i] != e->p_t[i2])
			return (0);
	}
	return (1);
}

void	resolve(t_ps *e)
{
	if (test_tri(e) || test_small(e))
		return ;
	if (e->t_t > 10)
	{
		while (!tri_end(e))
			sort_half(e);
		sort_reverse(e);
	}
	else
		little_sort(e);
}
