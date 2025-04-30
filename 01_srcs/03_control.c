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

void	_first_cmd(t_cmd *t, int heredoc)
{
	int		i;
	char	*infile;
	char	*cmd;

	t->fork_id[0] = fork();
	if (t->fork_id[0] == -1)
	{
		pex_puterror("Fork Failed");
		return ;
	}
	infile = t->p_argv[1];
	cmd = t->p_argv[2];
	if (t->fork_id[0] == 0)
	{
		if (heredoc == YES)
			i = pex_heredoc(t->p_argv[2], t->pipe_fd);
		else
			i = pex_first_process(infile, cmd, t->p_envp, t->pipe_fd);
		_free_content(t);
		exit(i);
	}
}

void	_middle_cmd(t_cmd *t, int cmd)
{
	int	i;

	t->fork_id[cmd] = fork();
	if (t->fork_id[cmd] == -1)
	{
		pex_puterror("Fork Failed");
		return ;
	}
	if (t->fork_id[cmd] == 0)
	{
		i = pex_middle_process(t->p_argv[cmd + 2], t->p_envp, t->pipe_fd, cmd);
		_free_content(t);
		exit(i);
	}
}

void	_last_cmd(t_cmd *t, int cmd, int append)
{
	int		i;
	char	*last_cmd;

	t->fork_id[cmd] = fork();
	if (t->fork_id[cmd] == -1)
	{
		pex_puterror("Fork Failed");
		return ;
	}
	last_cmd = t->p_argv[cmd + 1];
	if (t->fork_id[cmd] == 0)
	{
		if (append == YES)
			i = pex_append(t->p_argv[cmd + 3], t);
		else
			i = pex_last_process(t->p_argv[cmd + 2], last_cmd, t);
		_free_content(t);
		exit(i);
	}
}

void	_free_int_arr(int **arr)
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
