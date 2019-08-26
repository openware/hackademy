require 'minitest/autorun'
require 'minitest/pride'

class EnumerablesTest < Minitest::Test
  def test_squares_each
    numbers = [1, 2, 3, 4, 5]
    actual = []
    numbers.each do |number|
      actual << number ** 2
    end
    assert_equal [1, 4, 9, 16, 25], actual
  end

  def test_squares
    numbers = [1, 2, 3, 4, 5]
    actual = numbers.map do |number|
      number ** 2
    end
    assert_equal [1, 4, 9, 16, 25], actual
  end

  def test_find_waldo_each
    skip
    words = ["noise", "dog", "fair", "house", "waldo", "bucket", "fish"]
    actual = nil
    words.each do |word|
      # Your Code Here
    end
    assert_equal "waldo", actual
  end

  def test_find_waldo
    skip
    words = ["noise", "dog", "fair", "house", "waldo", "bucket", "fish"]
    actual = words.find do |word|
      # Your Code Here
    end
    assert_equal "waldo", actual
  end

  def test_pick_words_with_three_letters_each
    skip
    words = ["pill", "bad", "finger", "cat", "blue", "dog", "table", "red"]
    actual = []
    # Your Code Here
    assert_equal ["bad", "cat", "dog", "red"], actual
  end

  def test_pick_words_with_three_letters
    skip
    words = ["pill", "bad", "finger", "cat", "blue", "dog", "table", "red"]
    actual = # Your Code Here
    assert_equal ["bad", "cat", "dog", "red"], actual
  end

  def test_normalize_zip_codes_each
    skip
    numbers = [234, 10, 9119, 38881]
    actual = []
    # Your Code Here
    assert_equal ["00234", "00010", "09119", "38881"], actual
  end

  def test_normalize_zip_codes
    skip
    numbers = [234, 10, 9119, 38881]
    # Your Code Here
    assert_equal ["00234", "00010", "09119", "38881"], actual
  end

  def test_no_waldo_each
    skip
    words = ["scarf", "sandcastle", "flag", "pretzel", "crow", "key"]
    # Your Code Here
    assert_nil found
  end

  def test_no_waldo
    skip
    words = ["scarf", "sandcastle", "flag", "pretzel", "crow", "key"]
    # Your Code Here
    assert_nil found
  end

  def test_pick_floats_each
    skip
    numbers = [3, 1.4, 3.5, 2, 4.9, 9.1, 8.0]
    # Your Code Here
    assert_equal [1.4, 3.5, 4.9, 9.1, 8.0], actual
  end

  def test_pick_floats
    skip
    numbers = [3, 1.4, 3.5, 2, 4.9, 9.1, 8.0]
    # Your Code Here
    assert_equal [1.4, 3.5, 4.9, 9.1, 8.0], actual
  end

  def test_words_with_no_vowels_each
    skip
    words = ["green", "sheep", "travel", "least", "boat"]
    # Your Code Here
    assert_equal ["grn", "shp", "trvl", "lst", "bt"], actual
  end

  def test_words_with_no_vowels
    skip
    words = ["green", "sheep", "travel", "least", "boat"]
    # Your Code Here
    assert_equal ["grn", "shp", "trvl", "lst", "bt"], actual
  end

  def test_has_at_least_one_zero_each
    skip
    numbers = [2, 0, 9, 3, 0, 1]
    # Your Code Here
    assert_equal true, actual
  end

  def test_has_at_least_one_zero
    skip
    numbers = [2, 0, 9, 3, 0, 1]
    # Your Code Here
    assert_equal true, actual
  end

  def test_all_gone_each
    skip
    words = ["gone", "gone", "gone", "gone", "gone", "gone", "gone"]
    # Your Code Here
    assert_equal true, actual
  end

  def test_all_gone
    skip
    words = ["gone", "gone", "gone", "gone", "gone", "gone", "gone"]
    # Your Code Here
    assert_equal true, actual
  end

  def test_count_numbers_greater_than_17_each
    skip
    numbers = [9, 18, 12, 17, 1, 3, 99]
    # Your Code Here
    assert_equal 2, actual
  end

  def test_count_numbers_greater_than_17
    skip
    numbers = [9, 18, 12, 17, 1, 3, 99]
    # Your Code Here
    assert_equal 2, actual
  end

  def test_array_with_the_most_items_each
    skip
    arrays = [[:a, :b, :c], [1, 2, 3, 4, 5], ["zoo", :things, :stuff]]

    # Your Code Here

    assert_equal [1, 2, 3, 4, 5], actual
  end

  def test_array_with_the_most_items
    skip
    arrays = [[:a, :b, :c], [1, 2, 3, 4, 5], ["zoo", :things, :stuff]]

    # Your Code Here

    assert_equal [1, 2, 3, 4, 5], actual
  end

  def test_group_words_by_first_letter_each
    skip
    words = ["ant", "axis", "albatross", "bolt", "badge", "butter", "car", "cdr", "column"]
    # Your Code Here
    expected = {"a"=>["ant", "axis", "albatross"], "b"=>["bolt", "badge", "butter"], "c"=>["car", "cdr", "column"]}
    assert_equal expected, actual
  end

  def test_group_words_by_first_letter
    skip
    words = ["ant", "axis", "albatross", "bolt", "badge", "butter", "car", "cdr", "column"]
    # Your Code Here
    expected = {"a"=>["ant", "axis", "albatross"], "b"=>["bolt", "badge", "butter"], "c"=>["car", "cdr", "column"]}
    assert_equal expected, actual
  end

  def test_none_are_negative_each
    skip
    numbers = [9, 3, 1, 8, 3, 3, 5]
    # Your Code Here
    assert true, actual
  end

  def test_none_are_negative
    skip
    numbers = [9, 3, 1, 8, 3, 3, 5]
    # Your Code Here
    assert true, actual
  end

  def test_sum_a_list_of_numbers_each
    skip
    numbers = [32, 1, 21, 5, 81, 333]
    # initial value is 0
    actual = # Your code here
      assert_equal 473, actual
  end

  def test_sum_a_list_of_numbers
    skip
    numbers = [32, 1, 21, 5, 81, 333]
    # initial value is 0
    actual = # Your code here
      assert_equal 473, actual
  end

  def test_remove_numbers_divisible_by_3_each
    skip
    numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
    # Your Code Here
    assert_equal [1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19, 20], actual
  end

  def test_remove_numbers_divisible_by_3
    skip
    numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
    # Your Code Here
    assert_equal [1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19, 20], actual
  end

  def test_speed_interview_pairs_each
    skip
    list1 = ["Alice", "Bob", "Charlie"]
    list2 = ["Xenia", "Yves", "Zach"]
    # Your Code Here
    assert_equal [["Alice", "Xenia"], ["Bob", "Yves"], ["Charlie", "Zach"]], actual
  end

  def test_speed_interview_pairs
    skip
    list1 = ["Alice", "Bob", "Charlie"]
    list2 = ["Xenia", "Yves", "Zach"]
    # Your Code Here
    assert_equal [["Alice", "Xenia"], ["Bob", "Yves"], ["Charlie", "Zach"]], actual
  end

  def test_has_a_multi_word_phrase_each
    skip
    phrases = ["Sure!", "OK.", "I have no idea.", "Really?Whatever."]
    # Your Code Here
    assert_equal true, actual
  end

  def test_has_a_multi_word_phrase
    skip
    phrases = ["Sure!", "OK.", "I have no idea.", "Really?Whatever."]
    # Your Code Here
    assert_equal true, actual
  end

  def test_count_words_that_are_uppercase_each
    skip
    words = ["trousers", "SOCKS", "sweater", "Cap", "SHOE", "TIE"]
    # Your Code Here
    assert_equal 3, actual
  end

  def test_count_words_that_are_uppercase
    skip
    words = ["trousers", "SOCKS", "sweater", "Cap", "SHOE", "TIE"]
    # Your Code Here
    assert_equal 3, actual
  end

  def test_smallest_number_each
    skip
    numbers = [1, 10, 100, 1000, 10000, 1000000]

    # Your Code Here

    assert_equal 1, actual
  end

  def test_smallest_number
    skip
    numbers = [1, 10, 100, 1000, 10000, 1000000]

    # Your Code Here

    assert_equal 1, actual
  end

  def test_multiply_list_of_numbers_each
    skip
    numbers = [2, 3, 5, 7]
    # initial value is 1
    actual = # Your code goes here
      assert_equal 210, actual
  end

  def test_multiply_list_of_numbers
    skip
    numbers = [2, 3, 5, 7]
    # initial value is 1
    actual = # Your code goes here
      assert_equal 210, actual
  end

  def test_solitaire_each
    skip
    list1 = ["Ace", "6", "10", "Queen"]
    list2 = [:clubs, :diamonds, :hearts, :spades]
    actual = # Your code goes here
      assert_equal [["Ace", :clubs], ["6", :diamonds], ["10", :hearts], ["Queen", :spades]], actual
  end

  def test_solitaire
    skip
    list1 = ["Ace", "6", "10", "Queen"]
    list2 = [:clubs, :diamonds, :hearts, :spades]
    actual = # Your code goes here
      assert_equal [["Ace", :clubs], ["6", :diamonds], ["10", :hearts], ["Queen", :spades]], actual
  end

  def test_all_multiples_of_7_each
    skip
    numbers = [42, 14, 35, 49, 28, 56, 21, 7]
    actual = # Your code goes here
      assert actual
  end

  def test_all_multiples_of_7
    skip
    numbers = [42, 14, 35, 49, 28, 56, 21, 7]
    actual = # Your code goes here
      assert actual
  end

  def test_sort_by_number_of_cents_each
    skip
    prices = [3.02, 9.91, 7.9, 10.01, 11.0]
    actual = # Your code goes here
      assert_equal [11.0, 10.01, 3.02, 7.9, 9.91], actual
  end

  def test_sort_by_number_of_cents
    skip
    prices = [3.02, 9.91, 7.9, 10.01, 11.0]
    actual = # Your code goes here
      assert_equal [11.0, 10.01, 3.02, 7.9, 9.91], actual
  end
end
