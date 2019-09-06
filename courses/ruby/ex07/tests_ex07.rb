require "minitest/autorun"
require "minitest/pride"

require_relative "ex07"

class Ex07MyAppTest < Minitest::Test
  Module.prepend MyApp
  def test_class_config
    skip
    s = MyApp.config
    assert_equal s.class, MyApp::Config
    MyApp.reset
  end

  def test_obj_id
    skip
    a = MyApp.config
    b = MyApp.config
    assert_equal a.object_id, b.object_id
    MyApp.reset
  end

  def test_default_env
    skip
    a = MyApp.config
    assert_equal a.app_name, "dev app"
    MyApp.reset
  end

  def test_env_production
    skip
    ENV["MY_APP_ENV"] = "production"
    assert_equal MyApp.config.server, "http://httpd.example.org/"
    MyApp.reset
    ENV.delete("MY_APP_ENV")
  end

  def test_nested_level_one
    skip
    ENV["MY_APP_ENV"] = "test"
    assert_equal MyApp.config.public.mode, "public"
    MyApp.reset
    ENV.delete("MY_APP_ENV")
  end

  def test_nested_level_two
    skip
    ENV["MY_APP_ENV"] = "test"
    assert_equal MyApp.config.private.private.login, "any_login@bootcamp.com"
    MyApp.reset
    ENV.delete("MY_APP_ENV")
  end

  def test_erb_default
    skip
    ENV["MY_APP_ENV"] = "test"
    assert_equal MyApp.config.database.user, "root"
    MyApp.reset
    ENV.delete("MY_APP_ENV")
  end

  def test_erb_specified
    skip
    ENV["DATABASE_USER"] = "admin"
    ENV["MY_APP_ENV"] = "test"
    assert_equal MyApp.config.database.user, "admin"
    MyApp.reset
    ENV.delete("MY_APP_ENV")
    ENV.delete("DATABASE_USER")
  end
end