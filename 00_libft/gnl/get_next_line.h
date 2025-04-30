/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yuknakas <yuknakas@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/22 09:35:04 by yuknakas		  #+#	#+#			 */
/*   Updated: 2025/02/14 10:19:11 by yuknakas		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../header/libft.h"

char	*get_next_line(int fd, int clean);
void	gnl_free_double_pointer(char **arr);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif