/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:22:47 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/28 18:03:53 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int		valid_str(char *str, int index, t_ps *e)
{
	int i;
	int neg;
	int nb;

	i = -1;
	neg = 0;
	nb = 0;
	ft_strlen(str) == 10 && ft_strcmp(str, "2147483647") > 0 ? ft_quit() : 0;
	ft_strlen(str) == 11 && ft_strcmp(str, "-2147483648") > 0 ? ft_quit() : 0;
	ft_strlen(str) >= 12 || (ft_strlen(str) == 11 && str[0] != '-')
		? ft_quit() : 0;
	while (str[++i])
	{
		if ((str[i] == '-' && !i) || (str[i] <= '9' && str[i] >= '0'))
			str[i] == '-' ? neg = 1 : (nb *= 10);
		else
			return (0);
		str[i] != '-' ? nb += str[i] - 48 : 0;
	}
	neg ? nb *= -1 : 0;
	e->p_a[index] = nb;
	e->p_t[index] = nb;
	!ft_strcmp(str, "-2147483648") ? e->p_a[i] = -2147483648 : 0;
	return (1);
}

void	remp_struct(char **tab, t_ps *e)
{
	int i;

	i = taille_tab(tab);
	!i ? ft_quit() : 0;
	!(e->p_a = (int*)malloc(sizeof(int) * i)) ? ft_quit() : 0;
	!(e->p_b = (int*)malloc(sizeof(int) * i)) ? ft_quit() : 0;
	!(e->p_t = (int*)malloc(sizeof(int) * i)) ? ft_quit() : 0;
	!(e->p_tmp = (int*)malloc(sizeof(int) * i)) ? ft_quit() : 0;
	e->t_a = i;
	e->t_t = i;
	e->t_b = 0;
	i = -1;
	while (tab[++i])
	{
		!valid_str(tab[i], i, e) ? ft_quit() : 0;
		ft_strdel(&tab[i]);
	}
	free(tab);
}

void	check_valid2(char **str, t_ps *e)
{
	char	**tab;
	int		i;
	int		i2;

	i = -1;
	taille_tab(str) == 1 ? tab = ft_strsplit(str[0], ' ')
		: (tab = cpy_tab(str));
	if (tab == NULL)
		exit(0);
	remp_struct(tab, e);
	while (++i < e->t_a && (i2 = -1))
		while (++i2 < i)
			if (e->p_a[i] == e->p_a[i2])
				ft_quit();
}

void	check_valid(char **av, t_ps *e)
{
	if (!ft_strcmp(av[0], "-v"))
	{
		++av;
		e->v = 1;
	}
	check_valid2(av, e);
}
