/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:54:29 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/01 20:27:34 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../../../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>

int	checkvarend(char args)
{
	if (ft_isalnum(args) || ft_strchr(VARSYM, args))
		return (E_OK);
	return (E_KO);
}

int	checkvarfront(char args)
{
	if (ft_isalpha(args) || ft_strchr(VARSYM, args))
		return (E_OK);
	return (E_KO);
}

int	getoperation(t_arg *argt)
{
	int		i;

	if (argt->arg[argt->x] != VARCH)
		return (E_ERR);
	if ((argt->x && ft_strchr(FESC, argt->arg[argt->x - 1]))
		|| ft_strchr(RESC, argt->arg[argt->x + 1]))
		return (E_ERR);
	i = 0;
	++argt->x;
	while (SUBSTR[i] && argt->arg[argt->x] != SUBSTR[i])
		++i;
	--argt->x;
	return (i);
}

char	*getvarval(char *args, int size, t_hash *hst)
{
	char	*varval;

	args = ft_strndup(args, size);
	varval = hst->hash(args, hst->hashtb);
	free(args);
	return (varval);
}

char	*getvar(t_arg *argt, int size, t_hash *hst)
{
	char	*varval;
	
	if (!size)
		return (NULL);
	varval = getvarval((char *)argt->arg + argt->x, size, hst);
	if (!varval)
	{
		ft_putstr(MALLOCERROR);
		exit(-1);
	}
	argt->x += size;
	return (varval);
}

char	*subbraces(t_arg *argt, char end, t_hash *hst)
{
	int	size;

	size = ++argt->x;
	if (checkvarfront(argt->arg[size]))
		return (NULL);
	while (argt->arg[size] && argt->arg[size] != end
		&& !checkvarend(*(argt->arg + size)))
		++size;
	if (size == argt->x || argt->arg[size] != end)
		return (ft_perror("Command not found"));
	size -= argt->x;
	return (getvar(argt, size, hst));
}

char	*subpid(t_arg *argt)
{
	argt->x += I_PID;
	return (ft_itoa(getpid()));
}

char	*subexicd(t_arg *argt, char end, t_hash *hst)
{
	return (ft_strdup("000"));
}

char	*subvar(t_arg *argt, t_hash *hst)
{
	int	size;

	size = ++argt->x;
	if (checkvarfront(argt->arg[size]))
		return (NULL);
	while (argt->arg[size] && !checkvarend(*(argt->arg + size)))
		++size;
	if (size == argt->x)
		return (NULL);
	size -= argt->x;
	return (getvar(argt, size, hst));
}

char	*getvalstr(t_arg *argt, t_hash *hst, int oper)
{
	if (oper < 0)
		return (NULL);
	switch (oper)
	{
	case (I_BRACES):
		return (subbraces(argt, SUBEND[I_BRACES], hst));
	case (I_EXTSTS):
		return (subexicd(argt, SUBSTR[I_EXTSTS], hst));
	case (I_PID):
		return (subpid(argt));		
	}
	return (subvar(argt, hst));
}

t_llist	*getvars(t_arg *argt, t_hash *hst)
{
	char	*tmp;
	t_llist	*strll;

	strll = NULL;
	while (argt->arg[argt->x])
	{
		tmp = getvalstr(argt, hst, getoperation(argt));
		if (tmp)
		{
			llistadd_back(&strll, llistnewnode(tmp));
			argt->size += ft_strlen(tmp);
		}
		else
		{
			++argt->x;
			++argt->size;
		}
	}
	return (strll);
}

void	cpydata(char *args, char *str, t_arg *argt, t_llist *strll)
{
	argt->x = 0;
	while (*str && argt->x < argt->size)
	{
		if (getoperation(argt) >= 0)
		{
			argt->x = ft_strcpy(args + argt->x, (char *)(strll->data)) - args;
			while (*str && !ft_strchr(RESC, *str))
				++str;
		}
		else
		{
			args[argt->x] = *str;
			++str;
			++argt->x;
		}
	}
}

char	*getargs(char *str, t_hash *hst)
{
	t_arg	argt;
	char	*args;
	t_llist	*strll;

	argt.arg = str;
	argt.size = 0;
	argt.x = 0;
	strll = getvars(&argt, hst);
	args = malloc((argt.size + 1) * sizeof(char));
	if (!args)
	{
		ft_putstr(MALLOCERROR);
		exit(-1);
	}
	args[argt.size] = 0;
	cpydata(args, str, &argt, strll);
	llistclear(&strll, free);
	return (args);
}

char	*strhandler(char *str, t_hash *hst)
{
	if (!str || !hst || !(*str))
		return (ft_perror("ERROR!!! EMPTY ARGUMENT!!!"));
	return (getargs(str, hst));
}

void	*hash(t_cchar *key, char **hashtb)
{
	return ((void *)ft_strdup("ABC"));
}

int	main()
{
	char	*tmp;
	char	*line;
	t_hash	hst;
	
	hst.hash = hash;
	hst.hashtb = NULL;
	while (1)
	{
		line = readline("Pablo Escobar:\t");
		if (!ft_strcmp(line, "exit"))
			break ;
		printf("%s\n", line);
		tmp = strhandler(line, &hst);
		printf("|%s|\n", tmp);
		free(tmp);
		free(line);
	}
	return (0);
}

// int	getvarend(char *args, char end)
// {
// 	int	size;

// 	size = 0;
// 	while (*args && *args != end)
// 	{
// 		++args;
// 		++size;
// 	}
// 	if (!(*args))
// 		return (0);
// 	return (size);
// }

// static int	checkvarname(char *args, int size, char var)
// {
// 	if (*args != var)
// 		return (E_KO);
// 	if (size && *(args - 1) == BKSLASH)
// 		return (E_KO);
// 	if (checkvarend(++args) == E_OK)
// 		return (E_KO);
// 	return (E_OK);
// }

// char	*braceshndlr(t_arg *argt, t_hash *hst)
// {
// 	return (getvar(argt, getvarend(*args, BRACES[I_RBRACES]), hst));
// }

// char	*pidhndlr(char **args, t_hash *hst)
// {
// 	if (*((*args) + 1) != VARCH)
// 		return (NULL);
// 	return (getvar(args, ft_strlen(PID), hst));
// }

// char	*varhndlr(char **args, t_hash *hst)
// {
// 	int		size;

// 	size = 0;
// 	while (checkvarend((*args)[size]))
// 		++size;
// 	return (getvar(args, size, hst));
// }
