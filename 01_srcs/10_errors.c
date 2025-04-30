/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:42:30 by yuknakas          #+#    #+#             */
/*   Updated: 2025/03/12 13:30:29 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	pex_putstr_int(char *str)
{
	if (!str)
		return (-1);
	ft_putstr_fd(str, STDERR_FILENO);
	return (-1);
}

int	pex_puterror(char *str)
{
	perror(str);
	return (-1);
}

int	pex_file_error(char *file_name)
{
	ft_putstr_fd("bash: ", STDERR_FILENO);
	ft_putstr_fd(file_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(NULL);
	return (-1);
}

int	pex_cmd_error(char *cmd_name)
{
	ft_putstr_fd(cmd_name, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	return (-1);
}

void	_freearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
