require "minitest/autorun"
require "minitest/pride"

require_relative "delegate"

class Ex06MyDelegateTest < Minitest::Test
  Module.prepend MyDelegate

  def test_my_delegate_one_argument_instance
    skip
    example = Class.new do
      my_delegate :integer?, to: :@example

      def initialize(example)
        @example = example
      end
    end

    num = 424242
    fl = 4242.4242

    tmp = example.new(num)
    wrn = example.new(fl)
    res = tmp.integer?
    mis = wrn.integer?


    assert_equal true, res
    assert_equal false, mis
  end

  def test_my_delegate_few_argument_instance
    skip
    example = Class.new do
      my_delegate :finite?, :nan?, :to_s, to: :@example

      def initialize(example)
        @example = example
      end
    end

    num = 424242
    fl = 12.02

    tmp = example.new(num)
    cur = example.new(fl)

    res = tmp.finite?
    rgh = cur.nan?
    str = tmp.to_s

    assert_equal true, res
    assert_equal false, rgh
    assert_equal "424242", str
  end

  def test_my_delegate_argument_function
    skip
    example = Class.new do
      my_delegate :length, :split, to: :convert_to_str

      def initialize(example)
        @example = example
      end

      def convert_to_str
        @example.to_s
      end
    end

    num = 424242

    tmp = example.new(num)

    len = tmp.convert_to_str.length
    cur = tmp.convert_to_str.split

    assert_equal 6, len
    assert_equal ["424242"], cur
  end

  def test_my_delegate_argument_function_with_arguments
    skip
    example = Class.new do
      my_delegate :gsub, to: :@example
      my_delegate :split, to: :convert_to_str

      def initialize(example)
        @example = example
      end

      def convert_to_str
        @example.to_s
      end
    end

    num = 424242
    str = "424242"
    tmp = example.new(str)
    cur = example.new(num)
    res_tmp = tmp.gsub("4", "2")
    res_cur = tmp.convert_to_str.split('2')

    assert_equal "222222", res_tmp
    assert_equal ["4", "4", "4"], res_cur
  end

  def test_enumerables
    skip
    engine = Class.new do
      def initialize(horses:)
        @horses=horses
      end
      def horses
        @horses
      end
    end
    stock = Class.new do
      include Enumerable
      my_delegate :each, to: :engines_pack
      def initialize(engines_pack:)
        @engines_pack = engines_pack
      end
      def engines_pack
        @engines_pack
      end
    end
    engine1 = engine.new(horses: 10)
    engine2 = engine.new(horses: 20)
    engine3 = engine.new(horses: 30)
    shop = stock.new(engines_pack: [engine1, engine2, engine3])
    sum = 0
    shop.each {|eng| sum += eng.horses}

    assert_equal 60, sum
  end
end