require "yaml"
require "singleton"
require "hashie"
require "erb"
module MyApp
def self.reset
    Config.reset
  end
  def self.config
    Config.instance
  end

  class Config
    include Singleton
    class << self
    def reset
      @singleton__instance__ = nil
    end
  end
    def initialize
      template = ERB.new (File.read ('config.yml.erb'))
      file = YAML.load (template.result binding)
      @env = ENV.fetch('MY_APP_ENV', "development")
      @hash = Hashie::Mash.new(file[@env])
    end
    def method_missing(m)
      return @hash[m]
    end
  end
end
