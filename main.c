/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:46:04 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/05/28 22:58:34 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

char	**draw_board(int size)
{
	char	**board;
	int		i;

	board = ft_calloc((size + 1), sizeof(char *));
	i = 0;
	if (!board)
		return (NULL);
	while (board[i])
	{
		board[i] = ft_calloc((size + 1), sizeof(char));
		i++;
	}
	return (board);
}

void	insert_num()
{
	// char		**board;
	// int			i;
	// static char	num;	

	// board = draw_board(4);
	// num = '1';
	// board[0][0] = num;
	// i = 0;
	// while (board[0][i])
	// {
	// 	board[0][i++] = num++;
	// 	printf("%s\n", board[0]);
	// }

}

char	*remove_spce(char *argv)
{	
	int		i;
	int		a;
	char	*temp;

	i = 0;
	a = 0;
	temp = ft_calloc(17, sizeof(char));
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			temp[a++] = argv[i];
		i++;
	}
	temp[a] = '\0';
	return (temp);
}

int	size_error_checker(char *str)
{
	printf("strlen %d\n", ft_strlen(str) % 4);
	if (ft_strlen(str) % 4 == 0)
	{
		printf("%s\n", str);
		return (1);
	}
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	int		a;
	char	*str;

	if (argc != 2)
		return (0);
	str = remove_spce(argv[1]);
	if (size_error_checker(str) == 0)
		return (1);
}
