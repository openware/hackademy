require 'yaml'
require 'singleton'
require 'hashie'
require 'erb'

module MyApp
  def config
    Config.instance
  end

  module_function :config

  class Config
    include Singleton
    
    attr_reader :env

    def initialize
      erb = ERB.new File.read 'config.yml.erb'
      @config = YAML.load erb.result
      @env = ENV.fetch('ENV_VAR', :development)
    end
    
    def out
      @config
    end
    
    def method_missing(m)
      res = nil
      find = m.to_s
      @config.each do |key, value|
        if key == ENV["ENV_VAR"]
          value.is_a?(Hash) ? (return search(value, find)) : (return "Error")
        end
      end
    end

    def search(node, find)
      if node.is_a?(Hash)
        node.each do |key, value|
          key == find ? (return value) : ((return search(value, find)) if value.is_a?(Hash))
        end
        nil
      end
    end
  end
end

test = MyApp.config
puts test.inf
