/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:06:32 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/30 16:47:29 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
void	pex_pipex(t_cmd *tool);

int		_pipex(t_cmd *tool);
void	_first_cmd(t_cmd *t, int heredoc);
void	_middle_cmd(t_cmd *t, int cmd);
void	_last_cmd(t_cmd *t, int cmd, int append);

//processes
int		pex_first_process(char *input, char *cmd1, char **envp, int **p_fd);
int		pex_middle_process(char *cmd1, char **envp, int **p_fd, int cmd_count);
int		pex_last_process(char *output, char *cmd2, t_cmd *tool);
int		_execute(char *command, char **envp);

//heredoc
int		pex_bon_heredoc(t_cmd *tool);
int		pex_heredoc(char *limiter, int **p_fd);
int		pex_append(char *output, t_cmd *tool);

//utils
char	**pex_pipe_split(char const *str);
void	_rm_quote(char *str);
int		pex_putstr_int(char *str);
int		pex_puterror(char *str);
int		pex_file_error(char *file_name);
void	_freearr(char **arr);
void	_free_int_arr(int **arr);
void	_close_fds(int **pipe_fd, int i);
void	_free_content(t_cmd *tool);

#endif