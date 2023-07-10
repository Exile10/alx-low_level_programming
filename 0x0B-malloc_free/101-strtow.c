#include "main.h"
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

char **strtow(char *str);

char **strtow(char *str)
{
  if (str == NULL || *str == '\0')
    return NULL;

  int len = strlen(str);
  int word_count = 0;
  int word_start = 0;

  char **words = malloc((MAX_WORDS + 1) * sizeof(char *));
  if (words == NULL)
    return NULL;

  for (int i = 0; i < len; i++)
  {
    if (str[i] == ' ')
    {
      if (i > 0 && str[i - 1] != ' ')
      {
        int word_len = i - word_start;
        words[word_count] = malloc((word_len + 1) * sizeof(char));
        if (words[word_count] == NULL)
        {
          for (int j = 0; j < word_count; j++)
            free(words[j]);
          free(words);
          return NULL;
        }
        strncpy(words[word_count], &str[word_start], word_len);
        words[word_count][word_len] = '\0';
        word_count++;

        if (word_count >= MAX_WORDS)
          break;
      }
      word_start = i + 1;
    }
  }

  if (len > 0 && str[len - 1] != ' ')
  {
    int word_len = len - word_start;
    words[word_count] = malloc((word_len + 1) * sizeof(char));
    if (words[word_count] == NULL)
    {
      for (int j = 0; j <= word_count; j++)
        free(words[j]);
      free(words);
      return NULL;
    }
    strncpy(words[word_count], &str[word_start], word_len);
    words[word_count][word_len] = '\0';
    word_count++;
  }

  words[word_count] = NULL;
  return words;
}

