RPM_TO_SPEED_MULTIPLIER = 10
require "minitest/autorun"
require "minitest/pride"
require_relative "delegator.rb"
class Tire # Part of Car
  def initialize(producer:, diameter:)
    @producer = producer    # String
    @diameter = diameter    # String
    @dirty = [true, false].sample # Random state
  end

  def dirty
    @dirty
  end
end

class Engine # Part of Car
  def initialize(capacity:, horses:)
    @capacity = capacity  # Integer
    @horses = horses      # Integer
    @rpm = 0              # Integer
    @dirty = [true, false].sample # Random state
    @is_electric = true # All engines are electric
  end

  def accelerate(kilometers)
    # Lets say that our speed increase linearly with rotations per second.
    @rpm += kilometers * RPM_TO_SPEED_MULTIPLIER # Convert speed into rpm
  end

  def horses
    @horses
  end

  def rpm
    @rpm
  end

  def is_electric? # Reader
    @is_electric
  end

  def dirty
    @dirty
  end
end

class Car # Main class
  include Enumerable
  Module.prepend MyDelegate # Include my_delegate method
  def initialize(name:, engine:, tires:) # Car consist of 3 parts: brand, engine and array of tires
    @name = name
    @engine = engine
    @tires_pack = tires
  end

  my_delegate :rpm, :accelerate, :horses, :is_electric?, to: :@engine # Delegating Engine instance methods to instance variable @engine

  my_delegate :each, :find, :find_all, to: :details # Delegating Enumerables into "details" Car instance method

  my_delegate :capitalize, to: :@name #Delegating capitalize string method to @name instance variable

  def engine #Reader
    @engine
  end


  def speed #Reader
    rpm * RPM_TO_SPEED_MULTIPLIER
  end

  def details # => Array
    @tires_pack + [@engine]
  end
end

class MyDelegateTest< Minitest::Test #Tests
  def test_1
    engine = Engine.new(capacity: 0, horses: 200)
    tire1 = Tire.new(producer: :michelin, diameter: 17)
    tire2 = Tire.new(producer: :michelin, diameter: 17)
    tire3 = Tire.new(producer: :good_year, diameter: 18)
    tire4 = Tire.new(producer: :good_year, diameter: 18)
    c = Car.new(name: "Nissan", engine: engine, tires: [tire1, tire2, tire3, tire4])

    assert_equal c.horses, 200
    assert_equal c.capitalize, "Nissan".capitalize
  end
end

engine = Engine.new(capacity: 0, horses: 200)
tire1 = Tire.new(producer: :michelin, diameter: 17)
tire2 = Tire.new(producer: :michelin, diameter: 17)

tire3 = Tire.new(producer: :good_year, diameter: 18)
tire4 = Tire.new(producer: :good_year, diameter: 18)

c = Car.new(name: "Nissan", engine: engine, tires: [tire1, tire2, tire3, tire4])

pp "INITIAL: speed: #{c.speed}"
c.accelerate(10)
pp "ACCELERATE 1: speed #{c.speed}, rpm: #{c.rpm}"
c.accelerate(20)
pp "ACCELERATE 2: speed #{c.speed}, rpm: #{c.rpm}"
pp c.each {|detail| puts "Detail: #{detail}" }
pp "Finding engine details:"
pp c.find {|detail| detail.is_a?(Engine) }

pp "Finding dirty details:"
pp c.select(&:dirty)
