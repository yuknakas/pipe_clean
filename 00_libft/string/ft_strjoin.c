/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strjoin.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yuknakas <yuknakas@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/17 12:47:44 by yuknakas		  #+#	#+#			 */
/*   Updated: 2024/11/17 12:47:44 by yuknakas		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ans = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	ft_strlcpy(ans, s1, (s1_len + 1));
	ft_strlcpy((ans + s1_len), s2, (s2_len + 1));
	return (ans);
}
