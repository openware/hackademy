The goal of these exercises is to help you understand classes and methods, both how they work and how they can improve you code readability and flexability instead using just functions.

# Exercise structure

```ruby
class WalletTest < Minitest::Test
  def test_wallet_starts_at_zero
    #skip
    wallet = Wallet.new
    assert_equal 0, wallet.cents
    assert_equal 0, wallet.dollars
  end

  def test_wallet_starts_at_non_zero
    #skip
    wallet = Wallet.new(:penny, :nickel)
    assert_equal 6, wallet.cents
    assert_equal 0.06, wallet.dollars
  end
end
```
You should implement a simple wallet Class, which may contain 5 types of currency: penny, nickel, dime, quarter, dollar.
Your wallet should store two fields: counts of cents and dollars. This fields must be readable.
Also you should create next methods: 
1)Initializing new wallet with specified nominals (for one for each type) or just empty wallet if no arguments passed 
2) Adding any coin or dollar to wallet ( "<<" method - takes one argument - name of currency )
3) Getting one coin or one dollar from wallet if respective nominal exists in wallet. ( "take" method - takes some number of currencies)

# Running the test files
Unit tests are implemented with Minitest. If you did not check doc yet it's time to do it now.

# Running test suite:
```console
ruby wallet_test.rb
```
Expected output:
```console
Run options: --seed 8431

# Running:

..........

Finished in 0.000935s, 10699.5929 runs/s, 34238.6972 assertions/s.
10 runs, 32 assertions, 0 failures, 0 errors, 0 skips
```

# Running rubocop:
```console
rubocop wallet_test.rb
```

Expected output:
```console
Inspecting 1 file
.

1 file inspected, no offenses detected
```

# Bonus
Fix all rubocop offences and submit patch without solution. If there is something to improve in .rubocop.yml you are welcome!


