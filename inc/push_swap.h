/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:06:15 by mnegro            #+#    #+#             */
/*   Updated: 2023/04/21 18:41:18 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* HEADER FILES */
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* MACROS */
# define FT_ATOI_ERROR -2147483649

/* STRUCTURES */
typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}			t_stack;

typedef struct s_vals
{
	int	size_a;
	int	min_a;
	int	max_a;
	int	size_b;
	int	min_b;
	int	max_b;
}			t_vals;

/* PROTOTYPES */
/* ft_algoApplies.c */
void		ft_apply_combo_ab(int nbr, t_stack **stack_a, t_stack **stack_b,
				t_vals *vals);
void		ft_apply_combo_ba(int nbr, t_stack **stack_b, t_stack **stack_a,
				t_vals *vals);
/* ft_algoCombos.c */
int			ft_combo_ab(int nbr, t_stack *stack_a, t_stack *stack_b,
				t_vals *vals);
int			ft_combo_ba(int nbr, t_stack *stack_b, t_stack *stack_a,
				t_vals *vals);
/* ft_algoFinds.c */
int			ft_findidx(int nbr, t_stack *stack);
int			ft_finddst_ab(int nbr, t_stack *stack_b, t_vals *vals);
int			ft_finddst_ba(int nbr, t_stack *stack_a, t_vals *vals);
int			ft_findmin(t_stack *stack);
int			ft_findmax(t_stack *stack);
/* ft_algoLimits.c*/
void		ft_newmax_ab(t_stack **stack_a, t_stack **stack_b, t_vals *vals);
void		ft_newmin_ab(t_stack **stack_a, t_stack **stack_b, t_vals *vals);
void		ft_newmax_ba(t_stack **stack_b, t_stack **stack_a, t_vals *vals);
void		ft_newmin_ba(t_stack **stack_b, t_stack **stack_a, t_vals *vals);
/* ft_algoMovesAB.c */
int			ft_apply_r_ab(int nbr, t_stack **stack_a, t_stack **stack_b,
				t_vals *vals);
int			ft_apply_rr_ab(int nbr, t_stack **stack_a, t_stack **stack_b,
				t_vals *vals);
int			ft_apply_rrarb_ab(int nbr, t_stack **stack_a, t_stack **stack_b,
				t_vals *vals);
int			ft_apply_rrbra_ab(int nbr, t_stack **stack_a, t_stack **stack_b,
				t_vals *vals);
/* ft_algoMovesBA.c */
int			ft_apply_r_ba(int nbr, t_stack **stack_a, t_stack **stack_b,
				t_vals *vals);
int			ft_apply_rr_ba(int nbr, t_stack **stack_a, t_stack **stack_b,
				t_vals *vals);
int			ft_apply_rrarb_ba(int nbr, t_stack **stack_a, t_stack **stack_b,
				t_vals *vals);
int			ft_apply_rrbra_ba(int nbr, t_stack **stack_a, t_stack **stack_b,
				t_vals *vals);
/* ft_algoOpsAB.c */
int			ft_ops_r_ab(int nbr, t_stack *stack_a, t_stack *stack_b,
				t_vals *vals);
int			ft_ops_rr_ab(int nbr, t_stack *stack_a, t_stack *stack_b,
				t_vals *vals);
int			ft_ops_rrarb_ab(int nbr, t_stack *stack_a, t_stack *stack_b,
				t_vals *vals);
int			ft_ops_rrbra_ab(int nbr, t_stack *stack_a, t_stack *stack_b,
				t_vals *vals);
/* ft_algoOpsBA.c */
int			ft_ops_r_ba(int nbr, t_stack *stack_a, t_stack *stack_b,
				t_vals *vals);
int			ft_ops_rr_ba(int nbr, t_stack *stack_a, t_stack *stack_b,
				t_vals *vals);
int			ft_ops_rrarb_ba(int nbr, t_stack *stack_a, t_stack *stack_b,
				t_vals *vals);
int			ft_ops_rrbra_ba(int nbr, t_stack *stack_a, t_stack *stack_b,
				t_vals *vals);
/* ft_algoTurk.c */
void		ft_pushtwo(t_stack **stack_a, t_stack **stack_b, t_vals *vals);
void		ft_sortboth(t_stack **stack_a, t_stack **stack_b, t_vals *vals);
void		ft_turk(t_stack **stack_a, t_stack **stack_b);
/* ft_minorSorts.c */
void		ft_sort_three(t_stack **stack);
void		ft_sort_four(long int *ints, int size,
				t_stack **stack1, t_stack **stack2);
void		ft_sort_five(long int *ints, int size,
				t_stack **stack1, t_stack **stack2);
/* ft_miscUtils.c */
void		*ft_free(void **intptr);
void		ft_resetabc(t_stack *stack, int *a, int *b, int *c);
long int	ft_ps_atoi(const char *nptr);
void		ft_sortarr(long int *arr, int size);
void		ft_updatevals(t_stack *stack_a, t_stack *stack_b, t_vals *vals,
				char c);
/* ft_preChecks.c */
long int	*ft_conversion(int argc, char **argv);
long int	ft_check4dups(long int *ints, int size);
long int	ft_check4limits(long int *ints, int size);
long int	*ft_checkchecks(int *argc, char **argv);
/* ft_singleArgv.c */
int			ft_findspace(char *str);
int			ft_mtxlen(char **matrix);
void		ft_freematrix(char **matrix);
long int	*ft_conversion_sa(int argc, char **argv);
/* ft_stackMoves.c */
void		ft_swap(t_stack *stack, char c);
void		ft_push(t_stack **stackfrom, t_stack **stackto, char c);
void		ft_rotate(t_stack **stack, char c);
void		ft_reverserotate(t_stack **stack, char c);
/* ft_stackMoves2X.c */
void		ft_ss(t_stack *stack_a, t_stack *stack_b);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);
/* ft_stackOps1.c */
t_stack		*ft_stacknew(int nbr);
void		ft_stackaddback(t_stack **stack, t_stack *newnode);
t_stack		*ft_stacklast(t_stack *stack);
t_stack		*ft_stackcreate(long int *intptr, int size);
void		ft_stackfree(t_stack **stack);
/* ft_stackOps2.c */
void		ft_stackprint(t_stack *stack);
int			ft_stacksorted(t_stack *stack);
int			ft_instack(t_stack *stack, int val);
int			ft_stacksize(t_stack *stack);
/* main.c */
int			main(int argc, char **argv);
void		ft_operations(int argc, long int *ints, t_stack **stack_a);

#endif
