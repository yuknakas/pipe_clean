/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:44:52 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/02 10:19:50 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void		pex_pipex(t_cmd *tool);
static int	_single_process(t_cmd *tool);

void	pex_pipex(t_cmd *tool)
{
	int	i;

	if (tool->p_argc == 4 && tool->is_heredoc == NO)
	{
		_single_process(tool);
		return ;
	}
	_first_cmd(tool, tool->is_heredoc);
	i = 1;
	while (i < (tool->p_argc - 4 + tool->is_heredoc))
	{
		_middle_cmd(tool, i);
		i++;
	}
	_last_cmd(tool, tool->is_heredoc);
	i++;
}

static int	_single_process(t_cmd *tool)
{
	int	fd_input;
	int	fd_output;

	tool->fork_id[0] = fork();
	if (tool->fork_id[0] == -1)
	{
		pex_puterror("Fork Failed");
		return (-1);
	}
	if (tool->fork_id[0] != 0)
		return (-1);
	fd_input = open(tool->p_argv[1], O_RDONLY);
	if (fd_input == -1)
		return (pex_file_error(tool->p_argv[1]));
	fd_output = open(tool->p_argv[3], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_output == -1)
		return (pex_file_error(tool->p_argv[3]));
	dup2(fd_input, STDIN_FILENO);
	dup2(fd_output, STDOUT_FILENO);
	close(fd_input);
	close(fd_output);
	exit(_execute(tool->p_argv[2], tool->p_envp));
}
