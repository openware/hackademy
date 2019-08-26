The goal of these exercises is to help you understand enumerables, both how 
they work and how they can be replicated through the use of the #each, the 
basis of all enumerables.

# Exercise structure

Unit test example:
```ruby
  def test_squares_each
    numbers = [1, 2, 3, 4, 5]
    actual = []
    numbers.each do |number|
      actual << number ** 2
    end
    assert_equal [1, 4, 9, 16, 25], actual
  end

  def test_squares
    numbers = [1, 2, 3, 4, 5]
    actual = numbers.map do |number|
      number ** 2
    end
    assert_equal [1, 4, 9, 16, 25], actual
  end
```

First case should be solved using each method and the most intuitive flow.
On the second one you should choose appropriate enumerable method
(as opposed to doing everything with each) this will make our lives much easier!
Second solution will generally be much more concise.

Full list of enumerable methods you can find [here](https://ruby-doc.org/core-2.6.3/Enumerable.html).

NOTE: In the most of task you will need to use single enumerable method.    

# Running the test files

Unit tests are implemented with [Minitest](https://github.com/seattlerb/minitest#unit-tests).
If you did not check doc yet it's time to do it now.

### Running test suite:
`ruby enumerables_test.rb`

Expected output:
```bash
Run options: --seed 31622

# Running:

..............................................

Finished in 0.002427s, 18953.4398 runs/s, 824.0626 assertions/s.
46 runs, 46 assertions, 0 failures, 0 errors, 0 skips
```

### Running rubocop:
`rubocop enumerables_test.rb`

Expected output:
```bash
Inspecting 1 file
.

1 file inspected, no offenses detected
```

# Bonus

Fix all rubocop offences and submit patch without solution.
If there is something to improve in `.rubocop.yml` you are welcome!
