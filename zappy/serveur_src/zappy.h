/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 14:17:25 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/26 14:42:05 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_H
# define ZAPPY_H

# define BUF_SIZE			4096

# define TIME				100

# define RAND_NOURRITURE	0.8
# define RAND_LINEMATE		0.6
# define RAND_DERAUMERE		0.4
# define RAND_SIBUR			0.3
# define RAND_MENDIANE		0.2
# define RAND_PHIRAS		0.1
# define RAND_THSTAME		0.05

# define CLIENT_FREE		0
# define CLIENT_SERV		1
# define CLIENT_CLIENT		2
# define CLIENT_GRAPH		3
# define CLIENT_ATT			4

# define X					pos[0]
# define Y					pos[1]

# define TEST				e->clients[fd].i_action < 10 && tab[0]
# define TYPE(i)			e->clients[i].type

# include <sys/select.h>
# include <string.h>

typedef struct				s_clients
{
	int						type;
	int						nb;
	int						connected;
	int						life;
	int						linemate;
	int						deraumere;
	int						sibur;
	int						mendiane;
	int						phiras;
	int						thystame;
	int						lvl;
	void					(*fct_read)();
	void					(*fct_write)();
	void					(*fct_cmd)();
	int						i_action;
	void					(*fct_action[11])();
	int						action[11];
	char					arg[11][BUF_SIZE + 1];
	char					buf_read[BUF_SIZE + 1];
	char					buf_write[BUF_SIZE + 1];
	char					cbuf[BUF_SIZE + 1];
	size_t					start;
	size_t					end;
	int						pos[2];
	int						orient;
	char					*name;
}							t_clients;

typedef struct				s_oeuf
{
	int						nb;
	int						life;
	int						eclo;
	int						x;
	int						y;
	char					*team;
	struct s_oeuf			*next;
}							t_oeuf;

typedef struct				s_case
{
	int						joueur;
	int						nourriture;
	int						linemate;
	int						deraumere;
	int						sibur;
	int						mendiane;
	int						phiras;
	int						thystame;
}							t_case;

typedef struct				s_list
{
	char					*name;
	int						nb_connect;
	int						nb_player;
	int						nb_oeuf;
	struct s_list			*next;
}							t_list;

typedef struct				s_env
{
	int						port;
	int						width;
	int						height;
	t_list					*names;
	int						nb;
	int						time;
	t_clients				*clients;
	t_oeuf					*oeufs;
	t_case					**map;
	int						max_fd;
	int						max_clients;
	int						max;
	int						ret;
	fd_set					fd_read;
	fd_set					fd_write;
}							t_env;

typedef struct protoent		t_protoent;
typedef struct sockaddr_in	t_sockaddr_in;
typedef struct sockaddr		t_sockaddr;
typedef struct hostent		t_hostent;
typedef struct in_addr		t_in_addr;

void						initenv(t_env *e);
void						serveur(t_env *e);
void						ft_perror(char *str);
void						ft_error(char *str);
void						ft_accept(t_env *e, int sock);
void						cleanclient(t_clients *client);
void						ft_read(t_env *e, int fd);
void						ft_write(t_env *e, int fd);
void						loop(t_env *e);
void						initclients(t_env *e);
t_case						genere_case(void);
void						ft_select(t_env *e, unsigned long t
	, unsigned long last_t);
void						checkclients(t_env *e, unsigned long t
	, unsigned long last_t);
void						ft_connect(t_env *e, int fd, char *cmd);
void						ft_cmd(t_env *e, int fd);
void						eat(t_env *e, t_clients *client);
unsigned long				microtime(void);
void						preprend(t_env *e, int fd, char cmd[]);
void						prend(t_env *e, t_clients *player);
void						prepose(t_env *e, int fd, char cmd[]);
void						pose(t_env *e, t_clients *player);
void						preavance(t_env *e, int fd, char cmd[]);
void						avance(t_env *e, t_clients *player);
void						predroite(t_env *e, int fd, char cmd[]);
void						droite(t_env *e, t_clients *player);
void						pregauche(t_env *e, int fd, char cmd[]);
void						gauche(t_env *e, t_clients *player);
void						prevoir(t_env *e, int fd, char cmd[]);
void						voir(t_env *e, t_clients *player);
void						inside(t_clients *player, t_case place, int i);
int							modulo(int a, int b);
void						preinventaire(t_env *e, int fd, char cmd[]);
void						inventaire(t_env *e, t_clients *player);
int							opt(char **argv, t_env *e);
t_list						*new_name(char *name);
int							ft_initgraph(t_env *e, int fd);
void						connect_nbr(t_env *e, int fd);
void						connect_gfx(t_env *e, t_clients *player);
void						maj_gfx(t_env *e, char *maj);
void						move_gfx(t_env *e, t_clients *player);
void						prebroadcast(t_env *e, int fd, char *cmd);
void						broadcast(t_env *e, t_clients *player);
void						broadcast_gfx(t_env *e, t_clients *player
	, char *msg);
void						prefork(t_env *e, int fd, char cmd[]);
void						pond(t_env *e, t_clients *player);
t_oeuf						*create_oeuf(t_env *e, t_clients *player);
void						checkoeuf(t_env *e);
int							isoeuf(t_env *e, t_clients *player, char *cmd);
void						destroy_oeuf(t_env *e, t_oeuf *oeuf);
void						pond_gfx(t_env *e, t_oeuf *oeuf);
void						contenue(t_env *e, int i, int j, int fd);
void						preexpulse(t_env *e, int fd, char *cmd);
void						expulse(t_env *e, t_clients *player);
int							ex_dir(t_clients *src, t_clients *dst);
void						preincantation(t_env *e, int fd, char cmd[]);
void						incantation(t_env *e, t_clients *player);
void						aff_map(t_env *e, t_clients *player);
void						explode_player(t_env *e, t_clients *player);
void						explode_case(t_env *e, t_case *casee);
int							lvl_un(t_env *e, t_clients *player, t_case autel);
int							lvl_deux(t_env *e, t_clients *player, t_case autel);
int							lvl_trois(t_env *e, t_clients *player
	, t_case autel);
int							lvl_quatre(t_env *e, t_clients *player
	, t_case autel);
int							lvl_cinq(t_env *e, t_clients *player, t_case autel);
int							lvl_six(t_env *e, t_clients *player, t_case autel);
int							lvl_sept(t_env *e, t_clients *player, t_case autel);
void						end_game(t_env *e, t_clients *player);
void						next_action(t_clients *player);
int							ft_close_gfx(int fd, t_env *e);
void						contenue2(t_env *e, int i, int j);

#endif
