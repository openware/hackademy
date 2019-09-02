The goal of these exercises is to help you understand classes and methods, both how they work and how they can improve you code readability and flexability instead using just functions.

# Exercise structure

```
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
