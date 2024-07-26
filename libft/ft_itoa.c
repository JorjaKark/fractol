/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:25:15 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 18:13:51 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*it(char *str, int n, int num_digits, int total_digits)
{
	int	flag;

	flag = 0;
	if (n == -2147483648)
	{
		flag = 1;
		n = -2147483647;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while ((num_digits > 0 && str[0] != '-')
		|| (num_digits > 1 && str[0] == '-'))
	{
		num_digits--;
		str[num_digits] = n % 10 + 48;
		n = n / 10;
	}
	if (flag)
		str[total_digits - 1]++;
	return (str);
}

char	*ft_itoa(int n)
{
	int		num_digits;
	char	*str;
	int		i;
	int		total_digits;

	num_digits = 0;
	i = n;
	if (i <= 0)
		num_digits++;
	while (i != 0)
	{
		i = i / 10;
		num_digits++;
	}
	total_digits = num_digits;
	str = (char *)malloc((num_digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[num_digits] = '\0';
	return (it(str, n, num_digits, total_digits));
}
/*                                                               
int     main(void)
{    
	puts(ft_itoa(156));
	return 0;
}
*/
