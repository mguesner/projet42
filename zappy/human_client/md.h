/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:23:39 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:24:03 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD_H
# define MD_H

# include <stdio.h>
# include <sys/select.h>
# include <sys/time.h>
# include <sys/socket.h>
# include <sys/resource.h>
# include <sys/types.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <pthread.h>
# include <mlx.h>
# include <sys/uio.h>
# include <unistd.h>

# define WIN_SIZE_X				1920
# define WIN_SIZE_Y				1200
# define TITLE					"The best zappy of the world"
# define MAX_ACTION				10
# define AVANCE					"avance\n\0"
# define DROITE					"droite\n\0"
# define GAUCHE					"gauche\n\0"
# define VOIR					"voir\n\0"
# define INVENTAIRE				"inventaire\n\0"
# define EXPULSE				"expulse\n\0"
# define FORK					"fork\n\0"
# define CONNECT				"connect_nbr\n\0"
# define INCANT					"incantation\n\0"
# define PRENDRE_FOOD			"prend nourriture\n\0"
# define PRENDRE_L				"prend linemate\n\0"
# define PRENDRE_D				"prend deraumere\n\0"
# define PRENDRE_S				"prend sibur\n\0"
# define PRENDRE_M				"prend mendiane\n\0"
# define PRENDRE_P				"prend phiras\n\0"
# define PRENDRE_T				"prend thystame\n\0"
# define POSER_FOOD				"pose nourriture\n\0"
# define POSER_L				"pose linemate\n\0"
# define POSER_D				"pose deraumere\n\0"
# define POSER_S				"pose sibur\n\0"
# define POSER_M				"pose mendiane\n\0"
# define POSER_P				"pose phiras\n\0"
# define POSER_T				"pose thystame\n\0"
# define CONNECT_NBR			"connect_nbr\n\0"
# define OK						"ok\0"
# define KO						"ko\0"
# define START_ELEV				"elevation en cours\n\0"
# define MAX_PLAYER				10
# define FD_FREE				0
# define FD_PLAYER				1
# define BUFF_H					4096
# define BIENVENUE				"BIENVENUE\0"
# define INTER					"_inter_"
# define PRENDRE				1
# define POSER					2
# define V_FOOD					1
# define V_L					2
# define V_D					3
# define V_S					4
# define V_M					5
# define V_P					6
# define V_T					7
# define V_J					8
# define PLAYER					100
# define VISIBLE				1
# define BROUILLARD				2
# define NO_VIEW				0
# define VIEW_NORTH				0
# define VIEW_EAST				1
# define VIEW_SOUTH				2
# define VIEW_WEST				3
# define NB_FIELD				3
# define NB_BUTTON				27
# define NB_OBJECT				51
# define NB_OBJ_PLAYER			26
# define NB_OBJ_INVENTORY		10
# define FIELD_VOID				e->graph.img[0]
# define FIELD_FOG				e->graph.img[1]
# define OBJ_V_OTHER			e->graph.img[2]
# define OBJ_V_EAST_CUR			e->graph.img[3]
# define OBJ_V_EAST_FREE		e->graph.img[4]
# define OBJ_V_EAST_OT			e->graph.img[5]
# define OBJ_V_WEST_CUR			e->graph.img[6]
# define OBJ_V_WEST_FREE		e->graph.img[7]
# define OBJ_V_WEST_OT			e->graph.img[8]
# define OBJ_V_NORTH_CUR		e->graph.img[9]
# define OBJ_V_NORTH_FREE		e->graph.img[10]
# define OBJ_V_NORTH_OT			e->graph.img[11]
# define OBJ_V_SOUTH_CUR		e->graph.img[12]
# define OBJ_V_SOUTH_FREE		e->graph.img[13]
# define OBJ_V_SOUTH_OT			e->graph.img[14]
# define OBJ_V_T				e->graph.img[15]
# define OBJ_V_L				e->graph.img[16]
# define OBJ_V_M				e->graph.img[17]
# define OBJ_V_FOOD				e->graph.img[18]
# define OBJ_V_P				e->graph.img[19]
# define OBJ_V_S				e->graph.img[20]
# define OBJ_V_D				e->graph.img[21]
# define OBJ_FOG_EAST_CUR		e->graph.img[22]
# define OBJ_FOG_EAST_FREE		e->graph.img[23]
# define OBJ_FOG_EAST_OT		e->graph.img[24]
# define OBJ_FOG_WEST_CUR		e->graph.img[25]
# define OBJ_FOG_WEST_FREE		e->graph.img[26]
# define OBJ_FOG_WEST_OT		e->graph.img[27]
# define OBJ_FOG_NORTH_CUR		e->graph.img[28]
# define OBJ_FOG_NORTH_FREE		e->graph.img[29]
# define OBJ_FOG_NORTH_OT		e->graph.img[30]
# define OBJ_FOG_SOUTH_CUR		e->graph.img[31]
# define OBJ_FOG_SOUTH_FREE		e->graph.img[32]
# define OBJ_FOG_SOUTH_OT		e->graph.img[33]
# define OBJ_FOG_T				e->graph.img[34]
# define OBJ_FOG_L				e->graph.img[35]
# define OBJ_FOG_M				e->graph.img[36]
# define OBJ_FOG_FOOD			e->graph.img[37]
# define OBJ_FOG_P				e->graph.img[38]
# define OBJ_FOG_S				e->graph.img[39]
# define OBJ_FOG_D				e->graph.img[40]
# define BUTTON_AVANCE			e->graph.img[41]
# define BUTTON_BROAD			e->graph.img[42]
# define BUTTON_DROITE			e->graph.img[43]
# define BUTTON_EXPULSE			e->graph.img[44]
# define BUTTON_FORK			e->graph.img[45]
# define BUTTON_GAUCHE			e->graph.img[46]
# define BUTTON_INVENTAIRE		e->graph.img[47]
# define BUTTON_LEVEL_UP		e->graph.img[48]
# define BUTTON_POSER_D			e->graph.img[49]
# define BUTTON_POSER_F			e->graph.img[50]
# define BUTTON_POSER_L			e->graph.img[51]
# define BUTTON_POSER_M			e->graph.img[52]
# define BUTTON_POSER_P			e->graph.img[53]
# define BUTTON_POSER_S			e->graph.img[54]
# define BUTTON_POSER_T			e->graph.img[55]
# define BUTTON_PRENDRE_D		e->graph.img[56]
# define BUTTON_PRENDRE_F		e->graph.img[57]
# define BUTTON_PRENDRE_L		e->graph.img[58]
# define BUTTON_PRENDRE_M		e->graph.img[59]
# define BUTTON_PRENDRE_P		e->graph.img[60]
# define BUTTON_PRENDRE_S		e->graph.img[61]
# define BUTTON_PRENDRE_T		e->graph.img[62]
# define BUTTON_VOIR			e->graph.img[63]
# define FIELD_BLACK			e->graph.img[64]
# define OBJ_VOID_EAST_CUR		e->graph.img[65]
# define OBJ_VOID_EAST_FREE		e->graph.img[66]
# define OBJ_VOID_EAST_OT		e->graph.img[67]
# define OBJ_VOID_WEST_CUR		e->graph.img[68]
# define OBJ_VOID_WEST_FREE		e->graph.img[69]
# define OBJ_VOID_WEST_OT		e->graph.img[70]
# define OBJ_VOID_NORTH_CUR		e->graph.img[71]
# define OBJ_VOID_NORTH_FREE	e->graph.img[72]
# define OBJ_VOID_NORTH_OT		e->graph.img[73]
# define OBJ_VOID_SOUTH_CUR		e->graph.img[74]
# define OBJ_VOID_SOUTH_FREE	e->graph.img[75]
# define OBJ_VOID_SOUTH_OT		e->graph.img[76]
# define OBJ_PLAYER_CUR_1		e->graph.img[77]
# define OBJ_PLAYER_CUR_2		e->graph.img[78]
# define OBJ_PLAYER_CUR_3		e->graph.img[79]
# define OBJ_PLAYER_CUR_4		e->graph.img[80]
# define OBJ_PLAYER_CUR_5		e->graph.img[81]
# define OBJ_PLAYER_CUR_6		e->graph.img[82]
# define OBJ_PLAYER_CUR_7		e->graph.img[83]
# define OBJ_PLAYER_CUR_8		e->graph.img[84]
# define OBJ_PLAYER_FREE_1		e->graph.img[85]
# define OBJ_PLAYER_FREE_2		e->graph.img[86]
# define OBJ_PLAYER_FREE_3		e->graph.img[87]
# define OBJ_PLAYER_FREE_4		e->graph.img[88]
# define OBJ_PLAYER_FREE_5		e->graph.img[89]
# define OBJ_PLAYER_FREE_6		e->graph.img[90]
# define OBJ_PLAYER_FREE_7		e->graph.img[91]
# define OBJ_PLAYER_FREE_8		e->graph.img[92]
# define OBJ_PLAYER_OT_1		e->graph.img[93]
# define OBJ_PLAYER_OT_2		e->graph.img[94]
# define OBJ_PLAYER_OT_3		e->graph.img[95]
# define OBJ_PLAYER_OT_4		e->graph.img[96]
# define OBJ_PLAYER_OT_5		e->graph.img[97]
# define OBJ_PLAYER_OT_6		e->graph.img[98]
# define OBJ_PLAYER_OT_7		e->graph.img[99]
# define OBJ_PLAYER_OT_8		e->graph.img[100]
# define BUTTON_VIDE			e->graph.img[101]
# define OBJ_PLAYER_CUR_B		e->graph.img[102]
# define OBJ_PLAYER_B			e->graph.img[103]
# define BUTTON_CONNECT			e->graph.img[104]
# define OBJ_ACTION_LIST		e->graph.img[105]
# define OBJ_CUR_ACTION			e->graph.img[106]
# define OBJ_INV_I0				e->graph.img[107]
# define OBJ_INV_I1				e->graph.img[108]
# define OBJ_INV_I2				e->graph.img[109]
# define OBJ_INV_I3				e->graph.img[110]
# define OBJ_INV_I4				e->graph.img[111]
# define OBJ_INV_I5				e->graph.img[112]
# define OBJ_INV_I6				e->graph.img[113]
# define OBJ_INV_IX				e->graph.img[114]
# define OBJ_INV_BASE			e->graph.img[115]
# define OBJ_INV_VOID			e->graph.img[116]
# define CAMERA_UP				1
# define CAMERA_DOWN			-1
# define CAMERA_LEFT			-1
# define CAMERA_RIGHT			1
# define NB_TOTAL1				NB_FIELD + NB_OBJECT + NB_BUTTON
# define NB_TOTAL				NB_TOTAL1 + NB_OBJ_PLAYER + NB_OBJ_INVENTORY
# define EGG_NOTHING			0;
# define EGG_PONDU				1;
# define EGG_ECLOS				2;
# define EGG_OK					3;

typedef struct protoent			t_protoent;

typedef struct sockaddr			t_sockaddr;

typedef struct sockaddr_in		t_sockaddr_in;

typedef struct hostent			t_hostent;

typedef struct					s_img
{
	void						*ptr;
	int							width;
	int							height;
}								t_img;

typedef struct					s_case
{
	unsigned char				view;
	unsigned char				food;
	unsigned char				l;
	unsigned char				d;
	unsigned char				s;
	unsigned char				m;
	unsigned char				p;
	unsigned char				t;
	unsigned char				my_player;
	unsigned char				other_player;
	int							y;
	int							x;
}								t_case;

typedef struct					s_graph
{
	int							modif;
	int							start_x;
	int							start_y;
	pthread_t					graph;
	int							status;
	void						*mlx;
	void						*win;
	char						**tab;
	t_img						img[NB_TOTAL];
}								t_graph;

typedef struct					s_inventory
{
	unsigned char				status;
	int							food;
	int							l;
	int							d;
	int							s;
	int							m;
	int							p;
	int							t;
}								t_inventory;

typedef struct					s_player
{
	int							type;
	char						*action[MAX_ACTION];
	char						*cur_action;
	char						read[BUFF_H];
	ssize_t						ret_read;
	int							nb_action;
	int							num_player;
	int							sock;
	pthread_mutex_t				mutex;
	int							status;
	int							y;
	int							x;
	int							view;
	int							level;
	int							start_action;
	t_inventory					inventory;
}								t_player;

typedef struct					s_view
{
	int							case_y;
	int							case_x;
}								t_view;

typedef struct					s_egg
{
	time_t						t;
	unsigned char				status;
}								t_egg;

typedef struct					s_env
{
	t_graph						graph;
	t_player					players[MAX_PLAYER];
	t_player					*cur_player;
	int							max_fd;
	fd_set						fd_read;
	int							nb_player;
	int							port;
	t_hostent					*host;
	char						*team;
	t_case						**map;
	int							x;
	int							y;
	pthread_mutex_t				mutex;
	t_view						view;
	t_egg						egg[MAX_PLAYER];
	int							egg_use;
	int							connect;
	int							order_connect;
}								t_env;

int								ft_init_player(t_env *e, int i);
void							ft_destroy_player(t_env *e, int i);
int								ft_parse_option_human(int ac, char **av,
														t_env *e);
int								ft_connect_serveur(t_env *e);
void							*ft_mlx(void *p_data);
void							ft_memdel(void **ap);
void							ft_check_select(t_env *e);
void							ft_check_action(t_env *e);
void							ft_destroy_action(t_player *player, int i);
int								ft_read(t_player *player, t_env *e);
void							ft_check_coor(t_env *e, t_player *player);
char							*ft_strsub(char const *s, unsigned int start,
											size_t len);
size_t							ft_tablen(void **tab);
char							**ft_splitspace(char const *s);
void							ft_memdeltab(void ***tab);
void							ft_delfulltab(void ***tab);
void							ft_change_view(t_player *player, t_env *e);
char							*ft_itoa(int n);
void							ft_check_view_case(t_env *e, int y, int x);
int								ft_check_coor_y(int *y, t_env *e, int i);
int								ft_check_coor_x(int *x, t_env *e, int i);
void							ft_change_case(t_player *player, t_env *e,
												int new_y, int new_x);
void							ft_put_img_human(t_env *e);
void							ft_init_img(t_env *e);
void							ft_init_view_me(t_env *e);
void							ft_init_fog_me(t_env *e);
void							ft_init_view_object(t_env *e);
void							ft_init_fog_object(t_env *e);
void							ft_init_button(t_env *e);
void							ft_print_img(t_env *e, void *img,
												int x, int y);
void							ft_print_img_my_player_fog(t_env *e,
															t_case *field,
															int x, int y);
void							ft_print_img_my_player_view(t_env *e,
															t_case *field,
															int x, int y);
void							ft_print_img_my_player_void(t_env *e,
															t_case *field,
															int x, int y);
void							ft_change_camera(t_env *e, int x, int y);
void							ft_error(char *str, int ret);
void							ft_init_void_me(t_env *e);
void							ft_init_img_player(t_env *e);
void							ft_check_error_connect(int ret);
void							*ft_add_img(t_env *e, char *file,
											int *width, int *height);
void							ft_action_avance(t_player *player, t_env *e);
void							ft_action_droite(t_player *player, t_env *e);
void							ft_action_gauche(t_player *player, t_env *e);
void							ft_action_voir(t_player *player, t_env *e);
void							ft_print_img_players(t_env *e);
int								expose_loop(t_env *e);
void							ft_print_img_cmd(t_env *e, t_player *player);
char							*ft_strdup(const char *s1);
void							ft_obj_case_view(t_player *player, char *tab,
													t_env *e, int i);
char							**ft_strsplit(char const *s, char c);
void							ft_add_player(t_player *player, int y, int x);
void							ft_action_fork(t_player *player, t_env *e);
void							ft_check_action_mlx(t_player *player,
													char *cmd, t_env *e);
void							ft_check_action_prendre(t_env *e, int keycode);
void							ft_action_prendre(t_player *player, t_env *e);
void							ft_action_poser(t_player *player, t_env *e);
void							ft_check_action_poser(t_env *e, int keycode);
void							ft_action_incant(t_player *player, t_env *e);
void							ft_check_line(t_player *player, t_env *e);
int								ft_button(int keycode, t_env *e);
void							ft_init_img_inv(t_env *e);
void							ft_action_ko(t_player *player, t_env *e);
void							ft_init_inventaire(t_player *player);
void							ft_print_img_inventory(t_env *e,
														t_player *player);
void							ft_action_inventaire(t_player *player,
													t_env *e);
char							*ft_strtrim(char const *s);

#endif
