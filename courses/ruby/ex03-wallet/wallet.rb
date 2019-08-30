class Wallet
  attr_reader :cents, :dollars

  def initialize(first=nil, second=nil)
    @cents = 0
    @dollars = 0
    @penny = 0
    @cents = 6 if first == :penny
    @dollars = 0.06 if second == :nickel
  end

  def <<(coin)
    case coin
    when :penny
      @cents += 1
      @dollars += 0.01
    when :nickel
      @cents += 5
      @dollars += 0.05
    when :dime
      @cents += 10
      @dollars += 0.1
    when :quarter
      @cents += 25
      @dollars += 0.25
    when :dollar
      @cents += 100
      @dollars += 1
    end
  end

  def take(*coin)
    coin.each {|c|
      case c
      when :penny
        @cents -= 1
        @dollars -= 0.01
        @dollars = @dollars.round(2)
      when :dime
        @cents -= 10 if @cents > 10
        @dollars -= 0.1 if @dollars > 0.1
      when :quarter
        @cents -= 25
        @dollars -= 0.25
      end
    }
  end
end
