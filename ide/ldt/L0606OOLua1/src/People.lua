function People_new(name)
	
	local self = {}
	self.name = name
	
	self.sayHi = function ()
		print("Hello "..self.name)
	end
	
	return self
end