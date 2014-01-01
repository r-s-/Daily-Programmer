#119
#dailyprogrammer
#rs
=begin
Write A function that takes an amount of money, rounds it to the nearest 
penny and then tells you the minimum number of coins needed to equal that 
amount of money. For Example: "4.17" would print out:
Quarters: 16
Dimes: 1
Nickels: 1
Pennies: 2
=end

m = ARGV[0].to_f * 100
q=m.to_i/25; d=(m.to_i%25)/10; n=(m.to_i%10)/5; p=m.to_i%5

puts "Quarters: #{q}" if q>0
puts "Dimes: #{d}" if d>0
puts "Nickles: #{n}" if n>0
puts "Pennies: #{p}" if p>0