/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:56:55 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/24 19:55:04 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int		ft_quit(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	init_pile_t(t_ps *e)
{
	int i;
	int i2;
	int tmp;

	i = -1;
	while (++i < e->t_t && (i2 = i) != -1)
		while (++i2 < e->t_t)
			if (e->p_t[i] > e->p_t[i2])
			{
				tmp = e->p_t[i];
				e->p_t[i] = e->p_t[i2];
				e->p_t[i2] = tmp;
			}
}

int		test_tri(t_ps *e)
{
	int i;

	i = -1;
	if (e->t_a != e->t_t)
		return (0);
	while (++i < e->t_t)
		if (e->p_a[i] != e->p_t[i])
			return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_ps	e;

	if (ac <= 1)
		ft_quit();
	++av;
	e.v = 0;
	e.aff = 0;
	check_valid(av, &e);
	init_pile_t(&e);
	aff_pile(&e, "init");
	test(&e);
}
