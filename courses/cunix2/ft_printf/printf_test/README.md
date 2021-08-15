# ft_printf test

Unit test for the ft\_printf

## Usage

Clone this repo such that:

```
`
|- ft_printf_test/
|- ft_printf/
```

or modify the `FT_PRINTF_PATH` variable in the Makefile

- `> make run`: run the tests in a pretty format
- `> make verbose`: to show a more verbose output
- `> make quiet`: to show a more quiet output
- `> make raw`: run the tests in a ugly but parsable format

## Memory leaks check

- `> make check_leaks`: run valgrind on a test (without the test themself).
- `> make check_leaks_verbose`: add `--leak-check=full` to valgrind.
