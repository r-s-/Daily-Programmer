#119
#dailyprogrammer
#rs
m = ARGV[0].to_f * 100

q=m.to_i/25; d=(m.to_i%25)/10; n=(m.to_i%10)/5; p=m.to_i%5

puts "Quarters: #{q}" if q>0
puts "Dimes: #{d}" if d>0
puts "Nickles: #{n}" if n>0
puts "Pennies: #{p}" if p>0