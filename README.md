# ft_printf - Milestone 1 Common-Core project

The **ft_printf** project consists of recreating the standard C `printf` function, supporting a subset of its functionalities. This project deepened knowledge of variadic functions, formatting, and output control in C, requiring careful parsing and conversion of format specifiers.

## Project Objective

- Implement a custom version of the `printf` function named `ft_printf`.
- Support multiple format specifiers such as `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, and `%%`.
- Handle width, precision, and flags to format output similarly to the original `printf`.
- Manage variadic arguments using `stdarg.h`.

## Supported Format Specifiers

- `%c` — character
- `%s` — string
- `%d` / `%i` — signed decimal integer
- `%u` — unsigned decimal integer
- `%x` / `%X` — unsigned hexadecimal integer (lowercase/uppercase)
- `%p` — pointer address
- `%%` — literal percent sign

## Concepts Learned

- Handling of variadic functions and argument lists.
- Parsing complex format strings with multiple flags and options.
- String and number conversion techniques.
- Writing rob
