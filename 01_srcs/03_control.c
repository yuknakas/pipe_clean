/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:34:59 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 18:34:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	_first_cmd(t_cmd *t, int heredoc);
void	_middle_cmd(t_cmd *t, int cmd_nb);
void	_last_cmd(t_cmd *t, int cmd, int append);

void	_first_cmd(t_cmd *tool, int heredoc)
{
	int		i;
	char	*infile;
	char	*cmd;

	tool->fork_id[0] = fork();
	if (tool->fork_id[0] == -1)
	{
		pex_puterror("Fork Failed");
		return ;
	}
	infile = tool->p_argv[1];
	cmd = tool->p_argv[2];
	if (tool->fork_id[0] == 0)
	{
		if (heredoc == YES)
			i = pex_heredoc(tool->p_argv[2], tool->pipe_fd);
		else
			i = pex_first_process(tool);
		_free_content(tool);
		exit(i);
	}
}

void	_middle_cmd(t_cmd *tool, int cmd_nb)
{
	int		i;
	char	*cmd_name;

	tool->fork_id[cmd_nb] = fork();
	if (tool->fork_id[cmd_nb] == -1)
	{
		pex_puterror("Fork Failed");
		return ;
	}
	if (tool->fork_id[cmd_nb] == 0)
	{
		cmd_name = tool->p_argv[cmd_nb + 2];
		i = pex_middle_process(tool, cmd_name, cmd_nb);
		_free_content(tool);
		exit(i);
	}
}

void	_last_cmd(t_cmd *tool, int cmd, int append)
{
	int		i;
	char	*last_cmd;
	char	*output;

	tool->fork_id[cmd] = fork();
	if (tool->fork_id[cmd] == -1)
	{
		pex_puterror("Fork Failed");
		return ;
	}
	last_cmd = tool->p_argv[cmd + 1];
	output = tool->p_argv[tool->p_argc - 1];
	if (tool->fork_id[cmd] == 0)
	{
		if (append == YES)
			i = pex_append(output, tool);
		else
			i = pex_last_process(tool);
		_free_content(tool);
		exit(i);
	}
}
