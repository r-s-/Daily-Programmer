#Daily Programmer Problem 136
#I have already solved this in C++, now solving it in ruby

n = 0, m = 0, line_count = 0, ave = 0.0, total_sum = 0.0
name = [], average = []
data = File.new("data.txt", "r")
data.each_line {|line|  
  if (line_count == 0)
    f = line.split(' ')
    n = f[0].to_i
    m = f[1].to_i
  else
    l = line.split(' ')
    name[line_count] = l[0]
    sum = 0.0
    1.upto(n) {|i| sum = sum + l[i].to_i}
    ave = (sum/m)
    total_sum += ave
    average[line_count] = ave
  end
  line_count += 1
}
puts "#{total_sum/n}"
1.upto(n) {|i| puts "#{ name[i]} " "#{average[i]}"} 
