class String
  def ask
    StringAsk.new(self)
  end
end

class StringAsk < String
  attr_accessor :string
  
  def length
    @string.length
  end

  def initialize(string)
    @string = string
  end

  def method_missing(method)
    method.to_s.delete_suffix("?") == @string
    puts self.class.superclass if method.to_s == "parent"
  end
 
end
