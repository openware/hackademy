require 'yaml'
require 'singleton'

module MyApp
  def config
    Config.instance
  end

  module_function :config

  class Config
    include Singleton
    def initialize
      @config = YAML.load_file("config.yml")
    end
    
    def out
      @config
    end
    def method_missing(m)
      res = nil
      find = m.to_s
      @config.each do |key, value|
        if key == ENV["ENV_VAR"]
          if value.is_a?(Hash)
            res = search(value, find)
            return res
          else
            puts "Error"
          end
        end
      end
    end

    def search(node, find)
      if node.is_a?(Hash)
        node.each do |key, value|
          if key == find
            res = value
            return res
          elsif value.is_a?(Hash)
            res = search(value, find)
            return res
          end
        end
        nil
      end
    end
  end
end

test = MyApp.config
puts test.other
