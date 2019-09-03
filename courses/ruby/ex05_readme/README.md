# string-method_missing

In this exercise you should implement next methods:

- var.ask
- var.names_compare?
- var.parent

where 'var' is your variable name and 'names_compare' is expected string from tests.

## .ask

This spec should return instance of StringAsk class

Example: var = 'some_string'.ask # => 'some_string'

## .names_compare?

This spec should compare the string with self value of instance of StringAsk class.

Example: var.some_string?        # => true
         var.other_string?       # => false
Thus, you need to implement method for string which will return true if string is the same as the method name.

## .parent

This spec should return the parent class your class was inheritated from.

Example: var.parent            # => String

## Resources

[Method Missing in Ruby](https://medium.com/podiihq/method-missing-in-ruby-af4c6edd5130)
