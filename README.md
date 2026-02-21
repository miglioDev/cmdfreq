# cmdfreq

A minimal C CLI tool that analyzes a shell history file and shows the most frequently used commands.

## Build

make

## Usage

./cmdfreq <history_file>

Example:

./cmdfreq ~/.bash_history
./cmdfreq ~/.zsh_history

## Notes

- Groups subcommands (e.g. `git commit` → `git`)
- Ignores `sudo` prefix
- No external dependencies
- Updates and improvements coming soon
