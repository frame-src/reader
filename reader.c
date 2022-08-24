#include "reader.h"

char *create_the_word(char *string, int n)
{
	int	i;

	i = 0;
	char *new_string;
	new_string = malloc(n);
	if(new_string == NULL)
		return NULL;
	new_string[n] = '\0';
	while(i < n)
	{
		new_string[i] = string[i];
		i++;
	}
	return (new_string);
}

int check_for_word(char *string, t_args *args)
{
	int		i;
	int		word_num;
	bool	word;

	i = 0;
	word = false;
	while(string[i])
	{
		if (ft_strchr(args->ign_char_inside, string[i]) != NULL)
			i += jump_char_inside(&string[i], args->ign_char_inside, &word_num, &word);
		else if (ft_strchr(args->ignore, string[i])!= NULL)
			i = found_char_to_ignore(&word_num, i, string, &word);
		else if (single_word_strchr(args->single_word, &string[i]) > 0)
			return (i);
		else if (ft_strchr(args->split_char, string[i]) != NULL)
		{
			found_split_char( i, &word);
			return (i);
		}
		else
			i = found_word(&word, i, &word_num);
		if (word == false)
			return (i);
	}
	return (i);
}

static char	**fill_the_string(char **split, char *string, t_args *args, int size)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	while(i < size)
	{
		while(string[j])
		{
			if (check_for_word(&string[j], args) > 0)
			{
				n = check_for_word(&string[j], args);
				split[i] = create_the_word(&string[j], n);
				j = j + n;
				break;
			}
			if (single_word_strchr(args->single_word, &string[j]) > 0)
			{
				n = (single_word_strchr(args->single_word, &string[j]));
				split[i] = create_the_word(&string[j], n);
				j = j + n;
				break;
			}
			else
				j++;
		}
		i++;
	}
	return (split);
}

static char	**create_the_string(int size)
{
	char **string;
	string = malloc((sizeof(char *) * size) + 1);
	printf("SIZE = %d",size);
	if(string == NULL)
		return (NULL);
	string[size] = NULL;
		return (string);
	return (string);
}

void print_reader(char **string)
{
	int i;

	i = 0;
	while (string[i])
	{
		printf("\n token %d: \t %s", i + 1, string[i]);
		i++;
	}
}

char	**ft_reader(char *string, t_args *args)
{

	char	**split_string = NULL;
	split_string = create_the_string(word_count(string, args));
	if(split_string == NULL)
		return (NULL);
	split_string = fill_the_string(split_string, string, args, word_count(string, args));
	print_reader(split_string);
	return(split_string);
}

int main ()
{
	t_args args;
	args.split_char = " ";
	args.single_word = (char *[]){"||", "|", "&&", "<<", ">>", "<", ">", NULL};
	args.ignore = (char *)"\\";
	args.ign_char_inside = (char *)"\"'";
	char *string= (char *)"ls|ab|cd|es|gh>smth        more shit \" ||\" || bla bla && << < < >> >";
	char **j = ft_reader(string, &args);
	j = NULL;

	return 0;
}