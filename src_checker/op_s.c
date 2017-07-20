/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:10:36 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/24 19:55:20 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	op_sa(t_ps *e)
{
	int tmp;

	if (e->t_a < 2)
		return ;
	tmp = e->p_a[0];
	e->p_a[0] = e->p_a[1];
	e->p_a[1] = tmp;
}

void	op_sb(t_ps *e)
{
	int tmp;

	if (e->t_b < 2)
		return ;
	tmp = e->p_b[0];
	e->p_b[0] = e->p_b[1];
	e->p_b[1] = tmp;
}

void	op_ss(t_ps *e)
{
	e->aff = 1;
	op_sa(e);
	op_sb(e);
	e->aff = 0;
}
