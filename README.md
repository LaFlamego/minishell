_This project has been created as part of the 42 curriculum by crevette and Oery_

## Description

`minishell` is a `bash`-like shell, reimplementing a subset of `bash`'s features.
The goal of the project is to understand the mechanisms behind a shell and deepen our understanding of Linux.

#### Prompt
The command prompt is handled by the GNU Readline library.
The current command / prompt can be cancelled using `CTRL+C`.
`minishell` can be exited using the `exit` builtin.

#### Parsing
Parsing starts with a scanning step where a lexer turns raw characters into tokens.
Those tokens are processed into a tree of operation by a recursive top down parser.
Each node of the tree is an operation and each leaf is a command.
Commands are a list of words and each word a list of part.

#### Execution
With the calls from parsers, the nodes are tracked through before execution and get the right type of the node. The track happens recursively in each command after expanded properly and based on the kind of command, the data flow goes to dedicated execution line until there is an interruption or executed completely.

#### Features

##### Operators
- `&&`: the AND operator can be used to chain commands if the first one succeed.
- `||`: the OR operator can be used to chain commands if the first one fail.
- `(`, `)`: operation priorities can be set using parentheses
- `|`: pipes can be used to connect commands together, the output of each command is used as input for the next one.

##### Expansion
- `$`: dollarsign followed by a sequence of character will expand into the matching environment variable's value.
- `$?`: will expand into the last foreground command's exit code
- `*`: expands to a list of files in the current directory. Hidden files can be toggled by prefixing the filter with `.`. Supports filtering.
- `>`: redirect the output of the command to a file.
- `>>`: redirect the output of the command to a file in append mode.
- `<`: use the following file as input for the command.
- `<<`: use the terminal stdin as input until the given delimiter is found and pass it to the command.
- `UP/DOWN`: the arrow keys can be used to move through the history 
- `''`: can be used to stop the shell from interpreting its content
- `""`: can be used to contains spaces

#### Builtins
- `cd`: change current directory to the path given as argument
- `echo`: write text to stdout. the `-n` flag removes the newline that's added by default.
- `env`: print all environment variables and their values
- `exit`: exit with the exit code passed as argument
- `export`: set an environment variable's value. If no argument is provided, displays the environment variables and their values.
- `pwd`: print the current working directory
- `unset`: remove a variable from the environment

## Instructions

Run `make` to compile the `./minishell` binary.

#### Flags
- `-d`: run `minishell` in debug mode, printing information about lexing, parsing and execution.

## Resources
- [GNU Bash Manual Reference](https://www.gnu.org/software/bash/manual/bash.html)
- [Readline MAN Refeference](https://tiswww.case.edu/php/chet/readline/readline.html)
- [Crafting Interpreters - Robert Nystrom](https://craftinginterpreters.com/)
- [Tree Structure](https://en.wikipedia.org/wiki/Tree_(abstract_data_type))

## AI Usage
- Oery: AI was used for static analysis, test generation and questioning about Bash's internals
- crevette: Used AI to understand concepts like how builtins work in shell and test especailly for extreme cases might cause memory leak/fd leak
