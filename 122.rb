#122
#rselk

#Find words in a word list that contain all the vowels in alphabetical 
#order, non-repeated, where vowels are defined as A E I O U Y.

infile = File.open("enable1.txt")

File.foreach(infile){|x| 
	puts x if x.downcase.gsub(/[^aeiouy]/, '') == "aeiouy" }