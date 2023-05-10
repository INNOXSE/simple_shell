README.md ALX Simple Shell Team Project by SarahEmmy & INNOXSE

The simple_shell Project was completed using C Programming Language.
Compilation gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
How hsh works Prints a prompt and waits for a command from the user Creates a child process.

List of useful commands
cat - prints and concatenates the standard output files
cp -copies files into another file
grep - helps to search for a file in a specific pattern
less - let you go backward and forward in the files
ls - list all files and directories in current working dir.
mv - helps to move one file into another file
pwd - given you the current working directory.
chmod - converts files to executables

Files
README.md : File containing information about this project
main.h : Contains the header file all prototypes, Libriries for funcitons used.
hsh.c: hsh Main file is the file that uses most functions, executes them within this file
_getenv.c : Code  that contains _printf codes
_getline.c: Getting prompt and user input
convert.c: Specifically contains  functions for conversion specifiers
builtin_exe.c: The builtin's Executing.
builtin.c: Files which contains the two builtins.
parent_ch.c:These forks and creates parent child processes.
malloc.c :free malloc function files
prompt.c: The actual prompt line $ Files.
tokenizer.c: These creates function to tokenize an array of string Files.
utility_func.c: helper function,
