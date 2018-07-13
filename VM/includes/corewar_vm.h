/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 05:54:02 by gquerre           #+#    #+#             */
/*   Updated: 2018/05/02 06:47:47 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H
# define COREWAR_VM_H
# include <ncurses.h>
# include <curses.h>
# include <term.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>
# include <math.h>
# include "../SRC/libft/SRC/libft.h"

# define WIDTH_DUMP				64
# define COMMENT_SIZE			2048
# define NAME_SIZE				128
# define MEM_SIZE				(4 * 1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define REG_NUMBER				16
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define INT_SIZE				4
# define FREQ					500000

/*
** ENVIRONMENT
*/

# define BAD_CODING_BYTE		666
# define REG_INVALID			667
# define MAX_PLAYERS			4
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10
# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8
# define MAX_ARG_TYPE			3
# define NAME_LENGTH			128
# define COMMENT_LENGTH			2048
# define MAGIC_NB				0xea83f3

typedef	char	t_arg_type;

/*
** PROCESS
*/

typedef struct					s_process
{
	int							pc;
	unsigned int				reg[REG_NUMBER];
	int							waiting;
	int							lives_during_periode;
	struct s_process			*next;
	int							carry;
	int							to_exec;
	int							opcode;
	unsigned int				from_pl;
}								t_process;

/*
** OPS
*/

typedef struct					s_params
{
	int							nb_params_max;
	int							num_param;
	unsigned char				coding_byte;
	int							total_size;
	unsigned char				opcode;
	int							arg_type;
	int							bad_byte;
}								t_params;

typedef struct					s_args_value
{
	unsigned char				reg;
	unsigned int				dir;
	unsigned short				ind;
	unsigned short				dir_short;
	char						type;
}								t_args_value;

/*
** VISU
*/

typedef struct					s_visu
{
	int							root;
	int							border;
	int							mx;
	int							my;
	WINDOW						*arena;
	WINDOW						*info;
	int							color;
	int							speed;
}								t_visu;

/*
** PLAYERS
*/

typedef struct					s_player
{
	int							num_player;
	unsigned int				id;
	unsigned int				lives_periode;
	unsigned int				total_lives;
	unsigned int				last_live;
	unsigned int				very_last_flag;
	char						*name;
	char						*comment;
	int							size;
}								t_player;

/*
** ENVIRONMENT
*/

typedef struct					s_env
{
	int							nb_of_pl;
	int							visu;
	t_visu						*vi;
	t_process					*pc_list;
	unsigned char				*arena;
	unsigned char				*written_by;
	t_player					*players;
	int							cycles_to_die;
	int							cycles;
	int							cycles_periode;
	int							checks_done;
	unsigned int				lives_periode;
	char						*winner_name;
	int							winner_value;
	int							winner_num_player;
	int							option;
	int							dump_on;
	unsigned int				very_last_flag;
	int							winner_flag;
	unsigned int				forced_nb_for_pl;
}								t_env;

typedef struct					s_op_info
{
	void						(*op)(t_env *, t_process *,
								t_args_value args[3]);
	char						*name;
	int							nb_param;
	t_arg_type					arg_type[MAX_ARG_TYPE];
	int							opcode;
	int							nb_cycle;
	char						*comment;
	int							octal;
	int							dir_size;
}								t_op_info;

extern	t_op_info				g_op_tab[17];

/*
**	FUNCTIONS
*/

int								ft_print_hexa(unsigned char oct);
int								ft_comp_with_pl(t_env *e, t_process *pro);
int								ft_create_arena(t_env *e);
int								ft_how_many_pl(t_env *e, int argc, char **argv);
int								ft_init_player(t_env *e, char *argv);
int								ft_init_process(t_env *e);
int								ft_error(t_env *e, int i);
int								ft_finish(t_env *e, int i);
int								ft_game_runner(t_env *e);
int								ft_play_turn(t_env *e);
int								ft_options(t_env *e, char *argv);
int								ft_apply_option(t_env *e, char *argv, int i);
int								ft_dump(t_env *e);
int								ft_add_pc(t_env *e, t_process *father, short i);
int								read_nb_bytes(t_env *e, int arg_size,
								t_process *pc, int offset);
void							write_2_bytes(t_env *e, unsigned short input,
								t_process *pc, unsigned int offset);
void							write_4_bytes(t_env *e, int input,
								t_process *pc, unsigned int offset);
void							fonction_lancement_op(t_env *e, t_process *pc);
int								ft_operations(t_env *e, t_process *process);
void							dec_to_bin(int dec, unsigned char *bin_num,
								int index, int size);
unsigned int					bin_to_dec(int size, unsigned char *number,
								unsigned int array_size);
void							init_t_args(t_args_value args[3]);
void							init_t_params(t_params *params);
int								get_args_value(t_args_value args[3],
								t_process *pc, t_env *e, t_params *p);
short							ft_arg_neg_two(unsigned short nb, int mod);
int								ft_arg_neg_three(unsigned int nb, int mod);

/*
** OP PROTOTYPES
*/

void							live(t_env *e, t_process *pc,
									t_args_value args[3]);
void							ld(t_env *e, t_process *process,
									t_args_value args[3]);
void							st(t_env *e, t_process *process,
									t_args_value args[3]);
void							add(t_env *e, t_process *process,
									t_args_value args[3]);
void							sub(t_env *e, t_process *process,
									t_args_value args[3]);
void							c_and(t_env *e, t_process *process,
									t_args_value args[3]);
void							c_or(t_env *e, t_process *process,
									t_args_value args[3]);
void							c_xor(t_env *e, t_process *process,
									t_args_value args[3]);
void							zjmp(t_env *e, t_process *process,
									t_args_value args[3]);
void							ldi(t_env *e, t_process *process,
									t_args_value args[3]);
void							sti(t_env *e, t_process *process,
									t_args_value args[3]);
void							c_fork(t_env *e, t_process *process,
									t_args_value args[3]);
void							lld(t_env *e, t_process *process,
									t_args_value args[3]);
void							lldi(t_env *e, t_process *process,
									t_args_value args[3]);
void							lfork(t_env *e, t_process *process,
									t_args_value args[3]);
void							aff(t_env *e, t_process *process,
									t_args_value args[3]);

/*
**	VISUAL_FUNCTIONS
*/

void							ft_end_visu(t_env *e);
int								ft_fill_arena(t_env *e);
int								ft_fill_info(t_env *e);
int								ft_visual(t_env *e);
int								ft_start_the_game_visu(t_env *e);
int								ft_maj_visu(t_env *e);
int								unix_text_kbhit(void);
int								ft_keypad(t_env *e, int key_pressed);

#endif
