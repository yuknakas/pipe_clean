/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strtrim.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yuknakas <yuknakas@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/17 12:48:40 by yuknakas		  #+#	#+#			 */
/*   Updated: 2024/11/17 12:48:40 by yuknakas		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../header/libft.h"

static int	yn_setcheck(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && yn_setcheck(s1[start], set))
		start++;
	while (start < end && yn_setcheck(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, (end - start)));
}
