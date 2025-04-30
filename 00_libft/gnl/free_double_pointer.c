/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   free_double_pointer.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yuknakas <yuknakas@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/14 10:17:08 by yuknakas		  #+#	#+#			 */
/*   Updated: 2025/02/14 10:18:55 by yuknakas		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_free_double_pointer(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
