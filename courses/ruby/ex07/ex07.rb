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
      @config.each do |key, value|
        value.each do |arg|
          arg.each do |k, v|
            if k == m.to_s
              res = v
              return res
            end
          end
        end
      end
    end
  end
end
