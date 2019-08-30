require "minitest/autorun"
require "minitest/pride"

require_relative "my_attr_reader"

class MyAttrReaderTest < Minitest::Test
  def test_single_my_attr_reader
    skip
    klass = Class.new do
      my_attr_reader :readable

      def initialize
        @readable = "readme"
      end
    end

    instance = klass.new
    assert_equal "readme", instance.readable
  end

  def test_multiple_my_attr_readers
    skip
    klass = Class.new do
      my_attr_reader :readable1, :readable2
      my_attr_reader :readable3
      def initialize
        @readable1 = "readme1"
        @readable2 = "readme2"
        @readable3 = "readme3"
      end
    end

    instance = klass.new

    assert_equal "readme1", instance.readable1
    assert_equal "readme2", instance.readable2
    assert_equal "readme3", instance.readable3
  end

  def test_duplicated_my_attr_reader
    skip
    klass = Class.new do
      my_attr_reader :readable, :readable
      my_attr_reader :readable
      def initialize
        @readable = "readme"
      end
    end

    instance = klass.new
    assert_equal "readme", instance.readable
  end

  def test_my_attr_reader_initialization
    skip
    klass = Class.new do
      my_attr_reader :readable

      def initialize(readable)
        @readable = readable
      end
    end

    instance = klass.new("readme")
    assert_equal "readme", instance.readable
  end

  def test_my_attr_reader_changes
    skip
    klass = Class.new do
      my_attr_reader :readable

      def initialize
        @readable = "readme"
      end
    end

    instance = klass.new
    assert_equal "readme", instance.readable

    instance.instance_variable_set(:@readable, "readme one more time")
    assert_equal "readme one more time", instance.readable
  end

  def test_my_attr_reader_with_custom_writer
    skip
    klass = Class.new do
      my_attr_reader :readable

      def initialize
        @readable = "readme"
      end

      def readable=(r)
        @readable = r
      end
    end

    instance = klass.new
    assert_equal "readme", instance.readable

    instance.readable = "readme one more time"
    assert_equal "readme one more time", instance.readable
  end

  def test_my_attr_reader_instance_methods
    skip
    klass = Class.new do
      my_attr_reader :readable1, :readable2
      my_attr_reader :readable3
      def initialize
        @readable1 = "readme1"
        @readable2 = "readme2"
        @readable3 = "readme3"
      end
    end

    new_class_methods = klass.instance_methods - klass.superclass.instance_methods

    # Check that only expected methods were defined.
    assert_equal %i[readable1 readable2 readable3] - new_class_methods, []
  end

  def test_my_attr_reader_namespace
    # skip
    assert_raises NoMethodError do
      my_attr_reader(:readable)
    end

    assert_respond_to Module, :my_attr_reader
    assert_respond_to Class, :my_attr_reader
  end
end

