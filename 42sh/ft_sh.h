/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 13:20:11 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 13:55:24 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <termios.h>

# define CMD		0
# define PIPE		1
# define REDIRECT	2
# define END		3
# define BUILTIN	4
# define FILES		5
# define AND		6
# define OR			7

# define CO		tgetnum("co")
# define BUFF	ft_strlen(g_e.buff)
# define G_E	g_e.i + g_e.prompt

typedef struct		s_list
{
	char			*content;
	int				flag;
	pid_t			job;
	struct s_list	*next;
	struct s_list	*pre;
}					t_list;

typedef struct		s_tree
{
	char			*content;
	int				flag;
	struct s_tree	*right;
	struct s_tree	*left;
}					t_tree;

typedef struct		s_env
{
	struct termios	old;
	struct termios	termios_p;
	int				i;
	int				prompt;
	int				size;
	int				autocomplete;
	char			line[4];
	char			*buff;
	t_list			*hystor;
	t_list			*job;
	t_list			*choice;
}					t_env;

t_env				g_e;

int					ft_putonterm(int c);
char				**creat_env(void);
void				ft_error(char *str);
void				ft_sh(char **env);
void				ft_init(void);
void				ft_exit(int a);
void				ft_print(void);
void				ft_add(char *str, int i, char c, int *size);
void				ft_del_char(char *str, int i);
char				*ft_realloc(char *str, int size);
void				ft_init_e(void);
void				ft_prompt(char **env);
char				*ft_getenv(char *str, char **env);
void				ft_enter(char ***env);
void				ft_go(char ***env);
char				**ft_path(void);
void				ft_tabdel(char **env);
t_list				*ft_create_elem(char *str, int flag);
t_list				*ft_parser(char *str);
int					ft_parseredir(t_list **current, char **str, char c);
int					ft_parseend(t_list **current, char **str);
int					ft_parsecmd(t_list **current, char **str);
int					ft_parsepipe(t_list **current, char **str);
int					ft_parseand(t_list **current, char **str);
int					ft_parseor(t_list **current, char **str);
t_list				*ft_parseerror(t_list **list);
int					ft_isop(char c);
int					is_builtin(char *str);
char				*ft_createstr(char c, int n);
void				ft_lstdel(t_list *lst);
t_tree				*ft_make_tree(t_list *arg);
t_tree				*ft_new_node(t_list *arg);
t_tree				*ft_big_node(t_list *arg);
void				ft_see_tree(t_tree *tree, int i);
void				ft_del_tree(t_tree *tree);
int					ft_exec(t_tree *tree, char **path, char ***env);
int					ft_exec_pipe(t_tree *tree, char **path, char ***env);
int					ft_exec_redirect(t_tree *tree, char **path, char ***env);
int					ft_fork(char *cmd, char **path, char ***env);
int					ft_cmd(char *cmd, char **path, char ***env);
int					ft_tablen(char **arg);
int					ft_file_error(char *str);
int					ft_cd(char **arg, char ***env);
void				ft_error_cd(char *str);
int					ft_builtin(char *cmd, char ***env);
void				ft_setenv(char ***env, char *line, char *str);
int					ft_isdir(char *path);
int					ft_env(char **arg, char **env);
char				**ft_cpyenv(char **env);
void				ft_add_env(char ***env, char *str);
int					ft_presetenv(char **arg, char ***env);
int					ft_unsetenv(char **arg, char ***env);
void				ft_supressslash(char **arg);
void				ft_strsupressslash(char *str);
void				ft_arrow(void);
void				ft_signal(int i);
char				**ft_stock(char **env, int mode);
void				ft_reput_prompt(int a);
void				ft_add_hystor(int mode);
void				ft_hystor(void);
t_list				*ft_autocomplete(char *buff, char **path);
void				ft_tab(char **env);
void				ft_add_job(pid_t job, char *cmd);
int					ft_echo(char **arg);
void				ft_aff(t_list *lst);
void				ft_scroll(t_list *lst, int mode);
void				ft_reset(void);
int					ft_end(int stat_loc, char *cmd);
void				ft_add_rep(t_list **lst, char *dirname);
void				ft_add_all_tolist(t_list **lst, char *dirname);
void				ft_complete_cmd(char **line, char **path, t_list **lst);
void				ft_allcmd(t_list **lst, char **path);
char				*ft_getwords(char *line, int *slash);
int					ft_countword(char *line);
void				ft_delnode(t_list **node);
char				*ft_str_spe_dup(char *str);
void				ft_complete_file(char **save, int slash, t_list **lst);
void				ft_try_depth(char *word, t_list **lst);
void				ft_absolute_path(char *word, t_list **lst);
void				ft_cut(char *word, char **way, char **find);
void				ft_add_tolist(t_list **lst, char *dirname, char *line);
t_list				*ft_create_node(char *str);
void				ft_first_node(t_list **lst, t_list *node);
void				ft_insert_node(t_list *node, t_list *tmp, t_list **lst);
void				ft_add_node(t_list **lst, char *str);
void				ft_affbis(int i, int li, char line[1]);
int					ft_envbis(char **arg, int i, char **env_cpy);
void				ft_deleter(t_tree *tree, char **path
		, char ***env, char **cmd);
void				ft_leftson(int fd[2], t_tree *tree, char **path
		, char ***env);
t_tree				*ft_make_treebis(t_list *current, t_list *pre);
t_tree				*ft_make_treebis2(t_list *current, t_list *pre
		, t_list *arg);
void				ft_arg_del(t_list **arg);

#endif
