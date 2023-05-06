/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:52:05 by psegura-          #+#    #+#             */
/*   Updated: 2023/05/06 20:40:01 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBS_H
# define LIBS_H

//Write, Getpid, Pause, Sleep, Usleep
# include <unistd.h>

//Signal, Sigemptyset, Sigaddset, Sigaction, Kill
# include <signal.h>

//Read, Perror, Strerror
# include <stdio.h>

//Malloc, Free, Exit
# include <stdlib.h>

#endif
