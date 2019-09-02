
require 'openssl'
require 'base64'
require "minitest/autorun"
require "minitest/pride"
require_relative "my_attr_accessor"

class MyAttrAccessorTest < Minitest::Test
  Module.prepend MyAcc
  def test_single_my_attr_accessor
    klass = Class.new do
      my_attr_accessor(:acc, "./user_key.txt")
    end
    instance = klass.new
    instance.acc_set = "d2hdmnHxYJcxsajeblGv92vPgtBo8nxQ+nvPzZwNlLf7HEYWRo79aTiFJkusT/mbcVkKv/MPwRc0zil7YwbaQB733KgVduq1OHCXtAoc8P2fRHprvYE3nsru5Iz+fYPo46afEqnd8kqjIg44cLjobS+Y9p+/iJAcFripStM86bk=.B8lIigGs9fanDbEZfijgJG/42wxEzVpNQrK379lQdBolCEZsD2cTEW5cCY8pVnSEi2xO4Sj/tKW4nJvgxL/UkqmFI/jyBKfMexMTzFb8w7audRq99E0DlmJ9t6OQhkmIUN1aqeZOUMbOxd5WnxSNsBxUSf64v1ntErRSl3KfBD4="
    assert_equal "Hello World!", instance.acc
  end

  def test_wrong_signature_my_attr_accessor
    klass = Class.new do
      my_attr_accessor(:acc, "./user_key.txt")
    end
    instance = klass.new
    instance.acc_set = "d2hdmnHxYJcxsajeblGv92vPgtBo8nxQ+nvPzZwNlLf7HEYWRo79aTiFJkusT/mbcVkKv/MPwRc0zil7YwbaQB733KgVduq1OHCXtAoc8P2fRHprvYE3nsru5Iz+fYPo46afEqnd8kqjIg44cLjobS+Y9p+/iJAcFripStM86bk=.B2lIigGs9fanDbEZfijgJG/42wxEzVpNQrK379lQdBolCEZsD2cTEW5cCY8pVnSEi2xO4Sj/tKW4nJvgxL/UkqmFI/jyBKfMexMTzFb8w7audRq99E0DlmJ9t6OQhkmIUN1aqeZOUMbOxd5WnxSNsBxUSf64v1ntErRSl3KfBD4="
    msg = instance.acc
    assert_equal "Error", msg
  end

  def test_wrong_key_my_attr_accessor
    klass = Class.new do
      my_attr_accessor(:acc, "./user_key.txt")
    end
    instance = klass.new
    instance.acc_set = "cHNfFM+Y6ap8e6ExiGuVbaeqVdJe9KwoQwAWqdmkGvyRA4SAP0BPuPrp7P2lSEjbN5WMzEYuERZ6fxgbA83rx+hOov8YdQ0TYk34mbTaC3KOdPIduSvRHc3196nyCa752Jvyc8VeNHdt5brq32jDqrMTaej8QnzGJx3p6NuP3nY=.JyKEo41d+xCbsDqhdkW2Ex/kpVjnIy8x5RcSE55V0nOcoKFTRgTdEivE6A9X1U3HAi1usGFnv/6QiSPsBUxkxEafnPHVpX62BR1k293+81L8iaYUQsniz9MDoEHStwsFGnc+YktOQksKTmu9JR29BPTpk7lwkEeYQmT8L748sfg="
    msg = instance.acc
    assert_equal "Wrong Key", msg
  end

  def test_no_file_my_attr_accessor
    klass = Class.new do
      @@msg=my_attr_accessor(:acc, nil)
    end
    instance = klass.new
    assert_equal "File not found", @@msg
  end
end
