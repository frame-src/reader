#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct	s_args
{
	char	*split_char;			//string of value that should split the words (like spaces for example);
	char	**single_word;			//string of char that if read should create a single word ex: |echo| should return => [|][echo][|];
	char	*ignore;				//string of special char that should "ignore" the split if at the previous index ex: \\ in bash ;
	char	*ign_char_inside;		//special char that initialize a string that should be ignored by the function split ex: "ehci uwhe" should return a single word;
}	t_args;



/*	UTILS	*/
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c); // MOUAD ft_strchr libft

/*	WORD COUNT	*/
int		found_split_char(int i, bool *word);
int		found_word(bool *word, int i, int *word_count);
int		found_char_to_ignore(int *word_count, int i, char *string, bool *word);
int		word_count(char *string, t_args *args);
int		jump_char_inside(char *string, char *special, int *word_count, bool *word);
int		single_word_strchr( char **single_word, char *string);

#endif