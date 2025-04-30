/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strdup.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yuknakas <yuknakas@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/17 12:47:38 by yuknakas		  #+#	#+#			 */
/*   Updated: 2024/11/17 12:47:38 by yuknakas		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strdup(const char *src)
{
	int		length;
	char	*dest;

	length = ft_strlen(src);
	dest = malloc(length + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, src, length + 1);
	return (dest);
}
