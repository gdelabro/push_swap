/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:40:46 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/24 19:55:24 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	test(t_ps *e)
{
	char *line;

	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp("ra", line) || !ft_strcmp("rb", line))
			!ft_strcmp("ra", line) ? op_ra(e) : op_rb(e);
		else if (!ft_strcmp("rr", line) || !ft_strcmp("rra", line))
			!ft_strcmp("rr", line) ? op_rr(e) : op_rra(e);
		else if (!ft_strcmp("rrb", line) || !ft_strcmp("rrr", line))
			!ft_strcmp("rrb", line) ? op_rrb(e) : op_rrr(e);
		else if (!ft_strcmp("sa", line) || !ft_strcmp("sb", line))
			!ft_strcmp("sa", line) ? op_sa(e) : op_sb(e);
		else if (!ft_strcmp("ss", line))
			op_ss(e);
		else if (!ft_strcmp("pa", line) || !ft_strcmp("pb", line))
			!ft_strcmp("pa", line) ? op_pa(e) : op_pb(e);
		else
			ft_quit();
		aff_pile(e, line);
		ft_strdel(&line);
	}
	if (test_tri(e))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}
