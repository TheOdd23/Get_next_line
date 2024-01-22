# get_next_line

This project consists in making a function that returns the "next line" in a given file, starting by the first one, and returning NULL if the file is empty or the next line is EOF.

This function come in pretty handy when it comes to parse text files.  

The main concept to learn in this project is static variables and how they keep their memory after each call. The hard part was to make sure there was no memory leaks.

The bonus was to be able to manage mutliple opened fds.
