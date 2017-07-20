/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 15:46:30 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/28 18:06:04 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		test_follow(t_ps *e)
{
	int i;

	i = -1;
	while (++i < e->t_t && e->p_a[0] != e->p_t[i])
		;
	if (i && e->p_a[1] == e->p_t[i - 1])
		return (1);
	return (0);
}

void	resort(t_ps *e, int i)
{
	if (i < e->t_a / 2)
		while (!tri_end(e))
			op_rra(e);
	else
		while (!tri_end(e))
			op_ra(e);
}

void	push_next2(t_ps *e, int i, int sort)
{
	int i2;

	i2 = -1;
	if (sort)
		return (resort(e, i));
	while (++i2 < e->t_a)
	{
		if (!i2 && e->p_a[0] <= e->p_a[i])
		{
			op_pb(e);
			break ;
		}
		else if (e->p_a[i2] <= e->p_a[i])
		{
			op_ra(e);
			break ;
		}
		else if (e->p_a[e->t_a - 1 - i2] <= e->p_a[i])
		{
			op_rra(e);
			break ;
		}
	}
}

void	push_next(t_ps *e)
{
	int i;
	int i2;
	int sort;

	sort = 0;
	i2 = 1;
	i = -1;
	while (e->p_a[++i] != e->p_t[e->t_t - 1])
		;
	while (e->p_a[i] == e->p_t[e->t_t - i2])
	{
		i = (i + e->t_a - 1) % e->t_a;
		++i2;
		if (e->p_a[i] == e->p_t[e->t_t - 1])
		{
			sort = 1;
			i = i + 1 % e->t_a;
			break ;
		}
	}
	push_next2(e, i, sort);
}

void	little_sort(t_ps *e)
{
	int i;

	i = -1;
	while (!tri_end(e))
	{
		if (test_follow(e))
			op_sa(e);
		else
			push_next(e);
	}
	sort_reverse(e);
}
