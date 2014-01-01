#Daily Programmer #125
#r-s

=begin
You're a newly hired engineer for a brand-new company that's building a "killer Word-like 
application". You've been specifically assigned to implement a tool that gives the user 
some details on common word usage, letter usage, and some other analytics for a given 
document! More specifically, you must read a given text file (no special formatting, 
just a plain ASCII text file) and print off the following details:
Number of words
Number of letters
Number of symbols (any non-letter and non-digit character, excluding white spaces)
Top three most common words (you may count "small words", such as "it" or "the")
Top three most common letters
=end

infile = File.open(ARGV[0])
all = ""

def counter(all, ww)
  ww==1 ? w = all.gsub(/[[:punct:]]/, '').split(" ") : w = all.gsub(/[^a-z]/, '').split("")
  hs = Hash.new(0); w.each {|x| hs[x] +=1} 
  t = hs.sort_by{|x,y|y}; 3.times {puts t.pop.to_s}
end

File.foreach(infile){|line| all += line.downcase}
puts "#Words: #{all.split.size}"
puts "#Characters: #{all.length + 1- all.split.size}"
puts "#Symbols #{all.count(",//.//!//@//#//$//%//^//&//*//(//)//_//")}"  
puts "Three most common words: "; counter(all, 1)
puts "Three most common letters: "; counter(all, 0)
