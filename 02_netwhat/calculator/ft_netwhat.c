/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_netwhat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:35:04 by qmalcom           #+#    #+#             */
/*   Updated: 2020/08/03 21:31:39 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** compile as:
** gcc -o main ft_netwhat.c -L../../01_libft/libft -lft
*/

#include <stdio.h>
#include "libft.h"

/*
** fills last c bits of int number with 1
*/
int fill_from_the_end(int c)
{
	int res;

	res = 0;
	if (c > 0)
	{
		while (c)
			res += 1 << (8 - c--);
	}
	return (res);
}

/*
** fills first c bits of int number with 1
*/
int fill_from_the_beginning(int c)
{
	int res;

	res = 0;
	if (c > 0)
	{
		while (c)
			res += 1 << --c;
	}
	return (res);
}

/*
** bit_mask
** changing input int array (should've 4 elements)
** 1 param - CIDR notation
** 2 param - int array with 4 elements
** 
*/
int *bit_mask(int cidr, int *p)
{
	int i;

	i = 0;
	while (cidr >= 8)
	{
		p[i++] = 255;
		cidr -= 8;
	}
	p[i] = fill_from_the_end(cidr);
	return(p);
}

int num_poss_opt(int *p)
{
	return ((256 - p[3]) * (256 - p[2]) * (256 - p[1]) * (256 - p[0]) - 2);
}

int *broadcast_address(int *ip, int cidr)
{
	int i;
	int *broadcast;

	if (!(broadcast = ft_calloc(4, sizeof(int))))
		return (NULL);
	ft_memcpy(broadcast, ip, 4 * sizeof(int));
	i = 3;
	while (32 - cidr >= 8)
	{
		broadcast[i--] = 255;
		cidr += 8;
	}
	broadcast[i] |= fill_from_the_beginning(32 - cidr);
	return (broadcast);
}

int	*subn_address(int *arr1, int *arr2)
{
	int *res;
	int i;

	i = -1;
	if (!(res = ft_calloc(4, sizeof(unsigned int))))
		return (NULL);
	while (i++ < 4)
		res[i] = arr1[i] & arr2[i]; // logical AND
	return (res);
}

int main(int argc, char** argv)
{
	char **oktets_arr;
	char **cidr;
	int i;
	int ip[4] = {0, 0, 0, 0};
	int mask[4] = {0, 0, 0, 0};
	int *broadcast;
	int *subnet_address;

	i = 0;
	if (argc == 2 || argc == 3)
	{
		oktets_arr = ft_split(argv[1], '.');
		while (*oktets_arr)
				ip[i++] = ft_atoi(*oktets_arr++);
		if (argc == 2)
			printf("address range: %u\n", num_poss_opt(ip));
		if (argc == 3)
		{
			printf("ip address: %d.%d.%d.%d\n\n", ip[0], ip[1], ip[2], ip[3]);
			cidr = ft_split(argv[2], '/');
			bit_mask(ft_atoi(*cidr), mask);
			printf("subnet mask: %d.%d.%d.%d | ", mask[0], mask[1], mask[2], mask[3]);
			printf("address range: %u\n", num_poss_opt(mask));
			subnet_address = subn_address(ip, mask);
			printf("subnet address: %d.%d.%d.%d | ", subnet_address[0], \
			subnet_address[1], subnet_address[2], subnet_address[3]);
			broadcast = broadcast_address(ip, ft_atoi(*cidr));
			printf("broadcast address: %d.%d.%d.%d\n", broadcast[0], \
			broadcast[1], broadcast[2], broadcast[3]);
			printf("address range: %d.%d.%d.%d - %d.%d.%d.%d\n", \
			subnet_address[0], subnet_address[1], \
			subnet_address[2], subnet_address[3], \
			broadcast[0], broadcast[1], \
			broadcast[2], broadcast[3]);
		}
	}
}