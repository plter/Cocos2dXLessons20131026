require("People")

Man = {}
function Man.new(name)
	
	local self = People.new(name)
	copy(self,Man)
	return self
end

function Man.sayHi(self)
	print("Man say : Hi "..self.name)
end