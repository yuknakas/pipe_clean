/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strncmp.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yuknakas <yuknakas@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/17 12:48:10 by yuknakas		  #+#	#+#			 */
/*   Updated: 2024/11/17 12:48:10 by yuknakas		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ans;
	size_t	i;

	i = 0;
	ans = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	ans = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (ans);
}
