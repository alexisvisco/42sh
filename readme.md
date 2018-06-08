# 42sh

## Subject:

[Subject](https://cdn.intra.42.fr/pdf/pdf/183/42sh.fr.pdf)

## Mandatory part:
- [x] Prompt without line edition.
- [x] Builtins `cd`, `echo`, `exit`, `env`, `setenv`, `unsetenv` with there options.
- [x] Executing simple commands with there parameters using `PATH`.
- [x] Support for redirection `>`, `>>`, `<`and `|`.
- [x] Logical operand `&&`and `||`.
- [x] Separator `;`.

## Optional feature (five of theses are mandatory to validate the project):
- [x] Inhibitors `"`, `'`and `\`.
- [x] Advanced redirections: aggregation of file output and heredoc `<<`.
- [ ] Globbing: `*`, `?`, `[]`, `{}`, etc.
- [x] Backquotes \`.
- [ ] Subshell with operand `()`.
- [x] Local variable and builtin `unset` and `export`.
- [x] History with builtin `history`and `!` with options.
- [x] Advanced line edition.
- [ ] File descriptors and builtin `read` with options.
- [x] Dynamical autocompletion.

## Optional feature highly appreciated:
- [ ] Job Control and builtins `job`, `fg`, `bg` and operand `&`.
- [ ] Shell Scripting: bang (!), variable assignements, brace group, if, while, until, for and functions

## Bonuses
- [X] Bc like command with `calc`
- [X] History search with <kbd>CTRL</kbd>+<kbd>H</kbd>
- [X] Can perform arithmetic operations on local variables assignment
- [X] Can search binary name with approximation (like which)
- [X] Replacement of ~ by `$HOME`
- [X] Replacement of any environment variable with the value of the variable.
- [X] Binary hashtable
- [X] Rights in the PATH
- [X] Custom ctrl-v to handle multi-line copy and paste
- [X] Lot of shortcut for line edition like
  - <kbd>CTRL</kbd>+<kbd>T</kbd>  Change the position of the characters
  - <kbd>CTRL</kbd>+<kbd>U</kbd> Delete the entire line
  - <kbd>CTRL</kbd>+<kbd>K</kbd> Delete from cursor to the end of the line
  - <kbd>CTRL</kbd>+<kbd>W</kbd>  Delete the last word typed
  - <kbd>CTRL</kbd>+<kbd>L</kbd> Clear shortcut
  - <kbd>SHIFT</kbd> + <kbd>▲</kbd> Up cursor
  - <kbd>SHIFT</kbd> + <kbd>▼</kbd> Down cursor
  - <kbd>SHIFT</kbd> + <kbd>▶</kbd> Go to right word
  - <kbd>SHIFT</kbd> + <kbd>◀</kbd> Go to left word
  - And other conventional shortcut !
