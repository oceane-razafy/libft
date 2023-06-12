# Libft

This project is part of the curriculum at 42 school and aims to recreate various standard C library functions as well as additional utility functions. The project involves creating a library, named `libft.a`, that contains these functions, which can be used in future projects to simplify development tasks.

## Table of Contents

- [Project Description](#project-description)
- [Installation](#installation)
- [Usage](#usage)
- [Included Functions](#included-functions)

## Project Description

The "libft" project focuses on developing a library of useful functions that can be used in C programming. The main objectives of the project are:

1. Recreating standard C library functions, such as string manipulation functions (`strlen`, `strcpy`, `strcat`, etc.), memory functions (`memset`, `memcpy`, `memmove`, etc.), and character functions (`isalpha`, `isdigit`, `tolower`, etc.).
2. Implementing additional utility functions to simplify common tasks, such as string manipulation (`ft_substr`, `ft_strjoin`), string conversion (`ft_itoa`), string mapping (`ft_strmapi`), string iteration with index (`ft_striteri`), character output (`ft_putchar_fd`), and string splitting (`ft_split`).
3. Creating a static library, named `libft.a`, that can be linked to other projects.

## Installation

To use the "libft" library, follow these steps:

1. Clone the repository to your local machine:

```
git clone <repo url> libft
```

2. Navigate to the project directory:

```
cd libft
```

3. Build the library by running the make command:

```
make
```

4. Include the `libft.h` header file in your code:

```c
#include "libft.h"
```

5. Compile your code, linking it with the `libft.a`library:

```
gcc your_code.c -L/path/to/libft -lft -o your_program
```

## Usage

To use the `libft.a` library in your project, follow these steps:

1. Use the library functions in your project. For example:

```c
#include "libft.h"

int main()
{
    char str[] = "Hello new user!";
    int len = ft_strlen(str);
    ft_putstr_fd("The length of the string is: ", 1);
    ft_putnbr_fd(len, 1);
    ft_putchar_fd('\n', 1);
    return (0);
}
```

2. Compile your project, linking it with the `libft.a` library:

```
gcc your_code.c -L/path/to/libft -lft -o your_program
```

3. Run your program:

```
./your_program
```

## Included Functions

The `libft.a` library includes various functions, categorized as follows:

- **Memory functions**: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`

- **String functions**: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strnstr`, `ft_strncmp`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_itoa`, `ft_striteri`.

- **Character functions**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`.

- **Conversion functions**: `ft_atoi`, `ft_itoa`.

- **Output functions**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.

Please refer to the header file `libft.h` for the full list of functions.