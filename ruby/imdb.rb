#filename to imdb program
#go through a directory and get all the file names. If there is a match for them on IMDB then 
#write the movie information into a next file
#r-s

require 'rubygems'
require 'imdb'

Dir.foreach('/Users/rs/codemonkey/movies') do |item|
  next if item == '.' or item == '..'
  name = item.chomp(File.extname(item))
  
  s = IMDB::Search.new.movie(name)
  movie = IMDB::Movie.new(s[0].imdb_id)
  
  output = File.open("#{movie.title}.txt","w+")<<"#{movie.title}\n"
  
  movie.cast.each do |cast|  
    if !cast.nil? 
      output << "#{cast.name} as #{cast.char}\n"
    end
  end  
end 
