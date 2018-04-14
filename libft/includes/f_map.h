/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_map.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 09:48:14 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _F_MAP_H
# define _F_MAP_H
# include <stdlib.h>
# include <stdio.h>

typedef struct				s_entry
{
	char					*key;
	char					*value;
}							t_entry;

typedef struct				s_map
{
	t_list					*lst;
}							t_map;

t_map						*map_new(void);
void						map_del(t_map *hashmap);
void						map_print(t_map *map);
void						map_set(t_map *hashmap, char *key, char *val);
t_entry						*map_get(t_map *hashmap, char *key);
char						*map_getv(t_map *map, char *key);
int							map_unset(t_map *map, char *key);

#endif
