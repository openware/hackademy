require "minitest/autorun"
require "minitest/pride"

require_relative "ex05"

class Ex05Test < Minitest::Test
  
  def test_initialize
    skip 
    line = "hello world!"

    string = line.ask

    assert_equal line, string
  end

  def test_check_method_name
    skip
    line = "check"
    string = line.ask
    res = string.check?

    assert_equal true, res
  end
  
  def test_check_other_method_name
    skip
    line = "other_check"
    string = line.ask
    res = string.check?

    assert_equal false, res
  end
end
