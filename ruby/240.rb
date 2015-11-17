def scramble_words(unscrambled_words)
  unscrambled_words.split(' ').map do |word|
    word.split('').shuffle.join
  end
end
  
scramble_words(ARGV.last).each do |a| 
  print a + " "
end
