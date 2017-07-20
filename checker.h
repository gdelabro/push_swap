/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:55:06 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/24 19:40:16 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_printf/ft_printf.h"

typedef struct		s_ps
{
	int				*p_a;
	int				*p_b;
	int				*p_t;
	int				*p_tmp;
	int				t_a;
	int				t_b;
	int				t_t;
	int				a;
	int				b;
	int				t;
	int				v;
	int				aff;
}					t_ps;

int					ft_quit(void);
void				check_valid(char **str, t_ps *e);
void				aff_pile(t_ps *e, char *line);
void				test(t_ps *e);
int					test_tri(t_ps *e);
void				op_ss(t_ps *e);
void				op_sb(t_ps *e);
void				op_sa(t_ps *e);
void				op_pa(t_ps *e);
void				op_pb(t_ps *e);
void				op_ra(t_ps *e);
void				op_rb(t_ps *e);
void				op_rr(t_ps *e);
void				op_rra(t_ps *e);
void				op_rrb(t_ps *e);
void				op_rrr(t_ps *e);

#endif
