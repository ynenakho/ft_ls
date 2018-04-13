/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:39:57 by ynenakho          #+#    #+#             */
/*   Updated: 2018/03/19 19:39:59 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int g_optint = 1;

static void error(char x, char *name)
{
  ft_putstr_fd(name, 2);
  write(2, ": illegal option -- ", 20);
  ft_putchar_fd(x, 2);
  write(2, "\nusage: ls [-Ralrt] [file ...]\n", 31);
  exit(1);
}

int ft_getopt(char **argv, char *optstr)
{
  char *tmp;
  static int j = 0;

  j++;
  tmp = optstr;
  while (argv[g_optint])
  {
    if (argv[g_optint][0] == '-')
      while (argv[g_optint][j])
      {
        while (*tmp)
          if (argv[g_optint][j] == *tmp++)
            return (int)(argv[g_optint][j]);
        error(argv[g_optint][j], argv[0]);
      }
    else
      return (-1);
    g_optint++;
    j = 1;
  }
  return (-1);
}
