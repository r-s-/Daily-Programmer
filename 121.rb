#DailyProgrammer Challenge
#number 121

#Using the first link on wiki pages see if we can go from one page to another.

require 'open-uri'
require 'nokogiri'

#first page
page1 = "Cow"

#second page
page2 = "History"

until page1 == page2 do
  #open page
  doc = Nokogiri::HTML(open("http://en.wikipedia.org/wiki/" + page1))

  %w[.//table .//span .//sup .//i].map {|n| doc.xpath(n).map(&:remove) }

  #find href in first p
  fp = doc.css("p").first.search('a').map{ |a| a['href']}

  #make page1 = the end of the url. ex. /wiki/link = link
  page1 = fp.first[6,fp.first.length]
  puts page1
end

