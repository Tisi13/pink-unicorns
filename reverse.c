#include <stdio.h>
#include <stdlib.h>
#define MAX_ALLOC 1024
#define BUFFER_SIZE (MAX_ALLOC - sizeof(void *))


struct data 
{
    struct data *previous;
    char string[BUFFER_SIZE];
};


void reverse(char * s, int length)
{
    int i = 0;
    char b;
    length--;
    
    while(i<length)
    {
        b= s[i];
        s[i]=s[length];
        s[length]=b;
        i++;
        length --;
    }
}


void alloc_chunks_and_print_reverse(FILE *file_handle)
{
    struct data *current;
    struct data *previous;

    int actually_read;
    
    
    previous = NULL;
    
    while (1)
    {
        
        current = malloc(sizeof (struct data));
        current->previous = previous;

        /* reading file into the string */
        actually_read = fread(current->string, 1, BUFFER_SIZE , file_handle);
        
        
        if (actually_read == 0)
        {
                /* the last chunk will have actually_read = 0 */
                previous = current->previous;
                free(current);
                current = previous;
        }
        
        if (actually_read < 0) /* check whether an error occurred */
        {
            printf("Error while reading file\n");
            free(current);
            return;
        }
        
        current->string[actually_read] = '\0';
        reverse(current->string,actually_read);    
        
        if (feof(file_handle))
            break;
        
        previous = current;
    }
    

    /* the printing chunks in reverse part */
    while(current != NULL)
    {
        fwrite(current->string, actually_read , 1, stdout);
       
        actually_read = BUFFER_SIZE;
        
        
        previous = current->previous;
        free(current);
        current = previous;
    }
}

int main(int argc, char *argv[])
{
    FILE *file_handle;
    
    
    if (argc < 2)
    {
        printf("Not enough arguments given");
        return 1;
    }

    
    file_handle = fopen(argv[1], "rb");
    if (file_handle == 0)
    {
        printf("Could not fopen file\n");
        return 1;
    }
    
    alloc_chunks_and_print_reverse(file_handle);
    
    fclose(file_handle);
    
    return 0;
}
