/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:11:58 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/30 15:34:14 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	aff_pile2(t_ps *e, char *line)
{
	static int	c = -1;
	int			i;
	int			i2;

	ft_putstr("\033[H\033[J");
	i = e->t_t;
	i2 = -1;
	e->a = -1;
	e->b = -1;
	e->t = -1;
	while (++i2 < i)
	{
		i - i2 <= e->t_a ? ft_printf("{green}[%11d] ", e->p_a[++e->a])
			: ft_printf("%14s", "");
		i - i2 <= e->t_b ? ft_printf("{red}[%11d] ", e->p_b[++e->b])
			: ft_printf("%14s", "");
		ft_printf("{yellow}[%11d]", e->p_t[++e->t]);
		ft_putendl("");
	}
	ft_printf("   {green}%-13s {red}%-11s {yellow}%s\ncoup: %d\n\
operation: %s\n", "Stack a", "Stack b", "Stack triée", ++c, line);
}

void	aff_pile(t_ps *e, char *line)
{
	e->v ? aff_pile2(e, line) : 0;
}
