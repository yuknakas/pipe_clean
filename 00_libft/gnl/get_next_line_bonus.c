/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_bonus.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yuknakas <yuknakas@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/22 09:34:51 by yuknakas		  #+#	#+#			 */
/*   Updated: 2025/02/14 10:19:29 by yuknakas		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_next_line(char *line_buffer)
{
	char	*next_buffer;
	char	*new_line;
	int		new_len;

	if (line_buffer == NULL)
		return (NULL);
	if (ft_strchr(line_buffer, '\n') == NULL)
	{
		free(line_buffer);
		return (NULL);
	}
	new_line = ft_strchr(line_buffer, '\n') + 1;
	new_len = ft_strlen(new_line) + 1;
	next_buffer = ft_calloc(new_len, sizeof(char));
	if (next_buffer == NULL)
	{
		free(line_buffer);
		return (NULL);
	}
	ft_strlcpy(next_buffer, new_line, new_len);
	free(line_buffer);
	return (next_buffer);
}

static char	*_makeline(const char *line_buffer)
{
	char	*current_line;
	int		line_len;

	if (line_buffer == NULL)
		return (NULL);
	if (ft_strchr(line_buffer, '\n') != NULL)
		line_len = (ft_strchr(line_buffer, '\n') - line_buffer) + 1;
	else
		line_len = ft_strlen(line_buffer);
	current_line = ft_calloc(line_len + 1, sizeof(char));
	if (current_line == NULL)
		return (NULL);
	ft_strlcpy(current_line, line_buffer, line_len + 1);
	return (current_line);
}

static char	*_copybuffer(char *line_buffer, char *read_buffer)
{
	char	*new_array;

	new_array = ft_strjoin(line_buffer, read_buffer);
	free(line_buffer);
	return (new_array);
}

static char	*_readfile(int fd, char *line_buffer)
{
	char	*read_buffer;
	int		read_check;

	if (line_buffer == NULL)
		line_buffer = ft_calloc(1, 1);
	read_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read_check = 1;
	while (0 < read_check)
	{
		if (read_buffer != NULL)
			read_check = read(fd, read_buffer, BUFFER_SIZE);
		if (read_check == -1 || line_buffer == NULL || read_buffer == NULL)
		{
			free(read_buffer);
			free(line_buffer);
			return (NULL);
		}
		read_buffer[read_check] = '\0';
		line_buffer = _copybuffer(line_buffer, read_buffer);
		if (ft_strchr(read_buffer, '\n') != NULL)
			break ;
	}
	free(read_buffer);
	return (line_buffer);
}

char	*get_next_line(int fd, int clean)
{
	static char	*line_buffer[1023];
	char		*current_line;

	if (clean == YES)
		gnl_free_double_pointer(line_buffer);
	if (fd < 0 || BUFFER_SIZE <= 0 || clean == YES)
		return (NULL);
	line_buffer[fd] = _readfile(fd, line_buffer[fd]);
	if (line_buffer[fd] == NULL)
		return (NULL);
	if (line_buffer[fd][0] == '\0')
	{
		free (line_buffer[fd]);
		line_buffer[fd] = NULL;
		return (NULL);
	}
	current_line = _makeline(line_buffer[fd]);
	line_buffer[fd] = _next_line(line_buffer[fd]);
	return (current_line);
}
