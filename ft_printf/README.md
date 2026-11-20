*This project has been created as part of the 42 curriculum by angmarqu.*

# ft_printf

## Description

ft_printf is a recode of the libc `printf()` function. The goal is to learn how
variadic functions work in C (`va_start`, `va_arg`, `va_end`) and to write code that
is easy to extend with new conversions.

The result is a static library, `libftprintf.a`, with one function:

```c
int	ft_printf(const char *format, ...);
```

It prints the format string to the standard output, replacing each conversion with
the matching argument, and returns the number of characters printed, just like the
original.

### Supported conversions

| Conversion | Prints |
|---|---|
| `%c` | A single character |
| `%s` | A string (`(null)` if the pointer is NULL) |
| `%p` | A `void *` pointer in hexadecimal, with the `0x` prefix (`(nil)` if NULL, as on Linux) |
| `%d` | A signed decimal number |
| `%i` | A signed integer in base 10 |
| `%u` | An unsigned decimal number |
| `%x` | An unsigned number in lowercase hexadecimal |
| `%X` | An unsigned number in uppercase hexadecimal |
| `%%` | A percent sign |

Only the mandatory part is done (no flags, width or precision).

## Instructions

### Compilation

```bash
make        # builds libftprintf.a
make clean  # removes the object files
make fclean # removes the object files and libftprintf.a
make re     # rebuilds everything from scratch
```

### Usage

Include the header in your code:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("%s has %d cats, %x in hex\n", "Angelo", 2, 255);
	return (0);
}
```

And link the library when compiling:

```bash
cc main.c -L. -lftprintf
```

## Algorithm and data structure

### How it works

`ft_printf` reads the format string one character at a time:

1. If the character is not a `%`, it is printed as it is and the counter goes up by 1.
2. If it is a `%`, the next character is the conversion. `ft_conversion` looks at it,
   takes the next argument from the `va_list` with the right type (`int`, `char *`,
   `unsigned int` or `void *`) and calls the function that prints it.
3. Every print function returns how many characters it wrote, and `ft_printf` adds
   them all up. That total is the return value.

```
"Hi %s, %d%%"
 │    │   │ └─ ft_conversion('%') → ft_print_char('%')
 │    │   └─── ft_conversion('d') → ft_print_nbr(va_arg(args, int))
 │    └─────── ft_conversion('s') → ft_print_str(va_arg(args, char *))
 └──────────── normal characters → ft_print_char
```

### The print functions

Each conversion has its own small function, in its own file:

| File | Function | Used by |
|---|---|---|
| `ft_print_char.c` | `ft_print_char` | `%c`, `%%` and every normal character |
| `ft_print_str.c` | `ft_print_str` | `%s` |
| `ft_print_nbr.c` | `ft_print_nbr` | `%d`, `%i` |
| `ft_print_base.c` | `ft_print_base` | `%u`, `%x`, `%X` and the digits of `%p` |
| `ft_print_ptr.c` | `ft_print_ptr` | `%p` |

The numbers are printed with **recursion**: the function first calls itself with
`n / base` to print the digits on the left, and only then prints the last digit
(`n % base`). This way the digits come out in the right order without needing a
buffer or `malloc`.

`ft_print_base` takes the base as a string (`"0123456789"`, `"0123456789abcdef"` or
`"0123456789ABCDEF"`), so the same function prints decimal, lowercase hex and
uppercase hex. It uses an `unsigned long` so it can also print the full 64-bit
address of a pointer.

`ft_print_nbr` copies the `int` into a `long` before changing the sign, so
`-2147483648` (`INT_MIN`) works without overflow.

### Why this design

- **No data structure is needed.** The output goes straight to `write`, one piece at
  a time, so there is nothing to store. The subject also says not to implement the
  buffer of the original `printf`. The only thing kept is an `int` counter.
- **One function per conversion** keeps each function short (the Norm allows 25
  lines) and easy to test on its own.
- **Adding a new conversion** only needs a new `if` in `ft_conversion` and, if
  needed, a new print function. Nothing else changes.
- **The `va_list` is passed by pointer** (`va_list *`) to `ft_conversion`, so every
  `va_arg` moves the same list forward and the next conversion gets the next
  argument.

## Resources

- `man 3 printf`: the conversions and the return value
- `man 3 stdarg`: `va_start`, `va_arg`, `va_copy`, `va_end`
- `man 2 write`
- The 42 Norm and `norminette`
- [francinette](https://github.com/xicodomingues/francinette), for testing

### AI usage

AI was used as a peer: it explained `printf` and variadic functions in the style of a man page, answered my questions, and reviewed the code I wrote, without giving me the solutions.
