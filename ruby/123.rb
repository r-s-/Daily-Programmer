#DailyProgrammer Challenge
#number 128

def sumdigits(num)
  sum = num.to_s.split("").map(&:to_i).inject(:+)
  sum > 9 ? sumdigits(sum) : puts(sum) 
end


puts "Enter Number: "
num = gets.chomp
sumdigits(num)