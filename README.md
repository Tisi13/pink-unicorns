Systems Programming
===========

Name: Tisiana Henricus
Email address: tisianah@hotmail.com

Testing / Building changes
--------

- Added make file
- Added data generation program (`gen.py`)
- Added automatic tester (`test.sh`)

Data structure changes
--------

To simplify the problem, I made the data structure easier.
whereas it used to look like this:

```
struct data 
{
    struct data *previous;
    char string[BUFFER_SIZE];
};
```

it now looks like this:

```
struct data 
{
    struct data *previous;
    struct data *next;
    int size;
    char data[BUFFER_SIZE];
};
```

This way navigating and getting the size of a buffer will be nearly trivial.

Function Changes
------

`void reverse(char *s, int length)` the idea was very good, however the 
implementation was a bit unclear. Hopefully my current solution is readable

`void alloc_chunks_and_print_reverse(FILE *file_handle)` This method was simply 
*too big*. Quite a lot of discussion exists on the proper length of a function.
Usually people agree that a function should do one thing. I recycled the code 
in the following functions.

- `struct data *alloc_data()` allocates and initialises a data buffer
- `void free_data(struct data *begin)` frees a data linked list
- `struct data *readfile(FILE *file_handle)` reads a file into a data structure
- `void write_contents(struct data *first)` writes contents in normal order (debugging)
- `void write_contents_backwards(struct data *first)` writes buffers in reverse order to stdout (does not alter the contents of buffers)
- `void reverse_innerbuffers(struct data *first)` reverses every buffer of linked list data structure

All of the above functions are fairly straightforward in implementation.

