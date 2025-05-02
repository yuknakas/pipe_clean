/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:30:45 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/02 12:12:39 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int			main(int argc, char **argv, char **envp);
static int	_set_variables(t_cmd *tool, int argc, char **argv, char **envp);
static int	**_allocate_pipe_fork(t_cmd *tool);
static void	_make_pipe(t_cmd *tool, int pipe_count);
static int	_wait_all_pids(t_cmd *tool);

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*tool;
	int		status;

	if (argc < 4)
		return (pex_putstr_int("Incorrect number of arguments\n"));
	tool = malloc(sizeof(t_cmd));
	if (tool == NULL)
		return (-1);
	if (_set_variables(tool, argc, argv, envp) == -1)
		return (-1);
	_make_pipe(tool, (tool->fork_count - 1));
	pex_pipex(tool);
	status = _wait_all_pids(tool);
	_free_content(tool);
	return (status);
}

static int	_set_variables(t_cmd *tool, int argc, char **argv, char **envp)
{
	tool->p_argc = argc;
	tool->p_argv = argv;
	tool->p_envp = envp;
	tool->fork_count = argc - 3;
	tool->is_heredoc = NO;
	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		tool->fork_count = argc - 2;
		tool->is_heredoc = YES;
	}
	tool->pipe_count = tool->fork_count - 1;
	tool->pipe_fd = _allocate_pipe_fork(tool);
	if (tool->pipe_fd == NULL)
	{
		free(tool);
		return (pex_putstr_int("Error: memory allocation failed\n"));
	}
	return (0);
}

static int	**_allocate_pipe_fork(t_cmd *tool)
{
	int	**pipe_fd;
	int	i;

	tool->fork_id = malloc(tool->fork_count * sizeof(pid_t));
	pipe_fd = malloc((tool->pipe_count + 1) * sizeof(int *));
	if (tool->fork_id == NULL || pipe_fd == NULL)
	{
		free(pipe_fd);
		free(tool->fork_id);
		return (NULL);
	}
	i = 0;
	while (i < tool->pipe_count)
	{
		pipe_fd[i] = malloc(2 * sizeof(int));
		if (pipe_fd[i] == NULL)
		{
			_free_int_arr(pipe_fd);
			free(tool->fork_id);
			return (NULL);
		}
		i++;
	}
	pipe_fd[i] = NULL;
	return (pipe_fd);
}

static void	_make_pipe(t_cmd *tool, int pipe_count)
{
	int	i;

	i = 0;
	while (i < pipe_count)
	{
		if (pipe(tool->pipe_fd[i]) == -1)
		{
			perror("Pipe Failed");
			exit(1);
		}
		i++;
	}
}

static int	_wait_all_pids(t_cmd *tool)
{
	int	i;
	int	status;
	int	status_tmp;

	_close_fds(tool->pipe_fd, 0);
	i = 0;
	status = 0;
	while (i < tool->fork_count)
	{
		status_tmp = status;
		waitpid(tool->fork_id[i], &status, 0);
		i++;
	}
	status = WEXITSTATUS(status);
	if (ft_strncmp(tool->p_argv[1], "here_doc", 9))
		status = WEXITSTATUS(status_tmp);
	return (status);
}
