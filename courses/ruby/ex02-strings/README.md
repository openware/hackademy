The goal of these exercises is to help you understand strings metods, both how they work and how they can be used

# Exercise structure

Unit text example

```ruby
 def test_1
   name = "alice"
   # In place of the line below, call a method on the name variable
   # defined above to acheive the expected output.
   actual = name.capitalize
   expected = "Alice"
   assert_equal expected, actual
  end

```

The strings_test.rb file has a number of exercises to help you better work with
strings in ruby.  Below is a list of methods that will help you complete the 
exercises - research each of them on the Ruby Docs for Strings to learn more 
about what they do and how they are used.  There are additional methods that
you will need to complete the exercises; each of these additional methods can
be found in the Ruby Docs for Strings.

* #{}
* capitalize
* concat
* chomp
* chop
* delete
* include?
* length
* reverse
* sub
* strip
* upcase

Full list of enumerable methods you can find [here](https://ruby-doc.org/core-2.4.0/String.html).

### Running test suite:

`ruby strings_test.rb`

Expected output:
```bash
Run options: --seed 14084

# Running:

.......................

Fabulous run in 0.000844s, 27253.2837 runs/s, 30808.0598 assertions/s.

23 runs, 26 assertions, 0 failures, 0 errors, 0 skips
```


