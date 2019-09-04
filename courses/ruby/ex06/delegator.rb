module MyDelegate
  def my_delegate(*args, to:)
    if to.to_s =~ /@/
      args.each do |method|
        define_method(method.to_s) do |*param, &block|
          instance_variable_get(to).send(method, *param, &block)
        end
      end
    else
      args.each do |method|
        define_method(method.to_s) do |*param, &block|
          send(to).send(method, *param, &block)
        end
      end
    end
  end
end
