/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_handle_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:12:33 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/30 17:07:55 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	_rm_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"' || str[i] == '\'' || str[i] == '\\')
			i++;
		*str = str[i];
		str++;
	}
	*str = '\0';
}

void	_free_content(t_cmd *tool)
{
	int	i;

	i = 0;
	while (tool->pipe_fd[i] != NULL)
	{
		free(tool->pipe_fd[i]);
		i++;
	}
	free(tool->pipe_fd);
	free(tool->fork_id);
	free(tool);
}

void	_close_fds(int **pipe_fd, int i)
{
	while (pipe_fd[i] != NULL)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
}
