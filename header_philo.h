/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:21:41 by ajoya-pi          #+#    #+#             */
/*   Updated: 2025/07/22 10:21:43 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PHILO_H
# define HEADER_PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_start_data
{
	unsigned int	s_time;
	struct s_philos	*philos;
	int				phi_num;
	int				ttd;
	int				tte;
	int				tts;
	int				n_toeat;
	int				done;
	int				dead;
	pthread_t		*thread_id;
	pthread_mutex_t	block;
	pthread_mutex_t	to_print;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philos
{
	t_data			*data;
	int				id;
	int				eat_status;
	int				eated;
	int				ttd;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	*l_f;
	pthread_mutex_t	block;
}	t_philos;

//threads
void			*life(void *phil);
int				eat(t_philos *philo);
int				onephilo(t_data *data);
int				morephilo(t_data *data);
void			destroy_frees(t_data *data);
void			*is_alive(void *p_data);
//utils
long			ft_atoi(char *str);
int				ft_isdigit(int c);
//timing
unsigned int	time_state(void);
void			nap(unsigned int alarm);
int				info_user(int state, t_philos *phill);
int				check_finished(t_philos *phill);

#endif
