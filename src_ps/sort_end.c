/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:09:07 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/30 15:17:34 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_end2(t_ps *e, int i)
{
	while (e->p_a[e->t_a - 1] != e->p_t[e->t_t - 1])
	{
		if (i < e->t_a / 2)
			op_ra(e);
		else
			op_rra(e);
	}
}

void	sort_end(t_ps *e)
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
	sort ? sort_end2(e, i) : 0;
}
