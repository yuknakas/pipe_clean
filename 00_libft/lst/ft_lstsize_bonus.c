/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstsize.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yuknakas <yuknakas@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/20 09:44:35 by yuknakas		  #+#	#+#			 */
/*   Updated: 2024/11/20 09:44:35 by yuknakas		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
