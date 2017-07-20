/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:22:55 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/24 19:55:10 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	op_pa(t_ps *e)
{
	int i;

	if (!e->t_b)
		return ;
	++e->t_a;
	i = e->t_a;
	while (--i)
		e->p_a[i] = e->p_a[i - 1];
	e->p_a[0] = e->p_b[0];
	i = 0;
	while (++i < e->t_b)
		e->p_b[i - 1] = e->p_b[i];
	--e->t_b;
}

void	op_pb(t_ps *e)
{
	int i;

	if (!e->t_a)
		return ;
	++e->t_b;
	i = e->t_b;
	while (--i)
		e->p_b[i] = e->p_b[i - 1];
	e->p_b[0] = e->p_a[0];
	i = 0;
	while (++i < e->t_a)
		e->p_a[i - 1] = e->p_a[i];
	--e->t_a;
}
