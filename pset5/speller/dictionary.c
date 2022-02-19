// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#include "dictionary.h"

int word_counter = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_index = hash(word);
    node *cursor = table[hash_index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Modified from this one http://www.cse.yorku.ca/~oz/hash.html by Dan Bernstein
    unsigned int hash = 5381;

    while (*word != '\0')
    {
        unsigned char c = tolower(*word);
        hash = ((hash << 5) + (int)(c)) % N;
        word++;
    }

    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open file
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return 1;
    }

    char ch_array[LENGTH + 1];

    while (fscanf(file, "%s", ch_array) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        int hash_index = hash(ch_array);
        strcpy(n->word, ch_array);
        //n->next = NULL;

        if (table[hash_index] == NULL)
        {
            n->next = NULL;
        }
        else
        {
            n->next = table[hash_index];
        }

        table[hash_index] = n;
        word_counter += 1;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // implemented in the load f
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
        while (table[i] != NULL)
        {
            node *tmp = table[i];
            table[i] = table[i]->next;
            free(tmp);
        }
    return true;
}
