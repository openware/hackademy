require "singleton"
require "yaml"
require "hashie"
require "erb"

module MyApp
  def config
    Config.instance
  end

  module_function :config

  class Config
    include Singleton

    def initialize
      erb = ERB.new File.read "config.yml.erb"
      yaml = YAML.safe_load erb.result binding
      @env = ENV.fetch("MY_APP_ENV", "test")
      @config = Hashie::Mash.new(yaml[@env])
    end

    attr_reader :yaml, :env

    def method_missing(m)
      @config[m]
    end
  end
end

pp MyApp.config.config.name
