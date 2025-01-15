/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:02:46 by jzackiew          #+#    #+#             */
/*   Updated: 2024/12/07 13:25:25 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!src || !dest)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (s < d && d < s + n)
	{
		while (n--)
			d[n] = s[n];
	}
	else
		dest = ft_memcpy(d, s, n);
	return (dest);
}

/* int main()
{
	char str1[100];

	strcpy(str1, "123456789");
	memcpy(str1 + 1, str1, 9);
	printf("MEMCPY: %s \n", str1);
	
	strcpy(str1, "123456789");
	memmove(str1 + 1, str1, 9);
	printf("MEMMOVE: %s \n", str1);
	
	strcpy(str1, "123456789");
	ft_memcpy(str1 + 1, str1, 9);
	printf("FT_MEMCPY: %s \n", str1);

	strcpy(str1, "123456789");
	ft_memmove(str1 + 1, str1, 9);
	printf("FT_MEMMOVE: %s \n", str1);

	return 0;
} */