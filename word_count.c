#include "reader.h"


int	found_split_char(int i, bool *word)
{
	i++;
	(*word) = false;
	return (i);
}

int	found_char_to_ignore(int *word_count, int i, char *string, bool *word)
{
	if((*word) == false)
		(*word_count)++;
	(*word) = true;
	if(string[i + 1])
		return(i = i + 2);
	else
	{
		(*word_count)++;
		i++;
	}
	return (i);
}

int	found_word(bool *word, int i, int *word_count)
{
	if((*word) == false)
		(*word_count)++;
	(*word) = true;
	return (++i); 
}

int	word_count(char *string, t_args *args)
{
	int		i;
	int		word_count;
	bool	word;

	i = 0;
	word = false;
	word_count = 0;
	while(string[i])
	{
		if(ft_strchr(args->ign_char_inside, string[i]) != NULL)
			i += jump_char_inside(&string[i], args->ign_char_inside, &word_count, &word);
		else if(ft_strchr(args->ignore, string[i])!= NULL)
			i = found_char_to_ignore(&word_count, i, string, &word);
		else if(single_word_strchr(args->single_word, &string[i]) > 0)
		{
			i += (single_word_strchr(args->single_word, &string[i]));
			word_count++;
			word = false;
		}
		else if (ft_strchr(args->split_char, string[i]) != NULL)
			i = found_split_char( i, &word);
		else
			i = found_word(&word, i, &word_count);
	}
	return (word_count);
}

// int	word_count(char *string, t_args *args)
// {
// 	int		i;
// 	int		word_count;
// 	bool	word;

// 	i = 0;
// 	word = false;
// 	word_count = 0;
// 	while(string[i])
// 	{
// 		if(ft_strchr(args->ign_char_inside, string[i]) != NULL)
// 		{
// 			printf("char IGNORED: %c ", string[i]);
// 			i += jump_char_inside(&string[i], args->ign_char_inside, &word_count, &word);
// 			printf("till index: %d word_count: %d\n", i, word_count);
// 		}
// 		else if(ft_strchr(args->ignore, string[i])!= NULL)
// 		{
// 			printf("found \\: %c at index: %d ", string[i], i);
// 			i = found_char_to_ignore(&word_count, i, string, &word);
// 			printf("word_count: %d\n", word_count);
// 		}
// 		else if(single_word_strchr(args->single_word, &string[i]) > 0)
// 		{
// 			printf("found a SINGLE WORD: %c at index: %d ", string[i], i);
// 			i += (single_word_strchr(args->single_word, &string[i]));
// 			word_count++;
// 			word = false;
// 			printf("word_count: %d\n", word_count);
// 		}
// 		else if (ft_strchr(args->split_char, string[i]) != NULL)
// 		{
// 			printf("found a SPACE: %c at index: %d ", string[i], i);
// 			i = found_split_char( i, &word);
// 			printf("word_count should stay the same: %d\n", word_count);
// 		}
// 		else
// 		{
// 			printf("found a WORD: %c at index: %d ", string[i], i);
// 			i = found_word(&word, i, &word_count);
// 			printf("if true == %d word_count should stay the same: %d\n", word, word_count);
// 		}
// 	}
// 	return (word_count);
// }