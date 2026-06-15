_This project has been created as part of the 42 curriculum by mariafer._

## Description
The goal of this project is to recreate part of the behavior of _printf_ from standard C library. It focuses on file descriptors, static variables, memory allocation, buffer management, string manipulation, and careful handling of edge cases such as EOF, empty files, invalid file descriptors, and different `BUFFER_SIZE` values.

The function prototype is:
```C
char	*get_next_line(int fd);
```

|	Concept	|	Description	|
|-----------|---------------|
|fd|	File descriptor to be read|
|BUFFER_SIZE|	Number of bytes read at a time|
|read|	System call used to read from the file descriptor|
|static variable|	Stores the remaining content between function calls|
|EOF|	Indicates the end of the file|
|\n|	Marks the end of a line|

## Instructions
Example of main to test the program:
```C
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("README.md", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%d->%s\n", lines++, line);
		free(line);
	}
	close(fd);
	return (0);
}
```

Compile with:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Then run:
```bash
./a.out
```

You can test with different buffer sizes:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=84 main.c get_next_line.c get_next_line_utils.c
```
## Resources
+ man read(2)
+ [EOF with a C Program](https://www.tutorialspoint.com/article/explain-the-end-of-file-eof-with-a-c-program)
+ [How to use Header File](https://wiki.imindlabs.com.au/cs/lang/c/1_fundamentals/2-dive-into-c/2_dive_into_c/)
+ [Macros in C](https://www.geeksforgeeks.org/c/macros-and-its-types-in-c-cpp/)
+ Peer discussion and testing during the 42 learning process

## AI Usage
AI was used as a study assistant during the development of this project.

It helped with:
+ Understanding how static variables work
+ Reviewing edge cases
+ Improving the README structure
+ Analysing possible memory leaks

## Algorithm and Data Structure Explanation