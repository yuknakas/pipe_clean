/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:49:04 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/02 09:19:35 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int			_execute(char *command, char **envp);
static char	**_set_cmd(char *command);
static char	*_pathway(char *command, char **envp);
static char	*_check_path(char **path_comp, char *command);

int	_execute(char *command, char **envp)
{
	char	**cmd;
	char	*path;
	int		sucess;

	cmd = _set_cmd(command);
	if (cmd == NULL)
		return (-1);
	path = _pathway(cmd[0], envp);
	if (path == NULL)
	{
		pex_cmd_error(cmd[0]);
		_freearr(cmd);
		return (127);
	}
	sucess = execve(path, cmd, envp);
	free(path);
	_freearr(cmd);
	if (sucess == -1)
		return (pex_putstr_int("Error: Failed Execution\n"));
	return (sucess);
}

static char	**_set_cmd(char *command)
{
	int		i;
	char	**cmd_arg;

	if (command == NULL || *command == '\0')
	{
		pex_putstr_int("zsh: permission denied\n");
		return (NULL);
	}
	cmd_arg = pex_pipe_split(command);
	if (cmd_arg == NULL)
	{
		pex_putstr_int("Error: memory allocation failed\n");
		return (NULL);
	}
	i = 0;
	while (cmd_arg[i] != NULL)
	{
		_rm_quote(cmd_arg[i]);
		i++;
	}
	return (cmd_arg);
}

static char	*_pathway(char *command, char **envp)
{
	char	**path_comp;
	int		i;

	i = 0;
	while (envp[i] != NULL && ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	path_comp = ft_split((envp[i] + 5), ':');
	if (path_comp == NULL)
	{
		pex_putstr_int("Error: Split Failed\n");
		return (NULL);
	}
	return (_check_path(path_comp, command));
}

static char	*_check_path(char **path_comp, char *command)
{
	char	*new_path;
	char	*path;
	int		i;

	i = 0;
	while (path_comp[i] != NULL)
	{
		new_path = ft_strjoin(path_comp[i], "/");
		path = ft_strjoin(new_path, command);
		free(new_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			_freearr(path_comp);
			return (path);
		}
		free(path);
		i++;
	}
	_freearr(path_comp);
	return (NULL);
}
