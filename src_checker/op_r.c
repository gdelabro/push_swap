/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:37:45 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/24 19:55:13 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	op_ra(t_ps *e)
{
	int i;
	int tmp;

	if (!e->t_a)
		return ;
	tmp = e->p_a[0];
	i = -1;
	while (++i < e->t_a - 1)
		e->p_a[i] = e->p_a[i + 1];
	e->p_a[e->t_a - 1] = tmp;
}

void	op_rb(t_ps *e)
{
	int i;
	int tmp;

	if (!e->t_b)
		return ;
	tmp = e->p_b[0];
	i = -1;
	while (++i < e->t_b - 1)
		e->p_b[i] = e->p_b[i + 1];
	e->p_b[e->t_b - 1] = tmp;
}

void	op_rr(t_ps *e)
{
	e->aff = 1;
	op_ra(e);
	op_rb(e);
	e->aff = 0;
}
