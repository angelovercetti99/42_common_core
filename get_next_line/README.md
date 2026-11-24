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

1. While the stash has no `\n`:
   - read a block of `BUFFER_SIZE` bytes;
   - if `read()` returns 0, the file has ended: stop;
   - add the block to the end of the stash.
2. Take the line out of the stash (up to and including the `\n`).
3. Keep in the stash only what comes after the `\n`.
4. Return the line, or `NULL` if there was nothing left.

```
call 1: stash "ola\na"  → returns "ola\n", stash keeps "a"
call 2: stash "a" + "deus", read returns 0 → returns "adeus"
call 3: stash empty, read returns 0 → returns NULL
```

### Why this design

- **It reads as little as possible.** It stops reading as soon as a `\n` is in the
  stash, as the subject asks, instead of reading the whole file first.
- **It works with any `BUFFER_SIZE`**, from 1 to very large values, because the
  stash grows with `malloc` as needed.
- **No global variables**: the only state kept between calls is the static stash.

## Resources

- `man 2 read`
- `man 3 malloc`, `man 3 free`
- Static variables in C (storage duration)
- The 42 Norm and `norminette`

### AI usage

AI was used as a peer, without giving me the code:

- **Understanding the subject:** it explained `read()`, `BUFFER_SIZE` and static
  variables in the style of a man page.
- **The algorithm:** it asked me questions so I could build the steps myself (the
  stash, the reading loop, what stays after the `\n`).
- **The code:** it reviewed the code I wrote in `get_next_line.c`,
  `get_next_line_utils.c` and `get_next_line.h`.
- **This README:** it helped me write it in English.
