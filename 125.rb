#Daily Programmer #125
#r-s

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
