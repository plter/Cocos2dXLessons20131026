require("oo")

People = {}

function People.new(name)
	
	local self = clone(People)
	self.name = name
	return self
end

function People.sayHi(self)
	print("People say : Hi "..self.name)
end