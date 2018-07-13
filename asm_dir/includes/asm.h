/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 04:01:26 by fdidelot          #+#    #+#             */
/*   Updated: 2018/05/02 07:27:46 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"

# define MEM_SIZE			(4 * 1024)
# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)
# define COMMENT_CHAR		'#'
# define LABEL_CHAR			':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','
# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"
# define REG_NUMBER			16
# define MAX_ARG_TYPE		3
# define T_REG				1
# define T_DIR				2
# define T_IND				4
# define IND				192
# define REG				64
# define _DIR				128
# define MAGIC_NUMBER		0xea83f3

typedef	char		t_arg_type;

typedef struct		s_pukutak
{
	int				size_dir;
	int				deca;
}					t_pukutak;

typedef struct		s_label
{
	int				placement;
	int				deca;
	int				dir_size;
	char			*name;
	struct s_label	*next;
}					t_label;

typedef struct		s_offset
{
	unsigned int	index_str;
	unsigned int	offset;
	unsigned int	trileen;
	unsigned int	next_separator;
	unsigned int	size_ope;
}					t_offset;

typedef struct		s_op
{
	char			*name;
	int				nb_param;
	t_arg_type		arg_type[MAX_ARG_TYPE];
	int				opcode;
	int				nb_cycle;
	char			*comment;
	int				octal;
	int				dir_size;
}					t_op;

extern t_op			g_op_tab[17];

typedef struct		s_env
{
	int				size_player;
	int				valid_line;
	char			*name_file;
	char			*stock;
	unsigned char	*player_buff;
	int				off_set;
	int				count;
	char			*name_player;
	char			*comment;
	int				name_ok;
	int				comment_ok;
	t_label			*lst_label;
	t_label			*stock_label;
}					t_env;

void				get_args_ind(t_env *e, unsigned char *str, t_offset *t_off);
void				get_args_reg(t_env *e, unsigned char *str, t_offset *t_off);
void				get_args_dir(t_env *e, unsigned char *str, t_offset *t_off,
								int dir_size);
int					mini_reg(t_env *e, int *start);
int					lfork_operator(t_env *e, int start, int sl);
int					fork_operator(t_env *e, int start, int sl);
int					zjmp_operator(t_env *e, int start, int sl);
int					operator_all(t_env *e, int start, unsigned char opcode,
								int sl);
int					ft_create_cor(t_env *e);
int					replace_label(t_env *e);
int					skip_label(t_env *e, int sl);
int					valid_command(t_env *e, int sl, int i);
int					check_line(t_env *e, int sl);
int					name(t_env *e);
int					comment(t_env *e);
int					size_line(char *stock, int count);
int					skip_space(char *str);
int					skip_empty_and_com(char *str);
int					check_nb_param(t_env *e, int start, int sl, int n_op);
int					live_operator(t_env *e, int start, int sl);
int					valid_param(t_env *e, int start, int n_op);
int					check_reg(t_env *e, int start);
int					check_dir(t_env *e, int start);
int					check_ind(t_env *e, int start);
void				add_command(t_env *e, unsigned char *command, int size);
void				number_to_hex_size_two(unsigned int num,
										unsigned char *dest);
void				number_to_hex(unsigned int num, unsigned char *dest);
void				get_label(t_env *e, int start, int deca, int dir_size);
void				create_label_lst(t_env *e, int start, int end);
void				menu_args_coding_byte(t_env *e, int start,
										unsigned char opcode);
void				create_label_stock(t_env *e, int start, int end,
									t_pukutak puku);
void				ft_clean_env(t_env *e);
void				replace_valid(t_env *e);
int					valid_player(t_env *e);
int					replace_label(t_env *e);
#endif
