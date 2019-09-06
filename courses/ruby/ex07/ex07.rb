require "singleton"
require "yaml"

module MyApp
  def config
    Config.instance
  end

  module_function :config

  class Config
    include Singleton

    def initialize
      @yaml_config_file = YAML.safe_load(File.read("config.yml"))
    end

    attr_reader :yaml_config_file

    def method_missing(m)
      key = m.to_s
      @yaml_config_file.each do |key1, value|
      key1 == ENV["MY_APP_ENVIRONEMNT"] ? (return rec_search(value, key)) : (return nil)
      end
    end

    def rec_search(value, key_word)
      if !value.is_a?(Hash)
        puts value   
      else
        value.each do |k, v|
          if k == key_word
            return v
          else
            return rec_search(v, key_word) if v.is_a?(Hash)
          end
        end
      end
    end
  end
end

pp MyApp.config.private_key
