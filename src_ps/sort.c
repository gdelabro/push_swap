/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:16:59 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/24 19:00:51 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	opti(t_ps *e, int *i)
{
	*i = -1;
	while (e->p_b[++(*i)] != e->p_t[e->nb])
		;
	if (e->t_b > 1 && e->p_b[0] == e->p_t[e->nb - 1]
			&& (e->o = 1) && --(*i) != -1)
		op_pa(e);
	if (e->o && e->t_b > 2 && *i > 3 && e->t_b - *i > 3 &&
			e->p_b[0] == e->p_t[e->nb - 2] && (e->o = 2) && --(*i) != -1)
		op_pa(e);
}

void	find_next(t_ps *e)
{
	int i;

	opti(e, &i);
	if (e->p_b[0] == e->p_t[e->nb] && --e->nb != -2)
	{
		if (e->o == 2)
		{
			op_pb(e);
			op_rb(e);
		}
		e->o = 0;
		op_pa(e);
	}
	else if (i > e->t_b / 2)
		op_rrb(e);
	else
		op_rb(e);
	if (e->t_a > 1 && e->p_a[0] > e->p_a[1] && --e->nb != -2)
		op_sa(e);
}

void	sort_reverse(t_ps *e)
{
	e->nb = e->t_t - e->t_a - 1;
	e->o = 0;
	while (e->t_b)
		find_next(e);
}
