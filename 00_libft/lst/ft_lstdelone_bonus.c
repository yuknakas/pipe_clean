/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstdelone.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yuknakas <yuknakas@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/20 09:44:23 by yuknakas		  #+#	#+#			 */
/*   Updated: 2024/11/20 09:44:23 by yuknakas		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
