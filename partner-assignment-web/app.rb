require "bundler"
Bundler.require

class Application < Sinatra::Base

	get '/' do
		erb :index
	end

	post '/do-assignments' do
		tmp_file = ""
		10.times do |t|
			tmp_file += [rand(65..90),rand(97..122)].sample.chr
		end

		list = params[:list].split(/,|\n+/).join("\n")

		tmp_file = "/tmp/" + tmp_file
		File.open(tmp_file, "w") do |f|
			f.write(list)
		end

		command = "../partner-assignment/make-partner-sets.out #{tmp_file} #{params[:group_size]} --as-json"
		@results = JSON.parse(`#{command}`)

		erb :index
	end
end
