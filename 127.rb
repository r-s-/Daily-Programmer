#DailyProgrammer Challenge
#number 127

def mc (num)
  if num>100 
    puts "#{num} is > 100"
    num = num-10
  else
    puts "#{num} is < 100"
    mc(mc(num+11))
  end
end

puts mc(99)  



