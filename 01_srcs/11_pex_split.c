/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_pex_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:40:33 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/02 09:22:28 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char		**pex_pipe_split(char const *str);
static int	_word_len(const char *str);
static int	_pipe_countsegment(const char *str);
static char	**_pipe_freeall(char **arr);
static int	_makesegment(char **arr, char const **str, int sec);

char	**pex_pipe_split(char const *str)
{
	char	**arr;
	int		i;

	i = _pipe_countsegment(str);
	if (i == -1)
		return (NULL);
	arr = malloc((i + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		while (*str == ' ')
			str++;
		if (*str == '\0')
			break ;
		if (_makesegment(arr, &str, i) == -1)
			return (_pipe_freeall(arr));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

static int	_pipe_countsegment(const char *str)
{
	int		i;
	int		count;
	int		tmp;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
		{
			count++;
			tmp = _word_len(&str[i]);
			if (tmp == -1)
				return (-1);
			i += tmp;
		}
	}
	return (count);
}

static int	_word_len(const char *str)
{
	char	tmp;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			tmp = str[i];
			i++;
			while (str[i] != '\0' && !(str[i] == tmp && str[i - 1] != '\\'))
				i++;
			if (str[i] == '\0')
				return (pex_putstr_int("quote>\n"));
			i++;
		}
		else
			i++;
	}
	return (i);
}

static int	_makesegment(char **arr, char const **str, int sec)
{
	int	seglen;

	seglen = _word_len(*str);
	if (seglen < 1)
		return (-1);
	arr[sec] = ft_substr(str[0], 0, seglen);
	if (*arr == NULL)
		return (-1);
	_rm_quote(arr[sec]);
	*str += seglen;
	return (0);
}

static char	**_pipe_freeall(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
