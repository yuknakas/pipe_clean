/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:55:57 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/04 21:37:01 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int			pex_heredoc(char *limiter, int **p_fd);
int			pex_append(char *output, t_cmd *tool);
static void	_append(void);

int	pex_heredoc(char *limiter, int **p_fd)
{
	char	*line;
	char	*limit_nl;

	dup2(p_fd[0][1], STDOUT_FILENO);
	_close_fds(p_fd, 0);
	write(STDERR_FILENO, "> ", 2);
	line = get_next_line(STDIN_FILENO, NO);
	limit_nl = ft_strjoin(limiter, "\n\0");
	while (line && ft_strncmp(line, limit_nl, INT_MAX))
	{
		ft_putstr_fd(line, STDOUT_FILENO);
		write(STDERR_FILENO, "> ", 2);
		free(line);
		line = get_next_line(STDIN_FILENO, NO);
	}
	if (line)
		free(line);
	get_next_line(STDIN_FILENO, YES);
	free(limit_nl);
	close(STDIN_FILENO);
	return (0);
}

int	pex_append(char *output, t_cmd *tool)
{
	int	fd_output;

	fd_output = open(output, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd_output == -1)
	{
		pex_file_error(output);
		return (1);
	}
	dup2(tool->pipe_fd[tool->p_argc - 4][0], STDIN_FILENO);
	dup2(fd_output, STDOUT_FILENO);
	_close_fds(tool->pipe_fd, 0);
	close(fd_output);
	_append();
	return (0);
}

static void	_append(void)
{
	char	*line;

	line = get_next_line(STDIN_FILENO, NO);
	while (line)
	{
		ft_putstr_fd(line, STDOUT_FILENO);
		free(line);
		line = get_next_line(STDIN_FILENO, NO);
	}
	get_next_line(STDIN_FILENO, YES);
}
