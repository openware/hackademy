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
          value.is_a?(Hash) ? (return search(value, find)) : (retrun "Error")
        end
      end
    end

    def search(node, find)
      if node.is_a?(Hash)
        node.each do |key, value|
          key == find ? (return value) : (return search(value, find) if value.is_a?(Hash))
        end
        nil
      end
    end
  end
end

test = MyApp.config
puts test.other
