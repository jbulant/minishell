/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getusr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 00:53:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/26 16:24:04 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// void		tkn_add(t_token **head, t_token *nxt)
// {
// 	if (TOKEN_DEBUG && nxt)
// 	{
// 		if (nxt->type == WORD)
// 			ft_putstr("[ ADD ] < WORD > ");
// 		else
// 			ft_putstr("[ ADD ] < SEMICOLON >");
// 		ft_putendl(nxt->content ? nxt->content : "");
// 	}
// 	return (ft_lstadd((t_list**)head, (t_list*)nxt));
// }
//
// t_token		*tkn_new(char *content, t_tkn_type type)
// {
// 	t_token		*new;
// 	size_t		content_size;
//
// 	content_size = 0;
// 	if (!(new = (t_token *)ft_memalloc(sizeof(t_token))))
// 		return (NULL);
// 	if (content != NULL && (new->content = ft_strdup(content)))
// 		content_size =  ft_strlen(content);
// 	else
// 		new->content = NULL;
// 	new->content_size = content_size;
// 	new->next = NULL;
// 	new->type = type;
// 	return (new);
// }
//
// void		usr_input_init(t_usr_input *input)
// {
// 	ft_bzero(input, sizeof(t_usr_input));
// 	ft_stack_init(&input->exec, TOKEN_HEIGHT);
// }
//
// int			case_sc_token(t_usr_input *input, char *word)
// {
// 	char	*sc;
// 	int		t_cnt;
//
// 	t_cnt = 0;
// 	while ((sc = ft_strchr(word, ';')))
// 	{
// 		*sc = '\0';
// 		if (sc > word)
// 		{
// 			tkn_add(&input->token, tkn_new(word, WORD));
// 			t_cnt++;
// 		}
// 		tkn_add(&input->token, tkn_new(NULL, SEMICOLON));
// 		t_cnt++;
// 		word = sc + 1;
// 	}
// 	if (*word)
// 	{
// 		tkn_add(&input->token, tkn_new(word, WORD));
// 		t_cnt++;
// 	}
// 	return (t_cnt);
// }
//
// int			uio_token_create(t_usr_input *input)
// {
// 	char		**word_tab;
// 	int			t_cnt;
// 	int			i;
//
// 	word_tab = ft_create_wordtab(input->buffer, new_chrmsk("\t\v\n\f\r "));
// 	if (!word_tab)
// 		return (-1);
// 	t_cnt = 0;
// 	i = -1;
// 	while (word_tab[++i])
// 	{
// 		if (ft_strchr(word_tab[i], ';'))
// 			t_cnt += case_sc_token(input, word_tab[i]);
// 		else
// 			tkn_add(&input->token, tkn_new(word_tab[i], WORD));
// 	}
// 	input->token_cnt = t_cnt + i;
// 	return (0);
// }
//
// t_list		*create_new_get(t_usr_input *input, size_t avlen, size_t total_len)
// {
// 	t_token		*tmp;
// 	t_inblock	*get;
// 	t_list		*ret;
// 	size_t		i;
//
// 	if (!(get = (t_inblock*)ft_memalloc(sizeof(t_inblock)))
// 	|| !(ret = (t_list*)ft_memalloc(sizeof(t_list)))
// 	|| !(get->input = ft_strnew(total_len + avlen))
// 	|| !(get->argv = ft_arstrnew(avlen)))
// 		return (NULL);
// 	get->input_len = total_len + avlen;
// 	get->argv_len = avlen;
// 	total_len = 0;
// 	i = -1;
// 	while (++i < avlen)
// 	{
// 		tmp = input->token;
// 		get->argv[i] = get->input + total_len;
// 		ft_strcpy(get->argv[i], tmp->content);
// 		total_len += (tmp->content_size + 1);
// 		input->token = tmp->next;
// 		free(tmp->content);
// 		free(tmp);
// 	}
// 	ret->content = get;
// 	ret->content_size = sizeof(t_inblock);
// 	if (TOKEN_DEBUG)
// 	{
// 		for (int i = 0; get->argv[i]; i++)
// 		{
// 			ft_putstr("[ARGV]<");
// 			ft_putnbr(i);
// 			ft_putstr("> ");
// 			ft_putendl(get->argv[i]);
// 		}
// 	}
// 	return (ret);
// }
//
// int			uio_parse_token(t_usr_input *input)
// {
// 	t_token		*tmp;
// 	size_t		avlen;
// 	size_t		total_len;
//
// 	avlen = 0;
// 	while (input->token)
// 	{
// 		total_len = 0;
// 		tmp = input->token;
// 		while (tmp && tmp->type == WORD)
// 		{
// 			total_len += tmp->content_size;
// 			tmp = tmp->next;
// 			avlen++;
// 		}
// 		if (avlen)
// 		{
// 			ft_lstadd(&input->get, create_new_get(input, avlen, total_len));
// 		}
// 		if (input->token && input->token->type != WORD)
// 		{
// 			tmp = input->token->next;
// 			free(input->token);
// 			input->token = tmp;
// 		}
// 	}
// 	return (0);
// }
//
// int			get_usr_input(t_minishell *msh)
// {
// 	int		ret;
//
// 	ret = 0;
// 	ft_putstr("$> ");
// 	if (get_next_line(0, &msh->input.buffer) == -1)
// 		return (-1);
// 	msh->input.buff_len = ft_strlen(msh->input.buffer);
// 	if (uio_token_create(&msh->input) != -1)
// 		ret = uio_parse_token(&msh->input);
// 	// ret = parse_input(msh->input.buffer, msh);
// 	ft_memdel((void**)&msh->input.buffer);
// 	return (ret);
// }
//
int			get_usr_input(t_minishell *msh)
{
	char	*input;
	int		ret;

	ft_putstr("$> ");
	if (!get_next_line(0, &input))
		return (-1);
	ret = parse_input(input, msh);
	free(input);
	return (ret);
}
