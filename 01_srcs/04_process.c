/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:04:00 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/04 21:32:51 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	pex_first_process(t_cmd *tool);
int	pex_middle_process(t_cmd *tool, char *cmd_name, int cmd_count);
int	pex_last_process(t_cmd *tool);

int	pex_first_process(t_cmd *tool)
{
	int		fd_input;
	char	*infile;
	char	*first_cmd;

	infile = tool->p_argv[1];
	first_cmd = tool->p_argv[2];
	fd_input = open(infile, O_RDONLY);
	if (fd_input == -1)
	{
		pex_file_error(infile);
		return (1);
	}
	dup2(tool->pipe_fd[0][1], STDOUT_FILENO);
	dup2(fd_input, STDIN_FILENO);
	_close_fds(tool->pipe_fd, 0);
	close(fd_input);
	return (_execute(first_cmd, tool->p_envp));
}

int	pex_middle_process(t_cmd *tool, char *cmd_name, int cmd_count)
{
	dup2(tool->pipe_fd[cmd_count - 1][0], STDIN_FILENO);
	dup2(tool->pipe_fd[cmd_count][1], STDOUT_FILENO);
	_close_fds(tool->pipe_fd, 0);
	return (_execute(cmd_name, tool->p_envp));
}

int	pex_last_process(t_cmd *tool)
{
	int		fd_output;
	char	*output;
	char	*last_cmd;

	output = tool->p_argv[tool->p_argc - 1];
	last_cmd = tool->p_argv[tool->p_argc - 2];
	fd_output = open(output, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_output == -1)
	{
		pex_file_error(output);
		return (1);
	}
	dup2(tool->pipe_fd[tool->p_argc - 5][0], STDIN_FILENO);
	dup2(fd_output, STDOUT_FILENO);
	_close_fds(tool->pipe_fd, 0);
	close(fd_output);
	return (_execute(last_cmd, tool->p_envp));
}
