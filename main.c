/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:46:04 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/05/29 18:17:22 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

char	**draw_board(int size)
{
	char	**board;
	int		i;

	board = ft_calloc((size + 1), sizeof(char *));
	i = 0;
	if (!board)
		return (NULL);
	while (i < size)
	{
		board[i] = ft_calloc((size + 1), sizeof(char));
		i++;
	}
	return (board);
}

int	check_left(t_list *list, int y, int x)
{
	int	j;
	int	view;
	int	count;

	j = 0;
	view = 0;
	count = 0;
	while (j < list->size)
	{
		if (list->board[y][j] > view)
		{
			view = list->board[y][j];
			count++;
		}
		j++;
	}
	if (count + '0' != list->input[(2 * list->size) + y])
		return (0);
	else
		return (1);
}

int	check_right(t_list *list, int y, int x)
{
	int	j;
	int	view;
	int	count;

	j = list->size - 1;
	view = 0;
	count = 0;
	while (j >= 0)
	{
		if (list->board[y][j] > view)
		{
			view = list->board[y][j];
			count++;
		}
		j--;
	}
	if (count + '0' != list->input[(3 * list->size) + y])
		return (0);
	else
		return (1);
}

int	check_top(t_list *list, int y, int x)
{
	int	i;
	int	view;
	int	count;

	i = 0;
	view = 0;
	count = 0;
	while (i < list->size)
	{
		if (list->board[i][x] > view)
		{
			view = list->board[i][x];
			count++;
		}
		i++;
	}
	if (count + '0' != list->input[x])
		return (0);
	else
		return (1);
}

int	check_bottom(t_list *list, int y, int x)
{
	int	i;
	int	view;
	int	count;

	i = list->size - 1;
	view = 0;
	count = 0;
	while (i >= 0)
	{
		if (list->board[i][x] > view)
		{
			view = list->board[i][x];
			count++;
		}
		i--;
	}
	if (count + '0' != list->input[list->size + x])
		return (0);
	else
		return (1);
}

int	check(t_list *list, int y, int x)
{
	int	i;
	int	j;
		
	i = 0;
	j = 0;
	while (j < x)
	{
		if (list->board[y][j] == list->board[y][x])
			return (0);
		j++;
	}
	while (i < y)
	{
		if (list->board[i][x] == list->board[y][x])
			return (0);
		i++;
	}
	if (x == (list->size - 1))
	{
		
		if(!check_left(list, y, x) || !check_right(list, y, x))
			return (0);
	}
	if (y == (list->size - 1))
	{
		if (!check_top(list, y, x) || !check_bottom(list, y, x))
			return (0);
	}
	return (1);
}

int	solution(t_list	*list, int y, int x)
{
	int	ans;
	int a = 0;
	static int i = 0;
	
	if (x == list->size)
	{
		x = 0;
		y++;
		if (y == list->size)
			return (1);
	}
	ans = 1;
	while (ans <= list->size)
	{
		list->board[y][x] = ans + '0';
		i++;
		printf("Perm: %d\n", i);
		if (check(list, y, x) == 1)
		{
			if (solution(list, y, x + 1) == 1)
				return (1);
		}
		ans++;
	}
	list->board[y][x] = '\0';
	return (0);
}

// int	solution(t_list	*list)
// {
// 	int	ans;
// 	int a = 0;
	
// 	list->x++;
// 	if (list->x == list->size)
// 	{
// 		list->x = 0;
// 		list->y++;
// 		if (list->y == list->size)
// 			return (1);
// 	}
// 	ans = 1;
// 	while (ans <= list->size)
// 	{
// 		list->board[list->y][list->x] = ans + '0';
// 		if (check(list) == 1)
// 		{
			
// 			if (solution(list) == 1)
// 				return (1);
// 		}
// 		ans++;
// 	}
// 	list->board[list->y][list->x] = '\0';
// 	list->x--;
// 	if (list->x == -1)
// 	{
// 		list->y--;
// 		list->x = list->size - 1;
// 	}
// 	return (0);
// }

char	*remove_spce(char *argv)
{	
	int		i;
	int		a;
	char	*temp;

	i = 0;
	a = 0;
	temp = ft_calloc(ft_strlen(argv) + 1, sizeof(char));
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
	if (ft_strlen(str) % 4 == 0)
		return (1);
	else
		return (0);
}

void	initialize_varia(t_list *list)
{
	list->size = (ft_strlen(list->input) / 4);
	list->board = draw_board(list->size);
}

int	main(int argc, char *argv[])
{
	int		a;
	char	*str;
	char	**board;
	t_list	list;

	a = 0;
	if (argc != 2)
		return (0);
	list.input = remove_spce(argv[1]);
	initialize_varia(&list);
	if (size_error_checker(list.input) == 0)
	{
		printf("input: %s\n", list.input);
		printf("HERE\n");
		return (1);
	}
	if (solution(&list, 0, 0) == 1)
	{
		printf("SUCCESS\n");
		while (a < list.size)
		{
			printf("%s\n", list.board[a]);
			a++;
		}
	}
	else
	{
		printf("%s\n", list.board[0]);
		printf("%s\n", list.board[1]);
		printf("%s\n", list.board[2]);
		printf("%s\n", list.board[3]);
		printf("solution fail\n");
	}
}
