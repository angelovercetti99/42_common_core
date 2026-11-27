*This project has been created as part of the 42 curriculum by angmarqu.*

# get_next_line

## Description

get_next_line is a function that reads a file descriptor one line at a time. The
goal is to learn how `read()` works and to discover **static variables**, which keep
their value between calls to the same function.

```c
char	*get_next_line(int fd);
```

Each call returns the next line of the file, including the `\n` at the end (the last
line may come without it if the file does not end with a `\n`). When there is
nothing left to read, or if an error happens, it returns `NULL`.

It works with files and with the standard input.

The bonus part is also done (`get_next_line_bonus.c`, `get_next_line_bonus.h`,
`get_next_line_utils_bonus.c`): it uses only one static variable and can read from
several file descriptors at the same time, without mixing their lines.

## Instructions

### Compilation

There is no library to build: the files are compiled together with your own code.
`BUFFER_SIZE` sets how many bytes `read()` asks for each time. It can be changed with
`-D` (if it is not given, the header sets a default value):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

For the bonus part, use the bonus files and include `get_next_line_bonus.h`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

### Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

Every line returned is allocated with `malloc`, so the caller must `free` it.

## Algorithm

### The problem

`read()` does not read lines, it reads blocks of `BUFFER_SIZE` bytes. A block can end
in the middle of a line, or hold the end of one line and the start of the next:

```
BUFFER_SIZE = 5, file "ola\nadeus"

read → [o][l][a][\n][a]
        └── line ──┘  └ already belongs to the next line
```

The bytes after the `\n` cannot be lost, so they must be kept until the next call.

### The stash

A `static char *` (the stash) holds what was read but not returned yet. Because it
is `static`, it keeps its value between calls. The memory it points to comes from
`malloc`, because its size is not known in advance: it depends on `BUFFER_SIZE` and
on the length of the lines.

### Each call

`get_next_line` first checks its input: if `fd` is negative or `BUFFER_SIZE` is not
positive, it returns `NULL` right away. Then it calls three functions, one per step:

1. **`read_to_stash`**: while the stash has no `\n`:
   - read a block of `BUFFER_SIZE` bytes;
   - if `read()` returns 0, the file has ended: stop;
   - add the block to the end of the stash.
2. **`extract_line`**: take the line out of the stash (up to and including the `\n`).
   If the stash is empty, there is no line: the stash is freed and `NULL` is returned.
3. **`clean_stash`**: keep in the stash only what comes after the `\n`. The old stash
   is freed. If nothing is left, the stash becomes `NULL` instead of `""`, so no
   empty string stays allocated at the end of the file.
4. Return the line.

```
call 1: stash "ola\na"  → returns "ola\n", stash keeps "a"
call 2: stash "a" + "deus", read returns 0 → returns "adeus"
call 3: stash empty, read returns 0 → returns NULL
```

### Errors

- **`read()` returns -1** (closed or invalid file descriptor): the buffer and the
  stash are freed and `get_next_line` returns `NULL`.
- **`malloc` fails** (in the buffer, in `ft_strjoin` or in `ft_substr`): the memory
  already allocated is freed and nothing crashes. `get_next_line` returns `NULL`
  (if it fails while keeping the rest in `clean_stash`, the line is still returned
  and the stash becomes `NULL`).
- After an error or at the end of the file the stash is set back to `NULL`, so it
  never points to memory that was already freed.

### Helper functions

The libft is not allowed in this project, so the helpers are rewritten in
`get_next_line_utils.c`:

| Function | Used for |
|---|---|
| `ft_strlen` | Measuring the stash and the block, for `malloc` |
| `ft_strchr` | Checking if the stash already has a `\n` (it returns `NULL` if the stash is `NULL`) |
| `ft_strjoin` | Adding the block that was read to the end of the stash (a `NULL` stash counts as `""`, so the first call works) |
| `ft_substr` | Taking the line out of the stash, and keeping what comes after the `\n` |

`ft_strjoin` returns a new string, so `get_next_line` keeps it in a temporary
pointer, frees the old stash and only then points the stash to the new one. This way
no memory is lost on each `read()`.

### Bonus: several file descriptors

The mandatory part has only one stash, so reading from fd 3 and then from fd 4 would
mix the two files. The bonus keeps **one stash per file descriptor**, still with a
single static variable: an array of stashes.

```c
static char	*stash[MAX_FD];
```

```
 stash[0]  stash[1]  stash[2]  stash[3]   stash[4]  ...  stash[1023]
   NULL      NULL      NULL    "a2\na3"   "b2\n"           NULL
```

The `fd` itself is the index: `get_next_line(3)` only uses `stash[3]`, and
`get_next_line(4)` only uses `stash[4]`. Because the array is `static`, every box
starts as `NULL`. `MAX_FD` is 1024 by default (it can be changed with `-D`), and any
`fd >= MAX_FD` returns `NULL`, so the function never writes outside the array. The
three step functions are the same as in the mandatory part: they receive
`stash[fd]` instead of `stash`.

### Why this design

- **It reads as little as possible.** It stops reading as soon as a `\n` is in the
  stash, as the subject asks, instead of reading the whole file first.
- **It works with any `BUFFER_SIZE`**, from 1 to very large values, because the
  stash grows with `malloc` as needed.
- **No global variables**: the only state kept between calls is the static stash
  (one static array in the bonus).

## Resources

- `man 2 read`
- `man 3 malloc`, `man 3 free`
- Static variables in C (storage duration)
- The 42 Norm and `norminette`

### AI usage

I used AI as a peer, the same way I would work with another student. It did not
give me the answers or write the functions for me: I wrote all of them myself.

- **Concepts:** when I did not know something (`read()`, file descriptors,
  `BUFFER_SIZE`, static variables, arrays of pointers for the bonus), it explained
  the concept, like a man page, with small drawings of the memory.
- **Questions instead of answers:** to build the algorithm, it asked me questions
  (what has to survive between calls, when to stop reading, what stays after the
  `\n`, how to keep one stash per file descriptor) and gave me small hints when I
  was stuck.
- **Review:** when I showed it my code, it pointed out where the mistakes were
  (leaks, wrong conditions, reading outside the array) and explained why, so I
  could fix them myself.
