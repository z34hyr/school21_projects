/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:03:34 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/25 00:51:53 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_conv
{
	int				cf_space;
	int				cf_plus;
	int				cf_minus;
	int				cf_sharp;
	int				cf_zero;
	int				cf_dot;
	int				c_width;
	int				flag_ast;
	int				c_precision;
	int				prec_width;
	char			cs;
}					t_conv;

int					ft_strlen(char *string);
int					ft_printf(const char *string, ...);
int					is_digit(char symb);
int					is_conv_flag(char symb);
int					is_conv_spec(char symb);
char				*fill_conv_line(char *dst,
									const char *src,
									int start,
									int length);
int					ft_conv_handler(const char *string,
											int *i,
											int *counter,
											va_list a);
int					get_conv_line(char **dst, const char *string, int *i);
t_conv				*ft_conv_new(char *conv_line);
void				conv_flags_sifter(t_conv *conv_struct,
										char *conv_line,
										int *i);
void				get_width(t_conv *conv_struct,
								char *conv_line,
								int *i,
								va_list a);
void				get_precision(t_conv *conv_struct,
									char *conv_line,
									int *i,
									va_list a);
int					fill_conv_struct(char *conv_line,
									t_conv **conv_struc,
									va_list a);
void				to_flag_func(t_conv *conv_struc, va_list a, int *counter);
int					filler_line(char **dst, int len, char c);
int					prec_line_i_d_u(char *str,
									char **prec_str,
									t_conv *conv_struc);
int					prec_line_s(char *str, t_conv *conv_struc);
int					space_line(char *str,
								char **space_str,
								t_conv *conv_struc,
								int n_prec);
int					space_line_s(char **space_str,
								t_conv *conv_struc,
								int n_prec);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
void				*ft_memset(void *s, int c, size_t n);
int					ft_atoi(const char *nptr, int *i);
int					flag_d_i(t_conv *conv_struc, va_list a);
int					flag_u(t_conv *conv_struc, va_list a);
int					flag_x(t_conv *conv_struc, va_list a);
int					flag_p(t_conv *conv_struc, va_list a);
int					flag_c(t_conv *conv_struc, va_list a);
int					flag_s(t_conv *conv_struc, va_list a);
int					flag_percent(void);
void				flag_n(int n_write, va_list a);
int					print_d_i_u_x(char *pr_str,
									char *sp_str,
									char *str,
									t_conv *cnv_st);
int					print_s(int n_prec, char *space_str, char *str, int minus);
unsigned long int	ft_div_16(unsigned long int num, char conv_case);
int					ft_copy_backward(char **dst, char *src);
char				*hex_line(t_conv *conv_struc, va_list a);
void				free_flags_str(char *prec_str, char *space_str);
void				free_by_err(char *prec_str, char *space_str, int *n_write);
void				free_before_exit(char *str);
void				flag_n(int n_write, va_list a);
#endif
