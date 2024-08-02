/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:54:29 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/02 16:08:13 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>

#define T_ARG(argtll)	((t_arg *)((argtll)->data))

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

int	getoperation(char **args, int pos, char **substr)
{
	int		i;

	if (**args != VARCH)
		return (E_ERR);
	if ((pos && ft_strchr(FESC, (*args)[1])) || ft_strchr(RESC, (*args)[1]))
		return (E_ERR);
	i = 0;
	while (substr[i] && !ft_strlcmp(*args, substr[i]))
		++i;
	if (i < I_SUBSTRSIZE)
		*args += ft_strlen(substr[i]);
	else
		++(*args);
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

char	*getvar(char **args, int size, t_hash *hst)
{
	char	*varval;
	
	if (!size)
		return (NULL);
	varval = getvarval(*args, size, hst);
	if (!varval)
	{
		ft_putstr(MALLOCERROR);
		exit(-1);
	}
	*args += size;
	return (varval);
}

char	*subbraces(char **args, char *end, t_hash *hst)
{
	int		size;
	char	*res;

	size = 0;
	if (checkvarfront(**args))
		return (NULL);
	while ((*args)[size] && !ft_strlcmp(*args, end)
		&& !checkvarend((*args)[size]))
		++size;
	if (!size || !ft_strlcmp(*args, end))
		return (ft_perror("Command not found"));
	res = getvar(args, size, hst);
	++(*args);
	return (res);
}

char	*subexicd(char **args, t_hash *hst)
{
	return (ft_strdup("000"));
}

char	*subvar(char **args, t_hash *hst)
{
	int	size;

	if (checkvarfront(**args))
		return (NULL);
	size = 0;
	while ((*args)[size] && !checkvarend((*args)[size]))
		++size;
	if (!size)
		return (NULL);
	return (getvar(args, size, hst));
}

char	*getvalstr(char **args, int oper, t_strtosub *strtosub, t_hash *hst)
{
	if (oper < 0)
		return (NULL);
	switch (oper)
	{
	case (I_BRACES):
		return (subbraces(args, strtosub->subend[I_BRACES], hst));
	case (I_EXTSTS):
		return (subexicd(args, hst));
	case (I_PID):
		return (ft_itoa(getpid()));		
	}
	return (subvar(args, hst));
}

void	setargt(t_arg *argt, char *str, int x, int size)
{
	argt->arg = str;
	argt->x = x;
	argt->size = size;
}

t_llist	*getvars(char *args, t_strtosub *strtosub, t_hash *hst)
{
	char	*argsf;
	t_arg	argt;
	t_llist	*strll;

	strll = NULL;
	setargt(&argt, NULL, 0, 0);
	argsf = args;
	while (*args)
	{
		argt.arg = getvalstr(&args, getoperation(&args, argt.x,
			strtosub->substr), strtosub, hst);
		if (!argt.arg)
		{
			++args;
			++argt.size;
			continue ;
		}
		llistadd_back(&strll, llistnewnode(crtargt(argt.arg, argt.x, argt.size - argt.x)));
		setargt(&argt, NULL, args - argsf, args - argsf);
	}
	llistadd_back(&strll, llistnewnode(crtargt(argt.arg, argt.x, argt.size - argt.x)));
	return (strll);
}

int		getfullsize(char *args, t_llist *strll)
{
	int	size;

	size = 0;
	while (strll && strll->next)
	{
		size += T_ARG(strll)->size + ft_strlen(T_ARG(strll)->arg);
		strll = strll->next;
	}
	size += ft_strlen(args + T_ARG(strll)->size + T_ARG(strll)->x);
	return (size);
}

void	cpydata(char *args, char *str, t_llist *strll)
{
	while (*str && strll)
	{
		args = ft_strncpy(args, str + T_ARG(strll)->x, T_ARG(strll)->size);
		args = ft_strcpy(args, T_ARG(strll)->arg);
		strll = strll->next;
	}
	ft_strncpy(args, str + T_ARG(strll)->x, T_ARG(strll)->size);
}

char	*getargs(char *str, t_strtosub *strtosub, t_hash *hst)
{
	int		size;
	char	*args;
	t_llist	*strll;

	strll = getvars(str, strtosub, hst);
	size = getfullsize(str, strll);
	args = malloc((size + 1) * sizeof(char));
	if (!args)
	{
		ft_putstr(MALLOCERROR);
		exit(-1);
	}
	cpydata(args, str, strll);
	llistclear(&strll, freeargt);
	return (args);
}

char	*strhandler(char *str, char **substr, char **subend, t_hash *hst)
{
	t_strtosub	strtosub;

	strtosub.substr = substr;
	strtosub.subend = subend;
	if (!str || !hst || !(*str))
		return (ft_perror("ERROR!!! EMPTY ARGUMENT!!!"));
	return (getargs(str, &strtosub, hst));
}

void	*hash(t_cchar *key, char **hashtb)
{
	return ((void *)ft_strdup("ABC"));
}

int	main()
{
	char	*argt;
	char	*line;
	char	**substr;
	char	**subend;
	t_hash	hst;
	
	hst.hash = hash;
	hst.hashtb = NULL;
	substr = ft_split(SUBSTR, SPLTCH);
	subend = ft_split(SUBEND, SPLTCH);
	while (1)
	{
		line = readline("Pablo Escobar:\t");
		if (!ft_strcmp(line, "exit"))
			break ;
		printf("%s\n", line);
		argt = strhandler(line, substr, subend, &hst);
		printf("|%s|\n", argt);
		free(argt);
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



// int	checkvarend(char args)
// {
// 	if (ft_isalnum(args) || ft_strchr(VARSYM, args))
// 		return (E_OK);
// 	return (E_KO);
// }

// int	checkvarfront(char args)
// {
// 	if (ft_isalpha(args) || ft_strchr(VARSYM, args))
// 		return (E_OK);
// 	return (E_KO);
// }

// int	getoperation(t_arg *argt)
// {
// 	int		i;

// 	if (argt->arg[argt->x] != VARCH)
// 		return (E_ERR);
// 	if ((argt->x && ft_strchr(FESC, argt->arg[argt->x - 1]))
// 		|| ft_strchr(RESC, argt->arg[argt->x + 1]))
// 		return (E_ERR);
// 	i = 0;
// 	++argt->x;
// 	while (SUBSTR[i] && argt->arg[argt->x] != SUBSTR[i])
// 		++i;
// 	--argt->x;
// 	return (i);
// }

// char	*getvarval(char *args, int size, t_hash *hst)
// {
// 	char	*varval;

// 	args = ft_strndup(args, size);
// 	varval = hst->hash(args, hst->hashtb);
// 	free(args);
// 	return (varval);
// }

// char	*getvar(t_arg *argt, int size, t_hash *hst)
// {
// 	char	*varval;
	
// 	if (!size)
// 		return (NULL);
// 	varval = getvarval((char *)argt->arg + argt->x, size, hst);
// 	if (!varval)
// 	{
// 		ft_putstr(MALLOCERROR);
// 		exit(-1);
// 	}
// 	argt->x += size;
// 	return (varval);
// }

// char	*subbraces(t_arg *argt, char end, t_hash *hst)
// {
// 	int	size;

// 	size = ++argt->x;
// 	if (checkvarfront(argt->arg[size]))
// 		return (NULL);
// 	while (argt->arg[size] && argt->arg[size] != end
// 		&& !checkvarend(*(argt->arg + size)))
// 		++size;
// 	if (size == argt->x || argt->arg[size] != end)
// 		return (ft_perror("Command not found"));
// 	size -= argt->x;
// 	return (getvar(argt, size, hst));
// }

// char	*subpid(t_arg *argt)
// {
// 	argt->x += I_PID;
// 	return (ft_itoa(getpid()));
// }

// char	*subexicd(t_arg *argt, char end, t_hash *hst)
// {
// 	return (ft_strdup("000"));
// }

// char	*subvar(t_arg *argt, t_hash *hst)
// {
// 	int	size;

// 	size = ++argt->x;
// 	if (checkvarfront(argt->arg[size]))
// 		return (NULL);
// 	while (argt->arg[size] && !checkvarend(*(argt->arg + size)))
// 		++size;
// 	if (size == argt->x)
// 		return (NULL);
// 	size -= argt->x;
// 	return (getvar(argt, size, hst));
// }

// char	*getvalstr(t_arg *argt, t_hash *hst, int oper)
// {
// 	if (oper < 0)
// 		return (NULL);
// 	switch (oper)
// 	{
// 	case (I_BRACES):
// 		return (subbraces(argt, SUBEND[I_BRACES], hst));
// 	case (I_EXTSTS):
// 		return (subexicd(argt, SUBSTR[I_EXTSTS], hst));
// 	case (I_PID):
// 		return (subpid(argt));		
// 	}
// 	return (subvar(argt, hst));
// }
