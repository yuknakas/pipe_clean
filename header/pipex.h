/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:06:32 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/02 10:00:34 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../00_libft/gnl/get_next_line.h"
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_cmd
{
	int		p_argc;
	char	**p_argv;
	char	**p_envp;
	int		**pipe_fd;
	pid_t	*fork_id;
	int		fork_count;
	int		pipe_count;
	int		is_heredoc;
}	t_cmd;

//main
int		main(int argc, char **argv, char **envp);

//forks
void	pex_pipex(t_cmd *tool);
void	_first_cmd(t_cmd *tool, int heredoc);
void	_middle_cmd(t_cmd *tool, int cmd_nb);
void	_last_cmd(t_cmd *tool, int append);

//sorting fds
int		pex_first_process(t_cmd *tool);
int		pex_middle_process(t_cmd *tool, char *cmd_name, int cmd_count);
int		pex_last_process(t_cmd *tool);
int		pex_heredoc(char *limiter, int **p_fd);
int		pex_append(char *output, t_cmd *tool);

//execution
int		_execute(char *command, char **envp);
char	**pex_pipe_split(char const *str);

//errors & utils
int		pex_putstr_int(char *str);
int		pex_puterror(char *str);
int		pex_file_error(char *file_name);
int		pex_cmd_error(char *cmd_name);
void	_freearr(char **arr);
void	_rm_quote(char *str);
void	_free_content(t_cmd *tool);
void	_close_fds(int **pipe_fd, int i);
void	_free_int_arr(int **arr);

#endif