judge - online judge helper
---------------------------

## Functions

Auto initialze, compile, and run against input cases.

## Install

Download the repository. Add `export PATH=$PATH:<path-to-judge>` to your `.bashrc` or `.zshrc` file.

## Usage

```
Commands:

init [<solution_name>] [-l <cpp/java>] [-t <template>]
    Create a solution in specified language (default C++).
    Solution will be set to current directory if not specified, which is the same for the followings.

edit <solution_name>
    Open Sublime Text to edit the solution.

run <solution_name> [-i <input_file>]
    Compile a solution and run against test cases.
    This is the default command if no command is specified.

check <solution_name> [-i <input_file>]
    Compile a solution and run against test cases, and check the output against correct answer.


Options:

--help, -h
    Print this user manual.

--version, -v
    Print software version.
```