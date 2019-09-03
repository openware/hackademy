class StringAsk < String  
  def method_missing(m, *args, &block)
    if m.to_s[-1] == '?' 
      m.to_s.delete_suffix('?') == self ? true: false 
    elsif m.to_s == "parent"
      self.class.superclass
    end
  end
end

class String
  def ask
    example = StringAsk.new(self)    
  end
end

line = "some_method"
s = line.ask
puts s

s.some_method?
s.other_method?
s.class
s.parent
s.length
