/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:53:49 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/24 19:55:17 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	op_rra(t_ps *e)
{
	int i;
	int tmp;

	if (e->t_a <= 1)
		return ;
	tmp = e->p_a[e->t_a - 1];
	i = e->t_a;
	while (--i > 0)
		e->p_a[i] = e->p_a[i - 1];
	e->p_a[0] = tmp;
}

void	op_rrb(t_ps *e)
{
	int i;
	int tmp;

	if (e->t_b <= 1)
		return ;
	tmp = e->p_b[e->t_b - 1];
	i = e->t_b;
	while (--i > 0)
		e->p_b[i] = e->p_b[i - 1];
	e->p_b[0] = tmp;
}

void	op_rrr(t_ps *e)
{
	e->aff = 1;
	op_rra(e);
	op_rrb(e);
	e->aff = 0;
}
