/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marvin <marvin@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/17 13:40:33 by yuknakas		  #+#	#+#			 */
/*   Updated: 2025/02/28 17:43:33 by marvin		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../header/libft.h"

static int	_countsegment(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	**_freeall(char **arr)
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

char	**ft_split(char const *str, char c)
{
	int		seglen;
	char	**arr;
	char	**start;

	arr = malloc((_countsegment(str, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	start = arr;
	while (*str != '\0')
	{
		while (*str == c)
			str++;
		if (*str == '\0')
			break ;
		seglen = 0;
		while (str[seglen] != c && str[seglen] != '\0')
			seglen++;
		*arr = ft_substr(str, 0, seglen);
		if (*arr == NULL)
			return (_freeall(start));
		str += seglen;
		arr++;
	}
	*arr = NULL;
	return (start);
}
