/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 10:17:53 by icheres           #+#    #+#             */
/*   Updated: 2016/04/20 12:18:09 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include "includes/libft/libft.h"
# define PATH_MAX	4096

typedef	struct dirent	t_d;
typedef struct stat	t_s;

char				*g_oldpath;

typedef struct		s_nnlist
{
	char			*fd;
	char			*mode; // 1> 2>> etc
	struct s_nnlist	*next;
	struct s_nnlist	*prev;
}					t_nnlist;

typedef struct		s_nlist
{
	char			*command;
	struct s_nlist	*next;
	struct s_nlist	*prev;
	t_nnlist		*fd_in;
	t_nnlist		*fd_out;
}					t_nlist;

typedef struct		s_slist
{
	t_nlist			*data_list;
	struct s_slist	*next;
}					t_slist;

typedef	struct		s_ok
{
	int				ok1;
	int				ok2;
}					t_ok;

typedef	struct		s_mat
{
	char			**d;
	char			**envp;
}					t_mat;

typedef	struct		s_sp
{
	int				i;
	int				j;
	int				size;
	int				status;
	int				index;
}					t_sp;

typedef	struct		s_st
{
	t_d				*dp;
	t_s				stat;
}					t_st;

typedef	struct		s_run_data
{
	char			**argv;
	char			**envp;
	char			*command;
	char			*path;
	char			**paths;
}					t_run_data;

typedef	struct		s_arrays
{
	char			*home;
	char			*pwd;
}					t_arrays;

typedef	struct		s_main
{
	char			**paths;
	char			buff[2];
	char			*i_d;
	int				count;
}					t_main;

typedef struct		s_recdata
{
	int				in;
	int				index;
	int				max;
}					t_recdata;

//commands_h
void				commands(t_slist *list, char **env, char **paths);

// wrong_fct
void				aff(t_slist *a);
void				aff_nlist(t_nlist *a);
void				afis_paths(char **s);
void				aff_meganlist(t_nlist *list);

 // t2
void				kk(char **env, size_t index, int in_fd);
//run
void				child(char **env, char **paths, char *data);

int					err(char *s);
int					get_path_position(char **envp, char *info);
int					return_msj_val(char *str, int val);
char				*get_info(char **envp, char *info);

//iter_fd
void				iter_comm(t_nlist *l, char **en, char **paths);
void				pulis(t_nlist *l, char **en, char **paths);
//slist_create
t_slist				*get_list(char *data);

//nlist_create
t_slist				*create_selem(char *data);

char				*ft_strcpy(char *dst, const char *src);
char				**ft_split_whitespaces(char *str, char c);
void				ft_putstr(const char *s);
char				*ft_realloc(char *data, char *buff);
char				*comp(char *s1, char *s2);
int					is_special(char *s);
int					ft_implement_functions(char *input, char ***env);
int					print_env(char **env);
//utility validation
int					arg_number(char **data);
int					exists(char *s, char c);
//utility process
char				*concat_with(char **array, char delim);
char				**del_from_matrix(char **matrix, int pos);

//ut impl func
char				*unset_env_data(char *data);
int					ft_cd(char *data, char **envp);
int					recursive_search(char **d, int i, int max_args, DIR *dir);
int					r_msj_val(char *msj, char *name, int val);
void				refresh_path(char **envp);

//processing_command.c
void				processing_list(t_nlist *list);

//util_str_plus
char				*minus(char *d, char *s);
char				*clean_spaces(char *s);

void				init_split(int *i, int *j, int *index);
char				*clean(char *str, char del);
void				st(char **str, char *s_o, char d, char ***w);
int					ft_words(char *s, char delim);
int					compute(char *data, char **paths, char **env);

//utility_lis

int					list_count(t_nlist *l);

void				ft_putstr_s(char *s1, char *s2);
void				ft_afis_mat(char **s);
#endif
