/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:10:36 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/24 17:42:44 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_sa(t_ps *e)
{
	int tmp;

	if (e->t_a < 2)
		return ;
	tmp = e->p_a[0];
	e->p_a[0] = e->p_a[1];
	e->p_a[1] = tmp;
	!e->aff ? ft_putendl("sa") : 0;
}

void	op_sb(t_ps *e)
{
	int tmp;

	if (e->t_b < 2)
		return ;
	tmp = e->p_b[0];
	e->p_b[0] = e->p_b[1];
	e->p_b[1] = tmp;
	!e->aff ? ft_putendl("sb") : 0;
}

void	op_ss(t_ps *e)
{
	e->aff = 1;
	op_sa(e);
	op_sb(e);
	e->aff = 0;
	ft_putendl("ss");
}
