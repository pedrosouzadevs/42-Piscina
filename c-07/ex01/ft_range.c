/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:03:40 by pdro              #+#    #+#             */
/*   Updated: 2024/07/31 13:15:45 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
    int *range;
    int i;

    if (min < 0)
        i = min - max;
    else if (max < 0)
        i = -max - min;
    else if (min >= 0 && max >= 0)
	    i = max - min;
    range = (int *)malloc(i * sizeof(int));
    i = 0;
    if (max < min)
    {
        while ( min == max)
        {
            range[i] = min;
            min--;
            i++;
        }
    }
    else if (min < max)
    {
         while (min == max)
        {
            range[i] = min;
            min++;
            i++;
        }
    }
    return (range);
}

int main()
{
    int min = -1;
    int max = -3;
    int *range = ft_range(min, max);
    int i = 0;
    while (i < max - min)
    {
        printf("%d\n", range[i]);
        i++;
    }
    return 0;
}
