*This project has been created as part of the 42 curriculum by angmarqu.*

# Libft

## Description

Libft is the first project of the 42 Common Core. The goal is to recode a set of
functions from the C standard library, plus some extra utility functions, and gather
them in a static library (`libft.a`) that can be reused in future projects.

## Instructions

### Compilation

```bash
make        # builds libft.a
make clean  # removes the object files
make fclean # removes the object files and libft.a
make re     # rebuilds everything from scratch
```

### Usage

Include the header in your code:

```c
#include "libft.h"
```

And link the library when compiling:

```bash
cc main.c -L. -lft
```

## Library overview

### Part 1: Libc functions

Reimplementations of standard libc functions, with the same behaviour as the originals.

| Function | Description |
|---|---|
| `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | Character checks |
| `ft_toupper`, `ft_tolower` | Character case conversion |
| `ft_strlen` | Length of a string |
| `ft_memset`, `ft_bzero` | Fill a memory area with a byte / with zeros |
| `ft_memcpy`, `ft_memmove` | Copy a memory area (`memmove` handles overlap) |
| `ft_strlcpy`, `ft_strlcat` | Size-bounded string copy and concatenation |
| `ft_strchr`, `ft_strrchr` | First / last occurrence of a character in a string |
| `ft_strncmp`, `ft_memcmp` | Compare strings / memory areas |
| `ft_memchr` | Search a byte in a memory area |
| `ft_strnstr` | Locate a substring within the first `len` characters |
| `ft_atoi` | Convert a string to an `int` |
| `ft_calloc` | Allocate zero-initialised memory |
| `ft_strdup` | Duplicate a string |

### Part 2: Additional functions

Functions that are not in the libc, or are in a different form.

| Function | Description |
|---|---|
| `ft_substr` | Extract a substring from a string |
| `ft_strjoin` | Concatenate two strings into a new one |
| `ft_strtrim` | Remove a set of characters from both ends of a string |
| `ft_split` | Split a string by a delimiter into an array of strings |
| `ft_itoa` | Convert an `int` to a string |
| `ft_strmapi` | Apply a function to each character, creating a new string |
| `ft_striteri` | Apply a function to each character, in place |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write a character, string, string with newline or number to a file descriptor |

### Part 3: Linked lists

Functions to create and manipulate singly linked lists of `t_list` nodes, each with a
`content` pointer and a `next` pointer.

| Function | Description |
|---|---|
| `ft_lstnew` | Create a new node |
| `ft_lstadd_front`, `ft_lstadd_back` | Add a node at the beginning / end of a list |
| `ft_lstsize` | Count the nodes of a list |
| `ft_lstlast` | Return the last node of a list |
| `ft_lstdelone` | Free a node and its content |
| `ft_lstclear` | Free a whole list and set its pointer to NULL |
| `ft_lstiter` | Apply a function to the content of each node |
| `ft_lstmap` | Create a new list by applying a function to each node's content |

## Resources

- The `man` pages of the libc functions (`man 3 strlen`, `man 3 memmove`, `man 3 strlcpy`...)
- The 42 Norm and `norminette`
- [libft-unit-test](https://github.com/alelievr/libft-unit-test), for testing

### AI usage

AI was used mainly as a peer: to quiz me on my understanding, explain key concepts
(pointers to pointers, linked lists, function pointers, memory allocation) and review
code I wrote, without giving me the solutions. It was also used to run tests.
