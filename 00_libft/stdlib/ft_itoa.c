/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yuknakas <yuknakas@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/17 13:53:13 by yuknakas		  #+#	#+#			 */
/*   Updated: 2025/01/14 14:11:53 by yuknakas		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../header/libft.h"

static int	_dignbr(long nb)
{
	int		count;

	count = 1;
	if (nb < 0)
	{
		nb *= -1;
		count += 1;
	}
	while (10 <= nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*ans;
	long	nb;

	nb = (long)n;
	i = _dignbr(n);
	ans = malloc((i + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	ans[i] = '\0';
	if (nb < 0)
	{
		ans[0] = '-';
		nb *= -1;
	}
	while (10 <= nb)
	{
		ans[i - 1] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	ans[i - 1] = (nb % 10) + '0';
	return (ans);
}
