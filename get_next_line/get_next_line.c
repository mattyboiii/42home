/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:10:32 by mtripodi          #+#    #+#             */
/*   Updated: 2024/04/04 11:24:19 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: get_next_line
** -----------------------------
** Prototype: char *get_next_line(int fd);
**
** Parameters:
**    fd: The file descriptor to read from.
**
** Return value:
**    Read line: correct behavior
**    NULL: there is nothing else to read, or an error occurred.
**
** External functions: read, malloc, free
**
** Description:
**    Write a function that returns a line read from a file descriptor.
*/

/*
** ssize_t read(int fildes, void *buf, size_t nbyte);
**
** DESCRIPTION
**     read() attempts to read nbyte bytes of data from the object referenced
**     by the descriptor fildes into the buffer pointed to by buf.
*/

