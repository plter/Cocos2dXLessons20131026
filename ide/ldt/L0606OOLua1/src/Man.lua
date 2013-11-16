require("People")

function Man_new(name)
	
	local self = People_new(name)
	
	self.sayHi = function (this)
		print("Man say : Hi "..this.name)
	end
	
	self.sayHello = function (this)
		print("Man say : Hello "..this.name)
	end
	
	return self
end